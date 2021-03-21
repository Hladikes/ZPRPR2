/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 5.1
*/

#include <stdio.h>
#include <stdlib.h>
#define prompt(n, k, ...) printf("%s", n);scanf(k, __VA_ARGS__);fseek(stdin,0,SEEK_SET);
#define validatedPrompt(msg, condition, errmsg, format, ...) {  do{prompt(msg,format,__VA_ARGS__);if(!(condition)){printf("%s", errmsg);}}while(!(condition));  }
#define bool char
#define true 1
#define false 0

int main() {
  int *arr = calloc(2, sizeof(int));
  int c;
  prompt("Zadaj tri cele cisla oddelene medzerou: ", "%d %d %d", &arr[0], &arr[1], &c);
  printf("%d + %d + %d = %d", arr[0], arr[1], c, arr[0] + arr[1] + c);
  free(arr);
  return 0;
}