/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 5.6
*/

#include <stdio.h>
#include <stdlib.h>
#define prompt(n, k, ...) printf("%s", n);scanf(k, __VA_ARGS__);fseek(stdin,0,SEEK_SET);
#define validatedPrompt(msg, condition, errmsg, format, ...) {  do{prompt(msg,format,__VA_ARGS__);if(!(condition)){printf("%s", errmsg);}}while(!(condition));  }
#define bool char
#define true 1
#define false 0

int main() {
  FILE *prvy = fopen("./prvy.txt", "r");
  FILE *druhy = fopen("./druhy.txt", "r");
  FILE *treti = fopen("./treti.txt", "w+");

  if (!(prvy && druhy && treti)) {
    puts("[CHYBA] Nebolo mozne otvorit subory 'prvy.txt', 'druhy.txt' a 'treti.txt'");
    return 1;
  }

  char word1[100], word2[100];
  int f1 = 0, f2 = 0;
  
  while (f1 != -1 && f1 != -1) {
    f1 = fscanf(prvy, "%s", word1);
    f2 = fscanf(druhy, "%s", word2);
    
    if (f1 != -1) fprintf(treti, "+%s ", word1);
    if (f2 != -1) fprintf(treti, "-%s ", word2);
  }

  fclose(prvy);
  fclose(druhy);
  fclose(treti);

  return 0;
}