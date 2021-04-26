/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 9.1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define prompt(n, k, ...) printf("%s", n);scanf(k, __VA_ARGS__);fseek(stdin,0,SEEK_SET);
#define validatedPrompt(msg, condition, errmsg, format, ...) {  do{prompt(msg,format,__VA_ARGS__);if(!(condition)){printf("%s", errmsg);}}while(!(condition));  }
#define bool char
#define true 1
#define false 0

// MY CUSTOM ARRAY MANAGEMENT MACROS

#define array_define(name, type)                                         \
  typedef struct {                                                       \
    int length;                                                          \
    int _unitsize;                                                       \
    int _allocated;                                                      \
    type *items;                                                         \
  } name;                                                                \
  typedef type name##___type;                                            \
  name name##___default() {                                              \
    name arr = {                                                         \
      length : 0,                                                        \
      _unitsize : sizeof(name##___type),                                 \
      _allocated : 10                                                    \
    };                                                                   \
    arr.items = (name##___type *)malloc(arr._unitsize * arr._allocated); \
    return arr;                                                          \
  }

#define array(name) name##___default()

#define array_foreach(name, arr, index, iterator, code) \
  for (int ___i = 0; ___i < arr.length; ___i++) {       \
    name##___type iterator = arr.items[___i];           \
    int index = ___i;                                   \
    code;                                               \
  }

#define array_push(name, arr, item)                                                  \
  if (arr._allocated == arr.length) {                                                \
    arr._allocated *= 2;                                                             \
    arr.items = (name##___type *)realloc(arr.items, arr._unitsize * arr._allocated); \
  }                                                                                  \
  arr.items[(arr.length += 1) - 1] = item;

#define array_free(arr) free(arr.items)

// UTIL

char *_strin(int size) {
  char *str = (char*) calloc(size, sizeof(char));
  fgets(str, size, stdin);
  fseek(stdin, 0, SEEK_SET);
  int len = strlen(str);
  if (str[len - 1] == '\n') {
    str[len - 1] = '\0';
  }
  return str;
}

char _chin() {
  char c = getchar();
  fseek(stdin, 0, SEEK_SET);
  return c;
}

int _intin() {
  int n = 0;
  scanf("%d", &n);
  fseek(stdin, 0, SEEK_SET);
  return n;
}

double _dblin() {
  double d = 0;
  scanf("%lf", &d);
  fseek(stdin, 0, SEEK_SET);
  return d;
}

// END OF UTIL

typedef struct Tovar {
  char *name;
  char *vendor;
  int quantity;
  double price;
} Tovar;

array_define(Tovary, Tovar)

void addTovar(Tovary t) {
  Tovar newTovar;
  printf("Nazov tovaru: ");
  newTovar.name = _strin(100);
  printf("Vyrobca tovaru: ");
  newTovar.vendor = _strin(100);
  printf("Cena tovaru: ");
  newTovar.price = _dblin();
  printf("Pocet kusov tovaru: ");
  newTovar.quantity = _intin();
  array_push(Tovary, t, newTovar);
}

void printTovar(Tovary t) {
  puts("Pice funguj");
  array_foreach(Tovary, t, index, tovar, {
    puts(tovar.name);
  });
}

int main() {
  Tovary tovary = array(Tovary);

  bool loop = true;
  while (loop) {
    switch (_chin()) {
      case '+': addTovar(tovary); break;
      case 'p': printTovar(tovary); break;
    }
  }

  return 0;
}