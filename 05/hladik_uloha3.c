/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 5.3
*/

#include <stdio.h>
#include <stdlib.h>
#define prompt(n, k, ...) printf("%s", n);scanf(k, __VA_ARGS__);fseek(stdin,0,SEEK_SET);
#define validatedPrompt(msg, condition, errmsg, format, ...) {  do{prompt(msg,format,__VA_ARGS__);if(!(condition)){printf("%s", errmsg);}}while(!(condition));  }
#define bool char
#define true 1
#define false 0

#define PRESNOST 0.001

double f1(double x) {
  return 10 * x - 19;
}

double f2(double x) {
  return 5 / (x * x);
}

double derive(double x, double (*func)(double)) {
  return (func(x + PRESNOST) - func(x)) / (PRESNOST);
}

int main() {
  double r1, r2, step;
  prompt("Zadaj dve realne cisla oddelene medzerou: ", "%lf %lf", &r1, &r2);
  prompt("Zadajte hodnotu STEP: ", "%lf", &step);

  printf("x f1(x) f1'(x) f2(x) f2'(x)\n");

  double x = r1;
  while (x < r2) {
    double r_f1 = f1(x);
    double rd_f1 = derive(x, f1);
    double r_f2 = f2(x);
    double rd_f2 = derive(x, f2);

    printf("%.2lf %.2lf %.2lf %.2lf %.2lf\n", x, r_f1, rd_f1, r_f2, rd_f2);
    x += step;
  }

  return 0;
}