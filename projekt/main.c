/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Semestrálny projekt
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Makra na vseobecne pouzitie
#define prompt(n, k, ...) \
  printf("%s", n);        \
  scanf(k, __VA_ARGS__);  \
  fseek(stdin, 0, SEEK_SET);
#define validatedPrompt(msg, condition, errmsg, format, ...) \
  {                                                          \
    do {                                                     \
      prompt(msg, format, __VA_ARGS__);                      \
      if (!(condition)) {                                    \
        printf("%s", errmsg);                                \
      }                                                      \
    } while (!(condition));                                  \
  }
#define bool char
#define true 1
#define false 0

// Makra specificke pre tento projekt

#define ERR_ALLOC 2
#define ERR_FILE 3
#define STR_MAX_LENGTH 50
#define PATH_GOODS "./tovar.txt"
#define PATH_VENDORS "./dodavatelia.txt"
#define _divider()                                                                                      \
  printf("----------------------------------------------------------------------------------------\n"); \
  printf("----------------------------------------------------------------------------------------\n");

// Funkcia na ziskanie poctu znakov noveho riadku zo suboru
int _getNewlineCount(FILE *f) {
  // Posunieme kurzor na zaciatok suboru
  fseek(f, 0, SEEK_SET);
  int count = 0;
  char c;

  // Pripocitavame 1 iba ak je iterovany znak '\n' a
  // zaroven nieje EOF
  while ((c = fgetc(f)) != EOF) {
    count += (c == '\n');
  }

  fseek(f, 0, SEEK_SET);
  return count;
}

// Funkcia na zmazanie znaku noveho riadku z retazca
// v pripade ze sa na konci znak noveho riadku nachadza
void _removeTrailingNewline(char *str) {
  // puts("    Before strlen");
  // printf("    '%s'", str);
  int len = strlen(str);
  // puts("    After strlen");
  if (str[len - 1] == '\n') {
    str[len - 1] = '\0';
  }
}

// Wrapper funkcia ktora sa chova identicky ako funkcia
// fopen, akurat ukonci program s chybovou hlaskou
// v pripade ze sa nepodarilo otvorit subor
FILE *_openFile(char *filename, char *mode) {
  FILE *f = fopen(filename, mode);
  if (!f) {
    puts("Subor sa nepodarilo otvorit");
    exit(ERR_FILE);
  }
  return f;
}

// Funkcia ktora ziska pocet poloziek z daneho suboru. Ako argumenty
// pobera otvoreny subor, pointer kam ma ulozit pocet poloziek
// a pocet udajov ktore obsahuje kazda polozka.
void _getQuantity(FILE *f, int *quantity, int entriesCount) {
  if (!f) {
    // printf("[CHYBA] Nastala chyba pocas citania suboru\n");
    exit(ERR_FILE);
  } else {
    *quantity = (_getNewlineCount(f) + 1) / entriesCount;
  }
}

// Prototypy funkcii pre jednotlive podprogramy
void v(FILE **goods, int *goodsQuantity, FILE **vendors, int *vendorsQuantity);
void v_goods(FILE **goods, int *goodsQuantity);
void v_vendors(FILE **vendors, int *vendorsQuantity);
void o(FILE *goods, int goodsQuantity, FILE *vendors, int vendorsQuantity);
bool o_vendorExists(FILE *, int, int);

void n(
    FILE **goods,
    int goodsQuantity,
    FILE **vendors,
    int vendorsQuantity,
    char ***productsNames,
    int **productsQuantities,
    int **productsVendorIds,
    double **productsPrices,
    double **productsWeights,
    int **vendorIds,
    char ***vendorsNames,
    char ***vendorsAddresses);

void n_goods(
    FILE **goods,
    int goodsQuantity,
    char ***productsNames,
    int **productsQuantities,
    int **productsVendorIds,
    double **productsPrices,
    double **productsWeights);

