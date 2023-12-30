#include <stdlib.h>
#include <stdio.h>
#include "LinkedListHeader.h"

struct LLNode {
    struct LLNode *next;
    int data;
};


void show_data(struct LLNode *LL_NODE) {
    printf("show data: %d, \n", LL_NODE->data);
}


struct linked_list *linked_list_create() {
    struct linked_list *ret;
    ret = malloc(sizeof(struct linked_list));
    ret->head = NULL;
    ret->tail = NULL;
    ret->size = 0;
    return ret;
};

struct LLNode *linked_list_get(struct linked_list *this_linked_list, int index) {
    if (index == 0) {
        return this_linked_list->head;
    } else if (index == this_linked_list->size - 1) {
        return this_linked_list->tail;
    }
    int counter = 0;
    struct LLNode *ret = this_linked_list->head;
    while (counter < index) {
        ret = ret->next;
        counter += 1;
    }
    return ret;
}

void empty_list(struct linked_list *this_linked_list) {
    if (this_linked_list->head != NULL) {
        struct LLNode *trail = this_linked_list->head;
        struct LLNode *lead = this_linked_list->head->next;
        while (lead != NULL) {
            free(trail);
            trail = lead;
            lead = lead->next;
        }
        free(trail); //one more trail node to be freed
        this_linked_list->head = NULL;
        this_linked_list->tail = NULL;
        this_linked_list->size = 0;    
    }
}

int linked_list_index_of(struct linked_list *this_linked_list, int value) {
    struct LLNode *temp = (*this_linked_list).head;
    for (int i = 0; i < linked_list_size(this_linked_list); i++) {
        if ((*temp).data == value) {
            return i;
        }
        temp = temp->next;
    }
    return -1;
}

void linked_list_add(struct linked_list *this_linked_list, int value) {
    struct LLNode *to_add;    
    to_add = malloc(sizeof(struct LLNode));
    to_add->next = NULL;
    to_add->data = value;
    if (this_linked_list->size == 0) {
        this_linked_list->head = to_add;
        this_linked_list->tail = to_add;
    } else {
        this_linked_list->tail->next = to_add;
        this_linked_list->tail = to_add;
    }
    this_linked_list->size += 1;
}

void linked_list_remove(struct linked_list *this_linked_list, int index) {
    int counter = 0;
    if (index == 0) {
        struct LLNode *temp = (*this_linked_list).head;
        if (this_linked_list->size == 1) { //only 1 element in the list
            this_linked_list->head = NULL;
            this_linked_list->tail = NULL;
        } else {
            this_linked_list->head = this_linked_list->head->next;
        }
        free(temp); //frees the node from memory
    } else {
        struct LLNode *temp = linked_list_get(this_linked_list, index - 1); //the element before the one being removed
        struct LLNode *node_to_be_freed = (*temp).next;
        temp->next = temp->next->next;
        if (index == this_linked_list->size - 1) {
            this_linked_list->tail = temp;
        }
        free(node_to_be_freed); //frees the removed node from memory
    }
    this_linked_list->size -= 1;
}

int linked_list_size(struct linked_list *this_linked_list) {
    return this_linked_list->size;
}


void linked_list_set(struct linked_list *this_linked_list, int index, int value) {
    struct LLNode *temp = linked_list_get(this_linked_list, index);
    temp->data = value;
}


void toString(struct linked_list *this_linked_list) {
    if (this_linked_list->size == 0) {
        printf("The list is empty\n");
    } else {
        struct LLNode *temp = this_linked_list->head;
        int counter = 0;
        while (counter < this_linked_list->size) {
            printf("%d, ", (*temp).data);
            temp = temp->next;
            counter += 1;
        }
        printf("\n");
    }
}
