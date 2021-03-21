/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Úloha 1.4
*/

// Úloha 1.4: Napíšte program, ktorý načíta celé číslo N nasledované znakom konca
// riadku. Potom načíta postupnosť N celých čísel, každé nasledované znakom konca
// riadku. Program určí, či načítaná postupnosť čísel je správna. Postupnosť je správna,
// ak:
//  Prvé číslo je z rozsahu <0, 10>
//  Pre každé i-te číslo (i > 1) platí, že nie je väčšie ako dvojnásobok
// predchádzajúceho (i-1)-ho čísla, ani menšie ako polovica predchádzajúceho (i-1)-
// ho čísla.
// Ak je postupnosť správna, vypíše program správu Postupnost je spravna a odriadkuje,
// inak vypíše Postupnost nie je spravna a odriadkuje.
// Ukážka vstupu:
// 3
// 5
// 7
// 9
// Výstup pre ukážkový vstup:
// Postupnost je spravna

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
  validatedPrompt("Zadaj N <0,10>: ", (n > 0 && n < 10), "N nesplna podmienku <0,10>\n", "%d", &n);

  bool init = false;
  int previous = 0;
  bool correct = true;

  for (int i = 0; i < n; i++) {
    int c = 0;
    prompt("", "%d", &c);

    if (!init) {
      previous = c;
      init = true;
      continue;
    }

    correct = (c > 1) and (c < (previous * 2)) and (c > (previous / 2));

    previous = c;
  }

  printf(correct ? "Postupnost je spravna" : "Postupnost nie je spravna");
  printf("\n");

  getchar();

  return 0;
}