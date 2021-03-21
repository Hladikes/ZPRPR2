/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 2.2
*/

#include <stdio.h>
#define prompt(n, k, ...) printf("%s", n);scanf(k, __VA_ARGS__);fseek(stdin,0,SEEK_SET);
#define validatedPrompt(msg, condition, errmsg, format, ...) {  do{prompt(msg,format,__VA_ARGS__);if(!(condition)){printf("%s", errmsg);}}while(!(condition));  }
#define bool char
#define true 1
#define false 0
#define or ||
#define and &&

void mocnina(double d, int n) {
  double res = 1;
  for (int i = 0; i < n; i++) {
    res *= d;
  }
  printf("\n%.2lf^%d = %.2lf", d, n, res);
}

int main() {
  double a;
  int b = 1;
  prompt("Zadaj realne a cele cislo oddelene medzerou: ", "%lf %d", &a, &b);
  printf("%lf %d", a, b);

  for (int i = 0; i < b; i++) {
    mocnina(a, i + 1);
  }
  return 0;
}