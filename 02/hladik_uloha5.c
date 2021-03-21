/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 2.5
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
  f = fopen("./nasobky.txt", "w");

  double d;
  prompt("Zadaj jedno realne cislo: ", "%lf", &d);

  for (int i = 1; i <= 10; i++) {
    fprintf(f, "%d * %.2lf = %.2lf\n", i, d, i * d);
  }

  fclose(f);

  return 0;
}