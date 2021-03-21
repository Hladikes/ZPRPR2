/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 3.6
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

int oddsum(int n) {
  if (n == 1) return 1;
  if (n % 2 != 0) {
    return n + oddsum(n - 2);
  } else {
    return oddsum(n - 1);
  }
}

int main() {
  int n;
  prompt("Zadaj cele cislo: ", "%d", &n);
  printf("Sucet neparnych cisel mensich ako N je %d", oddsum(n));
  return 0;
}

// 1 2 3 4 5 6 7 8 9
//   2   4   6   8