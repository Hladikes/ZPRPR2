/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 3.3
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

int main() {
  FILE *largerFile = fopen("./prvy.txt", "r");
  FILE *smallerFile = fopen("./druhy.txt", "r");

  fseek(largerFile, 0, SEEK_END);
  fseek(smallerFile, 0, SEEK_END);

  int largerFileSize = ftell(largerFile);
  int smallerFileSize = ftell(smallerFile);

  if (smallerFileSize > largerFileSize) {
    FILE *tempFile = largerFile;
    largerFile = smallerFile;
    smallerFile = tempFile;
  }

  rewind(largerFile);
  rewind(smallerFile);

  int largerFileCharCount = 0;
  int smallerFileCharCount = 0;

  int matchingCharacters = 0;
  char cs, cl;

  while ((cs = fgetc(smallerFile), cl = fgetc(largerFile)) != EOF) {
    smallerFileCharCount += (cs != EOF);
    largerFileCharCount++;
    matchingCharacters += (cs != EOF && cs == cl);
  }
  
  printf("Pocet roznych znakov: %d\n", smallerFileCharCount - matchingCharacters);
  printf("Jeden zo suborov je dlhsi o pocet znakov %d\n", largerFileCharCount - smallerFileCharCount);

  fclose(largerFile);
  fclose(smallerFile);

  return 0;
}