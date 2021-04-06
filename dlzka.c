/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Measurments
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define prompt(n, k, ...) printf("%s", n);scanf(k, __VA_ARGS__);fseek(stdin,0,SEEK_SET);
#define validatedPrompt(msg, condition, errmsg, format, ...) {  do{prompt(msg,format,__VA_ARGS__);if(!(condition)){printf("%s", errmsg);}}while(!(condition));  }
#define bool char
#define true 1
#define false 0

int dlzka(int i, char str[]) { 
  return (str[i] == '\0') ? 0 : 1 + dlzka(i + 1, str);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("One file must be submitted\n");
    return 1;
  }

  FILE *lorem = fopen(argv[1], "r");
  if (!lorem) {
    printf("Unable to open file '%s'", argv[1]);
    return -1;
  }
  char buffer[100];
  int n;
  clock_t begin = clock();
  while (fscanf(lorem, "%s", buffer) > 0) {
    n = dlzka(0, buffer);
  }
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("%lf dlzka()\n", time_spent);
  fclose(lorem);
  n = n;
  return 0;
}