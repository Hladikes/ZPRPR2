/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 2.3
*/

#include <stdio.h>
#define prompt(n, k, ...) printf("%s", n);scanf(k, __VA_ARGS__);fseek(stdin,0,SEEK_SET);
#define validatedPrompt(msg, condition, errmsg, format, ...) {  do{prompt(msg,format,__VA_ARGS__);if(!(condition)){printf("%s", errmsg);}}while(!(condition));  }
#define bool char
#define true 1
#define false 0
#define or ||
#define and &&

int zisti_prvocislo(int cislo) { // 6
  if (cislo <= 1) {
    return -1;
  }

  for (int i = 2; i < cislo; i++) {
    if (cislo % i == 0) {
      return -1;
    }
  }

  return 1;
}

int main() {
  int a, b;
  prompt("Zadaj dve cele cisla oddelene medzerou: ", "%d %d", &a, &b);
  for (int i = a; i <= b; i++) {
    if (zisti_prvocislo(i) == 1) {
      printf("%d ", i);
    }
  }
  return 0;
}