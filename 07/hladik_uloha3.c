/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 7.3
*/

#include <stdio.h>
#include <stdlib.h>
#define prompt(n, k, ...) printf("%s", n);scanf(k, __VA_ARGS__);fseek(stdin,0,SEEK_SET);
#define validatedPrompt(msg, condition, errmsg, format, ...) {  do{prompt(msg,format,__VA_ARGS__);if(!(condition)){printf("%s", errmsg);}}while(!(condition));  }
#define bool char
#define true 1
#define false 0

int najdi(char *s, char c) {
  if (s[0] == '\0') return -1000;
  if (s[0] == c) return 1;
  return 1 + najdi(&s[1], c);
}

int main() {
  char str[100], c = 0;
  puts("Napis '* *' pre ukoncenie");
  while (true) {
    prompt("Zadaj slovo a znak oddelene medzerou: ", "%s %c", str, &c);
    if (str[0] == '*') break;

    int h = najdi(str, c) - 1;
    if (h >= 0) {
      printf("znak %c je na pozicii %d v %s\n", c, h, str);
    } else {
      printf("Znak %c sa v %s nenachadza\n", c, str);
    }
  }
  return 0;
}