void n_vendors(
    FILE **vendors,
    int vendorsQuantity,
    int **vendorIds,
    char ***vendorsNames,
    char ***vendorsAddresses);

void s(
    int goodsQuantity,
    int vendorsQuantity,
    char **productsNames,
    int *productsVendorIds,
    int *productsQuantities,
    int *vendorsIds);

void h(int goodsQuantity, int *productsQuantities);

void p(
    int goodsQuantity,
    char **productsNames,
    int *productsQuantities,
    int *productsVendorIds,
    double *productsPrices,
    double *productsWeights);

void z(int goodsQuantity, char **productsNames, double *productsWeights);

int main() {
  FILE *goods = NULL, *vendors = NULL;
  int goodsQuantity = -1, vendorsQuantity = -1;

  // Products arrays
  char **productsNames = NULL;
  int *productsQuantities = NULL, *productsVendorIds = NULL;
  double *productsPrices = NULL, *productsWeights = NULL;

  // Vendors arrays
  int *vendorsIds = NULL;
  char **vendorsNames = NULL, **vendorsAddreses = NULL;

  // Oznacuje stav, ci uz boli udaje zo suborov
  // nacitane do dynamickych poli alebo nie
  bool arrayLoaded = false;
  bool loop = true;
  char c;
  while (loop) {
    prompt("> ", "%c", &c);

    if (c == 'v') v(&goods, &goodsQuantity, &vendors, &vendorsQuantity);

    if (c == 'o') {
      if (!(goods && vendors)) {
        continue;
      }
      // Podfunkcia o sa vola len vtedy pokial udaje zo suborov
      // este neboli nacitane do pola a chceme citat zo suboru
      o(goods, goodsQuantity, vendors, vendorsQuantity);
    }

    if (c == 'n') {
      if (!(goods && vendors)) {
        continue;
      }

      if (arrayLoaded) {
        for (int i = 0; i < goodsQuantity; i++) {
          free(productsNames[i]);
        }
        free(productsNames);
        free(productsQuantities);
        free(productsVendorIds);
        free(productsPrices);
        free(productsWeights);

        free(vendorsIds);
        for (int i = 0; i < vendorsQuantity; i++) {
          free(vendorsNames[i]);
          free(vendorsAddreses[i]);
        }
        free(vendorsNames);
        free(vendorsAddreses);
      }

      n(
          &goods,
          goodsQuantity,
          &vendors,
          vendorsQuantity,
          &productsNames,
          &productsQuantities,
          &productsVendorIds,
          &productsPrices,
          &productsWeights,
          &vendorsIds,
          &vendorsNames,
          &vendorsAddreses);

      arrayLoaded = true;
    }

    if (c == 's') {
      if (!arrayLoaded) {
        puts("Polia nie su vytvorene");
        continue;
      }

      s(
          goodsQuantity,
          vendorsQuantity,
          productsNames,
          productsVendorIds,
          productsQuantities,
          vendorsIds);
    }

    if (c == 'h') {
      if (!arrayLoaded) {
        puts("Polia nie su vytvorene");
        continue;
      }

      h(goodsQuantity, productsQuantities);
    }

    if (c == 'p') {
      if (!arrayLoaded) {
        puts("Polia nie su vytvorene");
        continue;
      }

      p(
          goodsQuantity,
          productsNames,
          productsQuantities,
          productsVendorIds,
          productsPrices,
          productsWeights);
    }

    if (c == 'z') {
      if (!arrayLoaded) {
        puts("Polia nie su vytvorene");
        continue;
      }

      z(goodsQuantity, productsNames, productsWeights);
    }

    if (c == 'k') {
      loop = false;
    }
  }

  for (int i = 0; i < goodsQuantity; i++) {
    free(productsNames[i]);
  }
  free(productsNames);
  free(productsQuantities);
  free(productsVendorIds);
  free(productsPrices);
  free(productsWeights);

  free(vendorsIds);
  for (int i = 0; i < vendorsQuantity; i++) {
    free(vendorsNames[i]);
    free(vendorsAddreses[i]);
  }
  free(vendorsNames);
  free(vendorsAddreses);

  fclose(goods);
  fclose(vendors);
  return 0;
}

