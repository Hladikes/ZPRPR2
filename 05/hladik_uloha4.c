/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 5.4
*/

#include <stdio.h>
#include <stdlib.h>
#define prompt(n, k, ...) printf("%s", n);scanf(k, __VA_ARGS__);fseek(stdin,0,SEEK_SET);
#define validatedPrompt(msg, condition, errmsg, format, ...) {  do{prompt(msg,format,__VA_ARGS__);if(!(condition)){printf("%s", errmsg);}}while(!(condition));  }
#define bool char
#define true 1
#define false 0

int main() {
  int n;
  prompt("Zadajte jedno cele cislo: ", "%d", &n);
  char *arr = calloc(n, sizeof(char));
  
  prompt("", "%s", arr);

  for (int i = 0; i < n; i++) {
    putchar(*(arr + n - i - 1));
  }

  return 0;
}