#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"


/* Initialize the linked list to keep the history. */
List *init_history() {
  List *history_list = malloc(sizeof(List));
  history_list->root = malloc(sizeof(Item));
  return history_list;
}


/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str) {
  Item *temp = list->root;
  int counter = 1;
  while(temp->next != 0) {
    temp = temp->next;
    counter++;
  }
  temp->next = malloc(sizeof(Item));
  temp->next->str = copy_str(str, string_length(str));
  temp->next->id = counter;
}


/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id) {
  Item *temp = list->root;
  while(temp != 0) {
    if (temp->id == id) {
      return temp->str;
    }
    temp = temp->next;
  }
  return "id not found";
}


/*Print the entire contents of the list. */
void print_history(List *list) {
  Item *temp = list->root->next;
  while(temp != 0) {
    printf("%d.%s\n",temp->id,temp->str);
    temp = temp->next;
  }
}


/* Free the history list and the strings it references. */
void free_history(List *list) {
  //free(list);
  Item *cur = list->root;
  while(cur->next != 0) {
    Item *prev = cur;
    cur = cur->next;
    free(prev->str);
    free(prev);
  }
  free(cur->str);
  free(cur);
  free(list);
}
