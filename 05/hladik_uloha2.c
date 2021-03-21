/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 5.2
*/

#include <stdio.h>
#include <stdlib.h>
#define prompt(n, k, ...) printf("%s", n);scanf(k, __VA_ARGS__);fseek(stdin,0,SEEK_SET);
#define validatedPrompt(msg, condition, errmsg, format, ...) {  do{prompt(msg,format,__VA_ARGS__);if(!(condition)){printf("%s", errmsg);}}while(!(condition));  }
#define bool char
#define true 1
#define false 0

int parne(int x[], int pocetx, int y[]) {
  int i = 0;
  for (int n = 0; n < pocetx; n++) {
    if (x[n] % 2 == 0) y[i++] = x[n];
  }
  return i;
}

int main() {
  int pocetx = 8;
  int x[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
  int y[pocetx];
  int pocety = parne(x, pocetx, y);

  printf("Pocet y = %d\n", pocety);
  puts("y: ");
  
  for (int n = 0; n < pocety; n++) {
    printf("%d ", y[n]);
  }

  return 0;
}