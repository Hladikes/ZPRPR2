/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 3.1
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
  char s = getchar();
  
  FILE *znak = fopen("./znak.txt", "r");
  FILE *novy = fopen("./novy.txt", "w");

  if (!(znak and novy)) {
    printf("Nebolo mozne otvorit subor znak.txt a novy.txt");
    return 0;
  }

  bool save = (s == 's');
  char c;

  while ((c = fgetc(znak)) != EOF) {
    if (save) {
      fputc(c, novy);
    } else {
      putchar(c);
    }
  }

  fclose(znak);
  fclose(novy);

  return 0;
}