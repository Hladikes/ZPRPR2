/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 4.4
*/

#include <stdio.h>
#define prompt(n, k, ...) printf("%s", n);scanf(k, __VA_ARGS__);fseek(stdin,0,SEEK_SET);
#define validatedPrompt(msg, condition, errmsg, format, ...) {  do{prompt(msg,format,__VA_ARGS__);if(!(condition)){printf("%s", errmsg);}}while(!(condition));  }
#define bool char
#define true 1
#define false 0
#define or ||
#define and &&

bool nacitaj(double *a, double *b) {
  printf("Zadaj dve cele cisla oddelene medzerou: ");
  int n = scanf("%lf %lf", a, b);

  return n == 2;
}

void vypocitaj(double a, double b, double *obvod, double *obsah) {
  *obvod = (2 * a) + (2 * b);
  *obsah = a * b;
}

int main() {
  double a, b, obvod, obsah;

  if (!nacitaj(&a, &b)) {
    printf("Cisla neboli spravne nacitane");
    return 1;
  }

  vypocitaj(a, b, &obvod, &obsah);

  printf("Obvod: %.3lf\nObsah: %.3lf", obvod, obsah);

  return 0;
}