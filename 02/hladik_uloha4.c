/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 2.4
*/

#include <stdio.h>
#define prompt(n, k, ...) printf("%s", n);scanf(k, __VA_ARGS__);fseek(stdin,0,SEEK_SET);
#define validatedPrompt(msg, condition, errmsg, format, ...) {  do{prompt(msg,format,__VA_ARGS__);if(!(condition)){printf("%s", errmsg);}}while(!(condition));  }
#define bool char
#define true 1
#define false 0
#define or ||
#define and &&

int reverzne_cislo(int x) {
  int y = 0;
  while (x > 0) {
    y = 10 * y + (x % 10);
    x /= 10;
  }
  return y;
}

int main() {
  int n;
  while (scanf("%d", &n)) {
    int rn = reverzne_cislo(n);
    if (rn == n) {
      printf("%d Je palindrom", rn);
    } else {
      printf("%d Nieje palindrom", rn);
    }
    printf("\n");
  }
  return 0;
}