/*
*                  FIIT STU
*    Základy procedurálneho programovania
*                  LS 2021
*                Adam Hladík
*    Prostredie: Visual Studio Code + GCC-8.2.0-5
*   Popis programu: Semestrálny projekt 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

#define NAME_LENGTH 50
#define ADDRESS_LENGTH 100
#define hereiam printf("Here I am [%d]\n", __LINE__);
#define ERR_FILE 10

typedef struct Guest {
  char *name;
  char *address;
  int reservationStart;
  int reservationEnd;
  struct Guest *nextGuest;
} Guest;

typedef struct Room {
  int id;
  int size;
  double price;
  struct Room *nextRoom;
  Guest *firstGuest;
} Room;

// util

void _removeTrailingNewline(char *str) {
  int len = strlen(str);
  if (str[len - 1] == '\n') {
    str[len - 1] = '\0';
  }
}

char _chin() {
  char c = getchar();
  fseek(stdin, 0, SEEK_SET);
  return c;
}

char *_strin(int size) {
  char *str = (char *)calloc(size, sizeof(char));
  fgets(str, size, stdin);
  fseek(stdin, 0, SEEK_SET);
  return str;
}

int _intin() {
  int n = 0;
  scanf("%d", &n);
  fseek(stdin, 0, SEEK_SET);
  return n;
}

double _dblin() {
  double d = 0;
  scanf("%lf", &d);
  fseek(stdin, 0, SEEK_SET);
  return d;
}

// guest

bool _isGuestDelimiter(char *str) {
  return strcmp(str, "#\n") == 0;
}

Guest *_readGuest(FILE *f) {
  Guest *guest = (Guest *)malloc(sizeof(Guest));

  guest->name = (char *)calloc(NAME_LENGTH, sizeof(char));
  fgets(guest->name, NAME_LENGTH, f);
  _removeTrailingNewline(guest->name);

  guest->address = (char *)calloc(ADDRESS_LENGTH, sizeof(char));
  fgets(guest->address, NAME_LENGTH, f);
  _removeTrailingNewline(guest->address);

  fscanf(f, "%d %d ", &(guest->reservationStart), &(guest->reservationEnd));

  guest->nextGuest = NULL;
  return guest;
}

void _printGuest(Guest *g) {
  printf(
      "[ GUEST ]\n|- name:'%s'\n|- address:'%s'\n|- rstart:'%d'\n|- rend:'%d'\n\n",
      g->name,
      g->address,
      g->reservationStart,
      g->reservationEnd);
}

Guest *_getLastGuest(Guest *g) {
  while (g->nextGuest != NULL) {
    g = g->nextGuest;
  }
  return g;
}

void _pushGuest(Guest *dest, Guest *src) {
  _getLastGuest(dest)->nextGuest = src;
}

// https://stackoverflow.com/a/6417182/4396543
void _freeGuest(Guest **g) {
  Guest *temp;
  while ((*g) != NULL) {
    temp = (*g);
    (*g) = (*g)->nextGuest;
    free(temp->name);
    free(temp->address);
    free(temp);
  }
}

// room

bool _isRoomDelimiter(char *str) {
  return strcmp(str, "---\n") == 0;
}

Room *_readRoom(FILE *f) {
  Room *room = (Room *)malloc(sizeof(Room));
  fscanf(f, "%d %d %lf ", &(room->id), &(room->size), &(room->price));
  room->nextRoom = NULL;
  room->firstGuest = NULL;
  return room;
}

void _printRoom(Room *r) {
  printf(
      "[ ROOM ]\n|- id:'%d'\n|- size:'%d'\n|- price:'%lf'\n\n",
      r->id,
      r->size,
      r->price);
}

Room *_getLastRoom(Room *r) {
  while (r->nextRoom != NULL) {
    r = r->nextRoom;
  }
  return r;
}

void _pushRoom(Room *dest, Room *src) {
  _getLastRoom(dest)->nextRoom = src;
}

// https://stackoverflow.com/a/6417182/4396543
void _freeRoom(Room **r) {
  if (!(*r)) return;

  Room *temp;
  _freeGuest(&((*r)->firstGuest));
  while ((*r) != NULL) {
    temp = (*r);
    (*r) = (*r)->nextRoom;
    free(temp);
  }
}

// hotel

// void _printHotel(Room *r) {
//   while (r) {
//     int _padleft = 1;
//     Guest *g = r->firstGuest;
//     printf("|_ Room %d\n", r->id);

//     while (g) {
//       for (int i = 0; i < _padleft; i++) printf("  ");
//       printf("|_ %s\n", g->name);
//       _padleft++;
//       g = g->nextGuest;
//     }
//     r = r->nextRoom;
//     printf("\n");
//   }
// }

void _saveHotel(Room *r) {
  FILE *hotel = fopen("./hotel.txt", "w");
  if (!hotel) exit(ERR_FILE);

  while (r) {
    fprintf(
        hotel,
        "---\n%d\n%d\n%g\n",
        r->id,
        r->size,
        r->price);

    Guest *g = r->firstGuest;
    while (g) {
      fprintf(
          hotel,
          "#\n%s\n%s\n%d\n%d\n",
          g->name,
          g->address,
          g->reservationStart,
          g->reservationEnd);
      g = g->nextGuest;
    }
    r = r->nextRoom;
  }
  fclose(hotel);
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

void n(Room **firstRoom, bool output) {
  if (*firstRoom) _freeRoom(firstRoom);

  FILE *hotel = fopen("./hotel.txt", "r");
  if (!hotel) {
    if (output) puts("Zaznamy neboli nacitane");
    exit(ERR_FILE);
  }

  // *firstRoom = _readRoom(hotel);
  Room *r = *firstRoom;
  Guest *g = NULL;

  int records = 0;

  char buffer[1024];
  while (fgets(buffer, 1024, hotel)) {
    if (_isGuestDelimiter(buffer)) {
      if (!g) {
        r->firstGuest = _readGuest(hotel);
        g = r->firstGuest;
      } else {
        g->nextGuest = _readGuest(hotel);
        g = g->nextGuest;
      }
    }

    if (_isRoomDelimiter(buffer)) {
      if (!r) {
        *firstRoom = _readRoom(hotel);
        r = *firstRoom;
      } else {
        r->nextRoom = _readRoom(hotel);
        r = r->nextRoom;
      }
      g = r->firstGuest;

      records++;
    }
  }

  fclose(hotel);
  if (output) printf("Nacitalo sa %d zaznamov\n", records);
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

Room *v_findSmallestRoom(Room *from, int idOffset) {
  Room *smallest = NULL;
  int smallestId = -1;
  while (from != NULL) {
    if (from->id > idOffset && (smallestId == -1 || from->id < smallestId)) {
      smallestId = from->id;
      smallest = from;
    }

    from = from->nextRoom;
  }
  return smallest;
}

void v_printRoom(Room *r) {
  if (!r) return;

  Guest *g = r->firstGuest;

  printf(
      "Izba cislo: %d\nPocet lozok: %d\nCena: %g\nZoznam hosti:\n",
      r->id,
      r->size,
      r->price);

  while (g) {
    printf(
        "Meno: %s\nAdresa: %s\nZaciatok rezervacie: %d\nKoniec rezervacie: %d\n",
        g->name,
        g->address,
        g->reservationStart,
        g->reservationEnd);

    g = g->nextGuest;
    if (g) {
      puts("############################");
    }
  }
}

void v(Room *hotel) {
  if (!hotel) return;

  Room *temp = NULL;
  bool showHotelDivier = false;
  while ((temp = v_findSmallestRoom(hotel, temp ? temp->id : 0)) != NULL) {
    if (showHotelDivier) {
      puts("----------------------------\n----------------------------");
    }
    v_printRoom(temp);
    showHotelDivier = true;
  }
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

void r(Room **hotel) {
  // if (!(*hotel)) return;

  FILE *f = fopen("./hotel.txt", "a");
  if (!f) exit(ERR_FILE);

  int id = _intin();
  int size = _intin();
  double price = _dblin();
  int count = _intin();
  fprintf(
      f,
      "---\n%d\n%d\n%g\n",
      id,
      size,
      price);

  char *name = NULL, *address = NULL;
  int r_start = 0, r_end = 0;

  for (int n = 0; n < count; n++) {
    name = _strin(NAME_LENGTH);
    address = _strin(ADDRESS_LENGTH);
    _removeTrailingNewline(name);
    _removeTrailingNewline(address);

    r_start = _intin();
    r_end = _intin();
    fprintf(
        f,
        "#\n%s\n%s\n%d\n%d\n",
        name,
        address,
        r_start,
        r_end);

    free(name);
    free(address);
  }

  fclose(f);
  n(hotel, false);
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

bool h_isReserved(Room *r, int reservationDate) {
  Guest *g = r->firstGuest;

  while (g != NULL) {
    if (reservationDate >= g->reservationStart && reservationDate <= g->reservationEnd) {
      return true;
    }
    g = g->nextGuest;
  }

  return false;
}

void h(Room *hotel) {
  if (!hotel) return;

  int reservationDate = _intin();

  Room *temp = NULL;
  bool isSomeRoomReserved = false;

  while ((temp = v_findSmallestRoom(hotel, temp ? temp->id : 0)) != NULL) {
    if (h_isReserved(temp, reservationDate)) {
      printf("%d\n", temp->id);
      isSomeRoomReserved = true;
    }
  }

  if (!isSomeRoomReserved) {
    printf("K datumu %d neevidujeme rezervaciu.\n", reservationDate);
  }
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

void z(Room **hotel) {
  if (!(*hotel)) return;

  int idToDelete = _intin();

  Room *r = *hotel;

  if (r->id == idToDelete) {
    *hotel = r->nextRoom;
    r->nextRoom = NULL;
    _freeRoom(&r);
    _saveHotel(*hotel);
    printf("Rezervacia izby cislo %d bola zrusena.\n", idToDelete);
    return;
  }

  while (r) {
    if (r->nextRoom && r->nextRoom->id == idToDelete) {
      printf("Rezervacia izby cislo %d bola zrusena.\n", idToDelete);
      Room *roomToDelete = r->nextRoom;
      r->nextRoom = roomToDelete->nextRoom;
      roomToDelete->nextRoom = NULL;
      _freeRoom(&roomToDelete);
    }

    r = r->nextRoom;
  }
  _saveHotel(*hotel);
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

void a(Room *hotel) {
  if (!hotel) return;

  Room *r = hotel;
  int id = _intin();
  int newSize = _intin();
  bool changed = false;

  while (r) {
    if (r->id == id) {
      r->size = newSize;
      changed = true;
    }
    r = r->nextRoom;
  }

  if (changed) {
    _saveHotel(hotel);
  }

  printf("Izba cislo %d ma lozkovu kapacitu %d\n", id, newSize);
}

// main

int main() {
  Room *hotel = NULL;
  bool loop = true;
  while (loop) {
    printf("$: ");
    switch (_chin()) {
      case 'n':
        n(&hotel, true);
        break;
      case 'v':
        v(hotel);
        break;
      case 'r':
        r(&hotel);
        break;
      case 'h':
        h(hotel);
        break;
      case 'z':
        z(&hotel);
        break;
      case 'a':
        a(hotel);
        break;
      case 'k':
        loop = false;
        break;
    }
  }

  _freeRoom(&hotel);

  return 0;
}