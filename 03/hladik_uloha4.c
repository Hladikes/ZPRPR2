/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 3.4
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

int main() {
  int n;
  prompt("Zadaj neparne cislo <1,15>: ", "%d", &n);
  
  if (n % 2 == 0 or n < 1 or n > 15) {
    printf("Zly vstup");
    return 1;
  }

  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      printf("%c", (
        x == n / 2 or 
        y == n / 2 or 
        x == y or 
        x == n - y - 1
      ) ? '*' : '-');
    }
    printf("\n");
  }

  return 0;
}