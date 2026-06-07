#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"

#include <stdbool.h>
#include <stddef.h>

typedef struct linked_list linked_list;

struct linked_list
{
    node_t* head;
    node_t* tail;
    size_t size;
};

void init_list(linked_list* list);
void deinit_list(linked_list* list);

bool add_end(linked_list* list, int data);
bool add_front(linked_list* list, int data);
bool insert(linked_list* list, int data, size_t pos);

bool delete_at(linked_list* list, int* item, size_t pos);
bool delete_end(linked_list* list, int* item);
bool delete_front(linked_list* list, int* item);

void print_list(linked_list* list);

#endif