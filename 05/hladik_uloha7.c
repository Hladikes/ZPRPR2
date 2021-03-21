/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 5.7
*/

#include <stdio.h>
#include <stdlib.h>
#define prompt(n, k, ...) printf("%s", n);scanf(k, __VA_ARGS__);fseek(stdin,0,SEEK_SET);
#define validatedPrompt(msg, condition, errmsg, format, ...) {  do{prompt(msg,format,__VA_ARGS__);if(!(condition)){printf("%s", errmsg);}}while(!(condition));  }
#define bool char
#define true 1
#define false 0

int compare(const void *a, const void *b) {
  return *((double*) a) > *((double*) b) ? 1 : -1;
}

int main() {
  FILE *neusporiadane = fopen("./neusporiadane.txt", "r");
  FILE *usporiadane = fopen("./usporiadane.txt", "w+");

  if (!(usporiadane && neusporiadane)) {
    printf("[CHYBA] Nebolo mozne otvorit subory 'neusporiadane.txt' a 'usporiadane.txt'");
    return 1;
  }

  int n = 0;
  char c;
  while ((c = fgetc(neusporiadane)) != EOF) {
    n += (c == '\n');
  }

  if (n < 1) {
    printf("[CHYBA] Subor ma nespravny format");
    return 1;
  }

  double arr[n];
  fseek(neusporiadane, 0, SEEK_SET);

  for (int i = 0; i < n; i++) {
    fscanf(neusporiadane, "%lf", arr + i);
  }

  // Nevedel som ako efektivne spravit dalsie pole a donho vlozit 
  // usporiadane hodnoty z prveho pola. Tak som rovno usporiadal
  // povodne pole a to som zapisal.
  qsort(arr, n, sizeof(double), compare);

  for (int i = 0; i < n; i++) {
    fprintf(usporiadane, "%.2lf\n", *(arr + i));
  }

  return 0;
}