void v(FILE **goods, int *goodsQuantity, FILE **vendors, int *vendorsQuantity) {
  v_goods(goods, goodsQuantity);
  _divider();
  v_vendors(vendors, vendorsQuantity);
}

void v_goods(FILE **goods, int *goodsQuantity) {
  // Otvori subor v pripade ze este nebol otvoreny
  if (!(*goods)) *goods = _openFile(PATH_GOODS, "r");

  _getQuantity(*goods, goodsQuantity, 6);

  char *productName = calloc(STR_MAX_LENGTH, sizeof(char));
  int productQuantity = 0;
  double productPrice = 0;
  double productWeight = 0;
  int productVendorId = 0;

  for (int i = 0; i < *goodsQuantity; i++) {
    // Kedze nazov produktu moze obsahovat medzery tak je tu
    // pouzita funkcia fgets ktora neignoruje tzv. whitespace
    // characters
    fgets(productName, STR_MAX_LENGTH, *goods);

    // Kedze funkcia fgets neignoruje whitespace character ako '\n'
    // tak ho musime zmazat manualne
    _removeTrailingNewline(productName);
    fscanf(
        *goods,
        "%d %lf %lf %d ",
        &productQuantity,
        &productPrice,
        &productWeight,
        &productVendorId);

    printf("Nazov tovaru: %s\n", productName);
    printf("Pocet kusov na sklade: %d\n", productQuantity);
    printf("Cena: %.2lf\n", productPrice);
    printf("Hmotnost: %.4lf\n", productWeight);
    printf("ID dodavatela: %d\n\n", productVendorId);
  }

  fseek(*goods, 0, SEEK_SET);
  free(productName);
}

void v_vendors(FILE **vendors, int *vendorsQuantity) {
  // Otvori subor v pripade ze este nebol otvoreny
  if (!(*vendors)) *vendors = _openFile(PATH_VENDORS, "rw+");

  _getQuantity(*vendors, vendorsQuantity, 4);

  int vendorId = 0;
  char *vendorName = calloc(STR_MAX_LENGTH, sizeof(char));
  char *vendorAddress = calloc(STR_MAX_LENGTH, sizeof(char));

  for (int i = 0; i < *vendorsQuantity; i++) {
    fscanf(
        *vendors,
        "%d %s ",
        &vendorId,
        vendorName);

    fgets(vendorAddress, STR_MAX_LENGTH, *vendors);
    _removeTrailingNewline(vendorAddress);

    printf("ID dodavatela: %d\n", vendorId);
    printf("Meno dodavatela: %s\n", vendorName);
    printf("Adresa dodavatela: %s\n\n", vendorAddress);
  }

  fseek(*vendors, 0, SEEK_SET);
  free(vendorName);
  free(vendorAddress);
}

void o(FILE *goods, int goodsQuantity, FILE *vendors, int vendorsQuantity) {
  int vendorIdToFind = 0;
  prompt("", "%d", &vendorIdToFind);

  // Kontrola ci vobec dodavatel zo vstupnym ID vobec existuje v subore
  if (!o_vendorExists(vendors, vendorsQuantity, vendorIdToFind)) {
    // printf("[CHYBA] Dodavatel s id %d neexistuje\n", vendorIdToFind);
    return;
  }

  char *productName = calloc(STR_MAX_LENGTH, sizeof(char));
  int productQuantity = 0;
  double productPrice = 0;
  double productWeight = 0;
  int vendorId = 0;

  char *expensiveProductName = calloc(STR_MAX_LENGTH, sizeof(char));
  double highestPrice = 0;

  for (int i = 0; i < goodsQuantity; i++) {
    fgets(productName, STR_MAX_LENGTH, goods);
    _removeTrailingNewline(productName);
    fscanf(
        goods,
        "%d %lf %lf %d ",
        &productQuantity,
        &productPrice,
        &productWeight,
        &vendorId);

    // Hlada najdrahsi produkt od vstupneho dodavatela
    if (vendorId == vendorIdToFind && productPrice > highestPrice) {
      highestPrice = productPrice;
      strcpy(expensiveProductName, productName);
    }
  }

  // 0 je v pripade ze dodavatel existovat moze ale ziadny jeho tovar
  // sa nenachadza v suboroch
  if (strlen(expensiveProductName) > 0) {
    printf("Najdrahsi tovar je %s\n", expensiveProductName);
  }

  fseek(goods, 0, SEEK_SET);
  free(productName);
}

