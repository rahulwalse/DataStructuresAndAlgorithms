#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include <stdbool.h>
#include <stddef.h>

#include "node.h"

typedef struct forward_list forward_list;

struct forward_list
{
    node_t* head;
    size_t size;
};

void init_list(forward_list* list);
void deinit_list(forward_list* list);

bool add_at_end(forward_list* list, int data);
bool add_at_front(forward_list* list, int data);
bool insert(forward_list* list, int data, size_t pos);

bool delete_at_pos(forward_list* list, int* item, size_t pos);
bool delete_from_end(forward_list* list, int* item);
bool delete_from_front(forward_list* list, int* item);

void print(forward_list* list);

bool reverse_list(forward_list* list);

#endif