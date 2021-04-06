/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 7.2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define prompt(n, k, ...) printf("%s", n);scanf(k, __VA_ARGS__);fseek(stdin,0,SEEK_SET);
#define validatedPrompt(msg, condition, errmsg, format, ...) {  do{prompt(msg,format,__VA_ARGS__);if(!(condition)){printf("%s", errmsg);}}while(!(condition));  }
#define bool char
#define true 1
#define false 0

void minsort(char **arr, int count) {
  int bound = 0;
  while (bound < count) {
    int smallestIndex = bound;
    for (int n = bound; n < count; n++) {
      if (strcmp(arr[n], arr[smallestIndex]) == -1) {
        smallestIndex = n;
      }
    }
    
    char temp[100];
    strcpy(temp, arr[bound]);
    strcpy(arr[bound], arr[smallestIndex]);
    strcpy(arr[smallestIndex], temp);

    bound++;
  }
}

int main() {
  FILE *namesFile = fopen("./mena.txt", "r");
  if (!namesFile) {
    puts("Nebolo mozne otvorit subor mena.txt");
    return 1;
  }

  int namesCount = 0;
  char c;
  while ((c = fgetc(namesFile)) != EOF) {
    namesCount += (c == '\n');
  }

  fseek(namesFile, 0, SEEK_SET);

  char **names = calloc(namesCount, sizeof(char*));
  char buffer[100];

  for (int n = 0; n < namesCount; n++) {
    fscanf(namesFile, "%s", buffer);
    names[n] = calloc(strlen(buffer), sizeof(char));
    strcpy(names[n], buffer);
  }
  
  for (int i = 0; i < namesCount; i++) {
    printf("%s\n", names[i]);
  }
  puts("***** PO USPORIADANI *****");
  minsort(names, namesCount);
  for (int i = 0; i < namesCount; i++) {
    printf("%s\n", names[i]);
  }

  return 0;
}