#ifndef QUEUE_H
#define QUEUE_H

#include "forward-list.h"
#include "node.h"

#include <stdbool.h>

typedef struct queue_t queue_t;

struct queue_t
{
    forward_list list;
};

void init_queue(queue_t* queue);
void deinit_queue(queue_t* queue);

bool push(queue_t* queue, int data);
bool pop(queue_t* queue, int* item);
bool front(queue_t* queue, int* item);

bool is_empty(queue_t* queue);

void print_queue(queue_t* queue);

size_t queue_size(queue_t* queue);

#endif