/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 3.7
*/

#include <stdio.h>
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
#define or ||
#define and &&

int digitsum(int n) {
  return n != 0 ? (n % 10) + digitsum(n / 10) : 0;
}

int main() {
  int n;
  prompt("Zadaj cele cislo: ", "%d", &n);
  printf("Sucet neparnych cisel mensich ako N je %d", digitsum(n));
  return 0;
}