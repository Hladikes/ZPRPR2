/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 4.5
*/

#include <stdio.h>
#define prompt(n, k, ...) printf("%s", n);scanf(k, __VA_ARGS__);fseek(stdin,0,SEEK_SET);
#define validatedPrompt(msg, condition, errmsg, format, ...) {  do{prompt(msg,format,__VA_ARGS__);if(!(condition)){printf("%s", errmsg);}}while(!(condition));  }
#define bool char
#define true 1
#define false 0
#define or ||
#define and &&

#include <math.h>

int kvadraticka_rovnica(double a, double b, double c, double *x1, double *x2) {
  if (!a) {
    *x1 = -c / b;
    return 1;
  }

  double D = (b * b) - (4 * a * c);
  if (D < 0) return 0;

  double sqrtD = sqrt(D);
  *x1 = (-b + sqrtD) / (2 * a);
  *x2 = (-b - sqrtD) / (2 * a);

  return 2;
}

int main() {
  // Works well with a = 4, b = 5, c = 1
  double a, b, c, x1, x2;

  prompt("Zadaj 3 realne cisla oddelene medzerou: ", "%lf %lf %lf", &a, &b, &c);

  int roots = kvadraticka_rovnica(a, b, c, &x1, &x2);

  if (roots <= 1) {
    if (!a) {
      printf("x = %lf", x1);
    } else {
      printf("Rovnica nema riesenie");
    }
    return 0;
  }

  printf("x1 = %lf, x2 = %lf", x1, x2);

  return 0;
}