#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *clone(Node *c) {
  Node *newNode = malloc(sizeof(Node));
  newNode->data = c->data;
  return newNode;
}

void append(Node *u, Node *next) {
  while (u->next != NULL) {
    u = u->next;
  }
  u->next = next;
}

void prepend(Node *u, Node *next) {
  Node *old = clone(u);
  old->next = u->next;
  *u = *next;
  u->next = old;
}

void delete(Node *head, int n) {
  while (head->next != NULL) {
    head = head->next;
  }
  printf("\n");
}

Node *last(Node *head) {
  while (head->next != NULL) {
    head = head->next;
  }
  return head;
}

void print(Node *u) {
  while (u != NULL) {
    printf("%d", u->data);
    u = u->next;

    if (u != NULL) printf(" -> ");
  }
}

void _free(Node *head) {
  
}

int main() {
  Node *head = malloc(sizeof(Node));
  head->data = 1;
  head->next = NULL;

  Node *body = malloc(sizeof(Node));
  body->data = 2;
  body->next = NULL;

  Node *tail = malloc(sizeof(Node));
  tail->data = 3;
  tail->next = NULL;
 
  Node *random = malloc(sizeof(Node));
  random->data = 4;
  random->next = NULL;

  head->next = body;
  body->next = tail;
  
  print(last(random));


  return 0;
}