bool o_vendorExists(FILE *vendors, int vendorsQuantity, int vendorIdToFind) {
  int vendorId = 0;
  char *vendorName = calloc(STR_MAX_LENGTH, sizeof(char));
  char *vendorAddress = calloc(STR_MAX_LENGTH, sizeof(char));

  bool found = false;

  for (int i = 0; i < vendorsQuantity; i++) {
    fscanf(
        vendors,
        "%d %s ",
        &vendorId,
        vendorName);

    fgets(vendorAddress, STR_MAX_LENGTH, vendors);
    _removeTrailingNewline(vendorAddress);

    if (vendorId == vendorIdToFind) {
      found = true;
      break;
    }
  }

  fseek(vendors, 0, SEEK_SET);
  free(vendorName);
  free(vendorAddress);

  return found;
}

void n(
    FILE **goods,
    int goodsQuantity,
    FILE **vendors,
    int vendorsQuantity,
    char ***productsNames,
    int **productsQuantities,
    int **productsVendorIds,
    double **productsPrices,
    double **productsWeights,
    int **vendorIds,
    char ***vendorsNames,
    char ***vendorsAddresses) {
  n_goods(goods, goodsQuantity, productsNames, productsQuantities, productsVendorIds, productsPrices, productsWeights);
  n_vendors(vendors, vendorsQuantity, vendorIds, vendorsNames, vendorsAddresses);
}

void n_goods(
    FILE **goods,
    int goodsQuantity,
    char ***productsNames,
    int **productsQuantities,
    int **productsVendorIds,
    double **productsPrices,
    double **productsWeights) {
  *productsNames = (char **)calloc(goodsQuantity, sizeof(char *));
  for (int i = 0; i < goodsQuantity; i++) {
    (*productsNames)[i] = (char *)calloc(STR_MAX_LENGTH, sizeof(char));
  }
  *productsQuantities = (int *)calloc(goodsQuantity, sizeof(int));
  *productsPrices = (double *)calloc(goodsQuantity, sizeof(double));
  *productsWeights = (double *)calloc(goodsQuantity, sizeof(double));
  *productsVendorIds = (int *)calloc(goodsQuantity, sizeof(int));

  if (!(productsNames && productsQuantities && productsVendorIds && productsPrices && productsWeights)) {
    exit(ERR_ALLOC);
  }

  for (int i = 0; i < goodsQuantity; i++) {
    fgets((*productsNames)[i], STR_MAX_LENGTH, *goods);
    _removeTrailingNewline((*productsNames)[i]);

    fscanf(
        *goods,
        "%d %lf %lf %d ",
        &(*productsQuantities)[i],
        &(*productsPrices)[i],
        &(*productsWeights)[i],
        &(*productsVendorIds)[i]);
  }

  fseek(*goods, 0, SEEK_SET);
}

