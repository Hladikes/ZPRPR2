/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 1.5
*/

#include <stdio.h>
#define prompt(n, k, ...) printf(n);scanf(k, __VA_ARGS__);fflush(stdin);
#define validatedPrompt(msg, condition, errmsg, format, ...) {  do{prompt(msg,format,__VA_ARGS__);if(!(condition)){printf(errmsg);}}while(!(condition));  }
#define bool int
#define true 1
#define false 0
#define or ||
#define and &&

int main() {
  int n = 0;
  prompt("Zadaj N: ", "%d", &n);
  
  if (n < 1 or n > 15) {
    printf("Cislo nie je z daneho intervalu");
    return -1;
  }

  for (int y = 0; y < n; y++) {
    printf("%2d:", y + 1);
    for (int x = 0; x < n - y; x++) {
      printf(" %2d", n - x - y);
    }
    printf("\n");
  }

  getchar();
  
  return 0;
}