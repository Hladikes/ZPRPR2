/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 4.2
*/

#include <stdio.h>
#define prompt(n, k, ...) printf("%s", n);scanf(k, __VA_ARGS__);fseek(stdin,0,SEEK_SET);
#define validatedPrompt(msg, condition, errmsg, format, ...) {  do{prompt(msg,format,__VA_ARGS__);if(!(condition)){printf("%s", errmsg);}}while(!(condition));  }
#define bool char
#define true 1
#define false 0
#define or ||
#define and &&

int *maximum(int *a, int *b) {
  return *a > *b ? a : b;
}

int main() {
  int a, b;
  prompt("Zadaj dve cisla oddelene medzerou: ", "%d %d", &a, &b);
  int *max = maximum(&a, &b);
  printf("max: %d", *max);
  return 0;
}