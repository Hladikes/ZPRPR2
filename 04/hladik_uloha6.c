/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 4.6
*/

#include <stdio.h>
#define prompt(n, k, ...) \
  printf("%s", n);        \
  scanf(k, __VA_ARGS__);  \
  fseek(stdin, 0, SEEK_SET);
#define validatedPrompt(msg, condition, errmsg, format, ...) \
  {                                                          \
    do {                                                     \
      prompt(msg, format, __VA_ARGS__);                      \
      if (!(condition)) {                                    \
        printf("%s", errmsg);                                \
      }                                                      \
    } while (!(condition));                                  \
  }
#define bool char
#define true 1
#define false 0
#define or ||
#define and &&


typedef struct Point {
  int x;
  int y;
} Point;

typedef struct Line {
  Point from;
  Point to;
} Line;

bool priesecnik_priamok(Line l1, Line l2, double *x, double *y) {
  double a1 = l1.from.y - l1.to.y;
  double b1 = l1.to.x - l1.from.x;
  double c1 = (l1.from.x * l1.to.y) - (l1.to.x * l1.from.y);
  
  double a2 = l2.from.y - l2.to.y;
  double b2 = l2.to.x - l2.from.x;
  double c2 = (l2.from.x * l2.to.y) - (l2.to.x * l2.from.y);
  
  double d = a1 * b2 - b1 * a2;

  if (d == 0) {
    return false;
  } else {
    *x = (b1 * c2 - c1 * b2) / d;
    *y = (c1 * a2 - a1 * c2) / d;

    return true;
  }
}

int main() {
  Line l1;
  Line l2;

  prompt(
    "Zadaj polohu bodov pre prvu priamku oddelene medzerou\n[A = (x1, y1), B = (x2, y2)]: ", 
    "A = (%d, %d), B = (%d, %d)", 
    &l1.from.x, 
    &l1.from.y, 
    &l1.to.x, 
    &l1.to.y
  );

  prompt(
    "Zadaj polohu bodov pre prvu priamku oddelene medzerou\n[C = (x1, y1), D = (x2, y2)]: ", 
    "C = (%d, %d), D = (%d, %d)", 
    &l2.from.x, 
    &l2.from.y, 
    &l2.to.x, 
    &l2.to.y
  );

  double x = 0, y = 0;
  
  if (priesecnik_priamok(l1, l2, &x, &y)) {
    printf("Suradnice priesecnika priamok AB a CD su (%.1lf, %.1lf)", x, y);
  } else {
    puts("Priamky AB a CD su paralelne");
  }
  
  return 0;
}