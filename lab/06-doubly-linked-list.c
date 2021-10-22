#include <stdio.h>
#include <stdlib.h>

/*
 * Napat
 * 6310400967
 */

typedef struct Node{
  int data;
  struct Node *next, *prev;
} Node;

Node *newNode(int val){
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = val;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

int main(){
  struct Node *head = NULL;
  Node *first = newNode(1);
  Node *second = newNode(2);
  first->next = second;
  second->prev = first;
  if (first->prev != NULL)
      printf("%d", first->prev->data);
  printf(" <- %d -> %d\n", 
          first->data,
          first->next == NULL ? -1 : first->next->data);
  printf("%d <- %d ->", 
          second->prev == NULL ? -1 : second->prev->data,
          second->data);
  if (second->next != NULL)
      printf("%d", second->next->data);
  return 0;
}