void n_vendors(
    FILE **vendors,
    int vendorsQuantity,
    int **vendorsIds,
    char ***vendorsNames,
    char ***vendorsAddresses) {
  *vendorsIds = (int *)calloc(vendorsQuantity, sizeof(int));
  *vendorsNames = (char **)calloc(vendorsQuantity, sizeof(char *));
  for (int i = 0; i < vendorsQuantity; i++) {
    (*vendorsNames)[i] = (char *)calloc(STR_MAX_LENGTH, sizeof(char));
  }
  *vendorsAddresses = (char **)calloc(vendorsQuantity, sizeof(char *));
  for (int i = 0; i < vendorsQuantity; i++) {
    (*vendorsAddresses)[i] = (char *)calloc(STR_MAX_LENGTH, sizeof(char));
  }

  if (!(vendorsIds && vendorsNames && vendorsAddresses)) {
    exit(ERR_ALLOC);
  }

  for (int i = 0; i < vendorsQuantity; i++) {
    fscanf(
        *vendors,
        "%d %s ",
        &(*vendorsIds)[i],
        (*vendorsNames)[i]);

    fgets((*vendorsAddresses)[i], STR_MAX_LENGTH, *vendors);
    _removeTrailingNewline((*vendorsAddresses)[i]);
  }

  fseek(*vendors, 0, SEEK_SET);
}

void s(
    int goodsQuantity,
    int vendorsQuantity,
    char **productsNames,
    int *productsVendorIds,
    int *productsQuantities,
    int *vendorsIds) {
  int vendorIdToFind = 0;
  bool found = false;
  prompt("", "%d", &vendorIdToFind);
  for (int i = 0; i < vendorsQuantity; i++) {
    if (vendorsIds[i] == vendorIdToFind) {
      found = true;
      break;
    }
  }

  if (!found) return;

  for (int i = 0; i < goodsQuantity; i++) {
    if (productsVendorIds[i] == vendorIdToFind) {
      printf("%s (%d na sklade)\n", productsNames[i], productsQuantities[i]);
    }
  }
}

void h(int goodsQuantity, int *productsQuantities) {
  int quantities[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  for (int i = 0; i < goodsQuantity; i++) {
    int index = productsQuantities[i] / 10;
    quantities[index]++;
  }
  for (int i = 0; i < 10; i++) {
    printf("<%d,%d>: %d\n", i * 10, (i * 10) + 9, quantities[i]);
  }
}

void p(
    int goodsQuantity,
    char **productsNames,
    int *productsQuantities,
    int *productsVendorIds,
    double *productsPrices,
    double *productsWeights) {
  char *productName = (char *)calloc(STR_MAX_LENGTH, sizeof(char));
  fgets(productName, STR_MAX_LENGTH, stdin);
  _removeTrailingNewline(productName);

  int newProductQuantity = 0;
  prompt("", "%d", &newProductQuantity);

  bool success = false;

  for (int i = 0; i < goodsQuantity; i++) {
    if (strcmp(productsNames[i], productName) == 0) {
      productsQuantities[i] = newProductQuantity;
      success = true;
    }
  }

  if (!success) return;

  FILE *goods = fopen(PATH_GOODS, "w+");
  if (!goods) {
    puts("Neotvoreny subor");
    exit(ERR_FILE);
  }

  fseek(goods, 0, SEEK_SET);
  for (int i = 0; i < goodsQuantity; i++) {
    fprintf(
        goods,
        "%s\n%d\n%g\n%g\n%d\n\n",
        productsNames[i],
        productsQuantities[i],
        productsPrices[i],
        productsWeights[i],
        productsVendorIds[i]);
  }
  fclose(goods);
}

void z(int goodsQuantity, char **productsNames, double *productsWeights) {
  double min = 0, max = 0;
  prompt("", "%lf", &min);
  prompt("", "%lf", &max);

  if (min > max) {
    puts("Prve cislo musi byt mensie ako druhe cislo");
    return;
  }

  for (int i = 0; i < goodsQuantity; i++) {
    if (productsWeights[i] > min && productsWeights[i] < max) {
      printf("%s\n", productsNames[i]);
    }
  }
}