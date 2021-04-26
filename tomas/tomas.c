#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define hereiam printf("Here I am [%d]\n", __LINE__);

typedef struct person
{
  char *name;
  char *adress;
  int start;
  int end;
  struct person *nextP;
} PERSON;

typedef struct reservation
{
  int id;
  int size;
  double price;
  PERSON *person;
  struct reservation *nextR;
} RESERVATION;

void readFile(FILE **hotel, RESERVATION **reservation)
{
  if ((*hotel = fopen("hotel.txt", "r+")) == NULL)
  {
    printf("Nenasiel sa vybrany subor hotel.txt\n");
    exit(0);
  }
  else
  {
    printf("Subor hotel sa uspesne otvoril.\n");
    printf("----------------------------------------------------------------------------------------\n");
  }

  char *line = malloc(sizeof(char) * 100);

  RESERVATION *r = *reservation;
  PERSON *p = NULL;

  while (fgets(line, 100, *hotel))
  {
    if (strcmp(line, "---\n") == 0)
    {
      hereiam;
      puts("Precital som izbu");
      RESERVATION *newReservation = (RESERVATION*) malloc(sizeof(RESERVATION));
      hereiam;
      if (newReservation == NULL)
      {
        puts("NENI");
      }else{
        puts("EXISTUJE");
      }
      
      fscanf(*hotel, "%d %d %lf", &(newReservation->id), &(newReservation->size), &(newReservation->price));
      hereiam;
      newReservation->nextR = NULL;
      newReservation->person = NULL;
      hereiam;
      if (r == NULL)
      {
        *reservation = newReservation;
        r = *reservation;
        hereiam;
      }
      else
      {
        hereiam;
        r->nextR = newReservation;
        hereiam;
        r = r->nextR;
      }
      r->person = NULL;
      p = r->person;
    }
    if (strcmp(line, "#\n") == 0)
    {
      puts("Precital som hosta");
      PERSON *newPerson = malloc(sizeof(PERSON));
      fgets(newPerson->name, 100, *hotel);
      fgets(newPerson->adress, 100, *hotel);
      fscanf(*hotel, "%d %d ", &(newPerson->start), &(newPerson->end));
      if (p == NULL)
      {
        r->person = newPerson;
        p = r->person;
        hereiam;
      }
      else
      {
        hereiam;
        p->nextP = newPerson;
        hereiam;
        p = p->nextP;
      }      
    }
  }
}

int main()
{
  // char a;
  FILE *hotel = NULL;

  RESERVATION *reservation = NULL;

  // while (a != 'k')
  // {
  //   printf("\nVyberte funkciu: ");
  //   fseek(stdin, 0, SEEK_SET);
  //   scanf("%c", &a);
  //   getchar();
  //   switch (a)
  //   {
  //   case 'h':
      readFile(&hotel, &reservation);
  //   }
  // }
  fclose(hotel);


  return 0;
}