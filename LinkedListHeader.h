//include guards ensure that the compiler only compiles this file one time and does not constantly recompile this file

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef LINKED_LIST_MAIN
#define LINKED_LIST_MAIN  

struct linked_list {   
    struct LLNode *head;
    struct LLNode *tail;
    int size;
};


/**
 * prints the data for a particular node
*/
void show_data(struct LLNode *LL_NODE);

/**
 * initializes an empty linked list
*/
struct linked_list *linked_list_create();

/**
 * return the size of the linked list
*/
int linked_list_size(struct linked_list *this_linked_list);

/**
 * empties the list and frees the memory from the linked list
*/
void empty_list(struct linked_list *this_linked_list);

/**
 * returns the first index of the value in the array, returns -1 if not present
*/
int linked_list_index_of(struct linked_list *this_linked_list, int value);

/**
 * adds an item at the end of the link without needing a node to be passed
*/
void linked_list_add(struct linked_list *this_linked_list, int value);

/**
 * removes a LLNode at a particular index. returns the old data
*/
void linked_list_remove(struct linked_list *this_linked_list, int index);

/**
 * sets the data at a particular index to the new data
*/
void linked_list_set(struct linked_list *this_linked_list, int index, int value);

/** 
 * returns the data a particular index for this linked_list
*/
struct LLNode *linked_list_get(struct linked_list *this_linked_list, int index);

void toString(struct linked_list *this_linked_list);

#endif







