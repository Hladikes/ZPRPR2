/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 4.1
*/

#include <stdio.h>
#define prompt(n, k, ...) printf("%s", n);scanf(k, __VA_ARGS__);fseek(stdin,0,SEEK_SET);
#define validatedPrompt(msg, condition, errmsg, format, ...) {  do{prompt(msg,format,__VA_ARGS__);if(!(condition)){printf("%s", errmsg);}}while(!(condition));  }
#define bool char
#define true 1
#define false 0
#define or ||
#define and &&

void vymen_ukazovatele(int **a, int **b) {
  int *temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  int a = 120, b = 360;
  int *p_a, *p_b;

  p_a = &a;
  p_b = &b;

  printf("p_a = %p; a = %d\n", p_a, *p_a);
  printf("p_b = %p; b = %d\n", p_b, *p_b);
  printf("================\n");
  vymen_ukazovatele(&p_a, &p_b);
  printf("p_a = %p; a = %d\n", p_a, *p_a);
  printf("p_b = %p; b = %d\n", p_b, *p_b);

  return 0;
}