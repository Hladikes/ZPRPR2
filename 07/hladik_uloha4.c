/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 7.4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define prompt(n, k, ...) printf("%s", n);scanf(k, __VA_ARGS__);fseek(stdin,0,SEEK_SET);
#define validatedPrompt(msg, condition, errmsg, format, ...) {  do{prompt(msg,format,__VA_ARGS__);if(!(condition)){printf("%s", errmsg);}}while(!(condition));  }
#define bool char
#define true 1
#define false 0

int odstran_male_pismena(char *str) {
  int strlength = strlen(str);
  int numOfBigChars = 0;
  for (int n = 0; str[n] != '\0'; n++) {
    numOfBigChars += (str[n] >= 'A' && str[n] <= 'Z');
  }
  char bigStr[numOfBigChars + 1];
  int index = 0;
  for (int n = 0; str[n] != '\0'; n++) {
    if (str[n] >= 'A' && str[n] <= 'Z') {
      bigStr[index++] = str[n];
    }
  }
  bigStr[index] = '\0';
  strcpy(str, bigStr);
  return strlength - numOfBigChars;
}

int main() {
  char str[100];
  puts("Pre ukoncenie zadaj *");
  while (true) {
    prompt("Zadaj slovo: ", "%s", str);
    if (str[0] == '*') break;
    
    int d = odstran_male_pismena(str);
    printf("Retazec po uprave: %s\n", str);
    printf("Bolo odstranenych %d znakov\n", d);
  }
  return 0;
}