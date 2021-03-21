/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 3.5
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
  int n, r, s;
  prompt("Zadaj neparne cislo n <1,15>, r & s <1,7> (n r s): ", "%d %d %d", &n, &r, &s);
  
  if (n % 2 == 0 or (n < 1 or n > 15) or (r < 1 or r > 7) or (s < 1 or s > 7)) {
    printf("Zly vstup");
    return 1;
  }

  for (int c = 0; c < s; c++) {
    for (int y = 0; y < n; y++) {
      for (int i = 0; i < r; i++) {
        for (int x = 0; x < n; x++) {
          printf("%c", (
            x == n / 2 || 
            y == n / 2 || 
            x == y || 
            x == n - y - 1
          ) ? '*' : '-');
        }
      }
      printf("\n");
    }
  }

  return 0;
}