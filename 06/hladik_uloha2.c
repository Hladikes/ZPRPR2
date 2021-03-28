/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 6.2
*/

#include <stdio.h>
#include <stdlib.h>
#define prompt(n, k, ...) printf("%s", n);scanf(k, __VA_ARGS__);fseek(stdin,0,SEEK_SET);
#define validatedPrompt(msg, condition, errmsg, format, ...) {  do{prompt(msg,format,__VA_ARGS__);if(!(condition)){printf("%s", errmsg);}}while(!(condition));  }
#define hereiam printf("HERE I AM :%d\n", __LINE__)
#define bool char
#define true 1
#define false 0

int main() {
  char filename[20];
  prompt("Zadaj nazov suboru: ", "%s", filename);
  
  FILE *f = fopen(filename, "r");

  if (!f) {
    puts("Subor sa nepodarilo otvorit");
    return -1;
  }

  int newlineCount = 1;
  char c;
  while ((c = fgetc(f)) != EOF) {
    if (c == '\n') newlineCount++;
  }

  fseek(f, 0, 0);
  int histogram[newlineCount][26];

  for (int y = 0; y < newlineCount; y++) {
    for (int x = 0; x < 26; x++) {
      histogram[y][x] = 0;
    }
  }

  int currentLine = 0;

  while ((c = fgetc(f)) != EOF) {
    c -= 32 * (c >= 97 && c <= 122);
    histogram[currentLine][c - 65]++;
    currentLine += (c == '\n');
  }

  printf("      ");
  for (int i = 0; i < 26; i++) {
    printf("   %c", i + 65);
  }
  printf("\n");

  for (int y = 0; y < newlineCount; y++) {
    printf("%4d |", y + 1);
    for (int x = 0; x < 26; x++) {
      printf("%4d", histogram[y][x]);
    }
    printf("\n");
  }

  fclose(f);
  return 0;
}