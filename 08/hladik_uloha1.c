/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 8
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define prompt(n, k, ...) printf("%s", n);scanf(k, __VA_ARGS__);fseek(stdin,0,SEEK_SET);
#define validatedPrompt(msg, condition, errmsg, format, ...) {  do{prompt(msg,format,__VA_ARGS__);if(!(condition)){printf("%s", errmsg);}}while(!(condition));  }
#define bool char
#define true 1
#define false 0

#define SIZE 2

typedef struct {
  int id;
  char *osoba;
  char *mesto;
  int rok_nar;
  int poc_dni;
} Zajazd;

char *strin(char *msg, int size) {
  printf("%s", msg);
  char *str = calloc(size, sizeof(char));
  fgets(str, size, stdin);
  int len = strlen(str);
  str[len - 1] = '\0';
  return str;
}

int intin(char *msg) {
  printf("%s", msg);
  int n = 0;
  prompt("", "%d", &n);
  return n;
}

void fill(Zajazd zajazdy[], int size) {
  for (int i = 0; i < size; i++) {
    printf("\n*** Vypln udaje pre osobu c.%d ***\n", i);
    zajazdy[i].id = intin("id: ");
    zajazdy[i].osoba = strin("osoba: ", 100);
    zajazdy[i].mesto = strin("mesto: ", 100);
    zajazdy[i].rok_nar = intin("rok narodenia: ");
    zajazdy[i].poc_dni = intin("pocet dni: ");
  }
}

void print(Zajazd zajazdy[], int size) {
  printf("\n*** Vypis osob ***\n");
  for (int i = 0; i < size; i++) {
    printf(
      "id: %d\nosoba: %s\nmesto: %s\nrok narodenia: %d\npocet dni: %d\n\n",
      zajazdy[i].id,
      zajazdy[i].osoba,
      zajazdy[i].mesto,
      zajazdy[i].rok_nar,
      zajazdy[i].poc_dni
    );
  }
}

void search(Zajazd zajazdy[], int size) {
  char *osoba = strin("zadaj osobu: ", 100);
  for (int i = 0; i < size; i++) {
    if (strcmp(zajazdy[i].osoba, osoba) == 0) {
      printf(
        "id: %d\nosoba: %s\nmesto: %s\nrok narodenia: %d\npocet dni: %d\n\n",
        zajazdy[i].id,
        zajazdy[i].osoba,
        zajazdy[i].mesto,
        zajazdy[i].rok_nar,
        zajazdy[i].poc_dni
      );
      return;
    }
  }
  printf("osoba s menom '%s' nebola najdena\n", osoba);
}

void help() {
  printf("\n*** HELP ***\n");
  printf(" f - fill\n");
  printf(" p - print\n");
  printf(" s - search\n");
  printf(" ? - help\n");
  printf(" x - exit\n");
}

int main() {
  Zajazd zajazdy[SIZE];

  char c = 0;
  while (c != 'x') {
    prompt("> ", "%c", &c);
    switch (c) {
      case 'f': fill(zajazdy, SIZE); break;
      case 'p': print(zajazdy, SIZE); break;
      case 's': search(zajazdy, SIZE); break;
      case '?': help(); break;
    }
  }

  return 0;
}