#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include "node.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct forward_list forward_list;

struct forward_list
{
    node_t* head;
    size_t size;
};

void init_list(forward_list* list);
void deinit_list(forward_list* list);

node_t* create_node(int data);

bool add_at_end(forward_list* list, int data);
bool add_at_front(forward_list* list, int data);
bool insert(forward_list* list, int data, int pos);

bool delete_at_pos(forward_list* list, int* item, int pos);
bool delete_from_end(forward_list* list, int* item);
bool delete_from_front(forward_list* list, int* item);

void print(forward_list* list);

bool reverse_list(forward_list* list);

#endif