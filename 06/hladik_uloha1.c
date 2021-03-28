/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 6.1
*/

#include <stdio.h>
#include <stdlib.h>
#define prompt(n, k, ...) printf("%s", n);scanf(k, __VA_ARGS__);fseek(stdin,0,SEEK_SET);
#define validatedPrompt(msg, condition, errmsg, format, ...) {  do{prompt(msg,format,__VA_ARGS__);if(!(condition)){printf("%s", errmsg);}}while(!(condition));  }
#define bool char
#define true 1
#define false 0

int delitele(int x[], int pocetx, int y[], int k) {
  int i = 0;
  for (int n = 0; n < pocetx; n++) {
    if (k % x[n] == 0) y[i++] = x[n];
  }
  return i;
}

int main() {
  int pocetx = 10;
  int x[] = { 4, 7, 10, 2, 3, 9, 6, 5, 8, 12 };
  int y[pocetx];
  int k = 24;
  int pocety = delitele(x, pocetx, y, k);

  printf("Pocet y = %d\n", pocety);
  printf("%s", "y: ");
  
  for (int n = 0; n < pocety; n++) {
    printf("%d ", y[n]);
  }

  return 0;
}