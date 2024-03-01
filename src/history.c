#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

/* init_history: initialize the linked list to keep the history.  */
List *
init_history() {
  List *list = (List *)malloc(sizeof(List));
  if(!list)
    return NULL;

  list->root = NULL;
  return list;
}

/* Add a history item to the end of the list */
void add_history(List *list, char *str) {
  // Create a new item and verify it
  Item *newItem = (Item *)malloc(sizeof(Item));
  if (!newItem)
    return;

  // Define the new item
  char *tokenStrtPtr = token_start(str);
  char *tokenEndPtr = token_terminator(tokenStrtPtr);
  short tokenLen = tokenEndPtr - tokenStrtPtr;
  newItem->str = copy_str(str, tokenLen);
  newItem->next = NULL;

  // Put the new item in the end
  if (list->root == NULL) {
    newItem->id = 1;
    list->root = newItem;
  } else {
    // Find the end of the list
    Item *temp = list->root;
    while (temp->next != NULL)
      temp = temp->next;

    //Assign the new item in the end
    newItem->id = temp->id+1;
    temp->next = newItem;
  }
}

/* Retrieve the string stored in the node where Item->id == ied */
char *
get_history(List *list, int id) {
  if (!list)
    return NULL;

  // Create an item to iterate
  Item *curr = list->root;
  while (curr && curr->id != id)
    curr = curr->next;

  // Verify curr is not NULL
  if (!curr)
    return NULL;

  return curr->str;
}

/* Print the entire contents of the list */
void print_history(List *list) {
  if (!list)
    return;

  // Create an item to iterate
  Item *curr = list->root;
  int count = 1;

  // While curr isn't NULL
  while (curr) {
    printf("Item %d: %s\n", counter, curr->str);
    count++;
    curr = curr->next;
  }
}

/* Free the history list and the strings it references */
void free_history(List *list) {
  if (!list)
    return;

  // Create an item to iterate
  Item *curr = list->root;

  while (curr) {
    Item *nextItem = curr->next;
    free(curr->str);
    free(curr);
    curr = nextItem;
  }
  free(list);
}
