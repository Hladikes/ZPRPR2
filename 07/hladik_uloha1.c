/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 7.1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define prompt(n, k, ...) printf("%s", n);scanf(k, __VA_ARGS__);fseek(stdin,0,SEEK_SET);
#define validatedPrompt(msg, condition, errmsg, format, ...) {  do{prompt(msg,format,__VA_ARGS__);if(!(condition)){printf("%s", errmsg);}}while(!(condition));  }
#define bool char
#define true 1
#define false 0

#define STR_LENGTH 100

int main() {
  puts("Press # to exit\n");
  char buffer[STR_LENGTH];
  while (true) {
    scanf("%s", buffer);
    for (int i = 0; i < strlen(buffer); i++) {
      printf("%c", buffer[i] == '*' ? '^' : ' ');
    }
    printf("\n");
    if (buffer[0] == '#') break;
  }
  
  return 0;
}