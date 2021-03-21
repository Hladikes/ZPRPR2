/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: 
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
  int n = 0;
  prompt("Zadaj N: ", "%d", &n);
  double min = -1, max = -1;
  bool init = false;

  for (int i = 0; i < n; i++) {
    double d = 0;
    prompt("", "%lf", &d);

    if (!init) {
      init = true;
      min = d;
      max = d;
      continue;
    }
    
    if (d < min) min = d;
    if (d > max) max = d;
  }

  printf("Minimum: %.2lf\n", min);
  printf("Maximum: %.2lf\n", max);

  getchar();

  return 0;
}