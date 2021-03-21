/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 3.2
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
  FILE *vstup = fopen("./vstup.txt", "r");
  FILE *cisla = fopen("./cisla.txt", "w");

  char buffer[1024];

  while (fgets(buffer, 1024, vstup) != NULL) {
    int numOfSmallChars = 0;
    for (int n = 0; n < 1024; n++) {
      if (buffer[n] == '\n') break;

      numOfSmallChars += (buffer[n] >= 'a' && buffer[n] <= 'z');
    }
    fprintf(cisla, "%s%d\n", buffer, numOfSmallChars);
  }

  fclose(vstup);
  fclose(cisla);

  return 0;
}