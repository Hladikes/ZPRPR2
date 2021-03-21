/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 2.6
*/

#include <stdio.h>
#define prompt(n, k, ...) printf("%s", n);scanf(k, __VA_ARGS__);fseek(stdin,0,SEEK_SET);
#define validatedPrompt(msg, condition, errmsg, format, ...) {  do{prompt(msg,format,__VA_ARGS__);if(!(condition)){printf("%s", errmsg);}}while(!(condition));  }
#define bool char
#define true 1
#define false 0
#define or ||
#define and &&

int main() {
  FILE *f;
  f = fopen("./text.txt", "r");

  if (f == NULL) {
    printf("Nebolo mozne otvorit subor");
    return -1;
  }

  int spaceCount = 0;
  char c;
  while ((c = fgetc(f)) != EOF) {
    if (c == 'x' || c == 'X' || c == 'y' || c == 'Y')  {
      printf("Precital som %c\n", c);
    } else if (c == '#' || c == '$' || c == '&') {
      printf("Precital som riadaci znak\n");
    } else if (c == ' ') {
      spaceCount++;
    } else if (c == '*') {
      printf("Koniec");
      break;
    }
  }

  fclose(f);
  printf("Pocet precitanych medzer: %d", spaceCount);

  return 0;
}