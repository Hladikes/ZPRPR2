/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 4.3
*/

#include <stdio.h>
#include <stdlib.h>
#define prompt(n, k, ...) printf("%s", n);scanf(k, __VA_ARGS__);fseek(stdin,0,SEEK_SET);
#define validatedPrompt(msg, condition, errmsg, format, ...) {  do{prompt(msg,format,__VA_ARGS__);if(!(condition)){printf("%s", errmsg);}}while(!(condition));  }
#define bool char
#define true 1
#define false 0

void zakladny_tvar(int *c, int *m) {
  for (int i = 2; i < *m; i++) {
    while (*c % i == 0 && *m % i == 0) {
      *c /= i;
      *m /= i;
    }
  }
}

int main() {
  int c = 60, m = 120;
  zakladny_tvar(&c, &m);
  printf("%d/%d", c, m);
  return 0;
}