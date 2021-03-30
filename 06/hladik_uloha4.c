/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 6.4
*/

#include <stdio.h>
#include <stdlib.h>
#define prompt(n, k, ...) printf("%s", n);scanf(k, __VA_ARGS__);fseek(stdin,0,SEEK_SET);
#define validatedPrompt(msg, condition, errmsg, format, ...) {  do{prompt(msg,format,__VA_ARGS__);if(!(condition)){printf("%s", errmsg);}}while(!(condition));  }
#define bool char
#define true 1
#define false 0

#define STR_LENGTH 100

int samohlasky(int i, char str[]) { 
  if (str[i] == '\0') return 0;
  return (
    str[i] == 'a' || 
    str[i] == 'e' || 
    str[i] == 'i' || 
    str[i] == 'o' || 
    str[i] == 'u'
  ) + samohlasky(i + 1, str);
}

int main() {
  char buffer[STR_LENGTH], c;
  printf("Press * for exit\n");
  while (true) {
    fscanf(stdin, "%s%c", buffer, &c);
    printf("%d %c", samohlasky(0, buffer), c == '\n' ? c : ' ');
    if (buffer[0] == '*') break;
  }
  return 0;
}