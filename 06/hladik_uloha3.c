/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 6.3
*/

#include <stdio.h>
#include <stdlib.h>
#define prompt(n, k, ...) printf("%s", n);scanf(k, __VA_ARGS__);fseek(stdin,0,SEEK_SET);
#define validatedPrompt(msg, condition, errmsg, format, ...) {  do{prompt(msg,format,__VA_ARGS__);if(!(condition)){printf("%s", errmsg);}}while(!(condition));  }
#define bool char
#define true 1
#define false 0

#define STR_LENGTH 100

int dlzka(int i, char str[]) { 
  return (str[i] == '\0') ? 0 : 1 + dlzka(i + 1, str);
}

int main() {
  printf("Press * for exit\n");
  char buffer[STR_LENGTH], c;
  while (true) {
    fscanf(stdin, "%s%c", buffer, &c);
    printf("%d %c", dlzka(0, buffer), c == '\n' ? c : ' ');
    if (buffer[0] == '*') break;
  }
  return 0;
}