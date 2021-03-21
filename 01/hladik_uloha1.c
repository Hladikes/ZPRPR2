/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: BMI calculator
*/

#include <stdio.h>
#define prompt(n, k, ...) printf(n);scanf(k, __VA_ARGS__);fflush(stdin);
#define validatedPrompt(msg, condition, errmsg, format, ...) {  do{prompt(msg,format,__VA_ARGS__);if(!(condition)){printf(errmsg);}}while(!(condition));  }
#define bool int
#define true 1
#define false 0
#define or ||
#define and &&

int main() {
  double m = 0, h = 0;
  prompt("Zadaj vysku (m) a hmotnost (kg): ", " %lf %lf", &m, &h);
  fflush(stdin);
  m /= 100;
  double bmi = h / (m * m);
  printf("BMI: %.3lf", bmi);
  getchar();
  return 0;
}