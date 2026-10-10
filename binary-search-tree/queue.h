#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

#include <stddef.h>

typedef int bool;
#define TRUE    1
#define FALSE   0

typedef struct queue_t queue_t;

struct queue_t
{
    node_t** nodes;
    size_t front;
    size_t rear;
    size_t size;
};

node_t* back(queue_t* queue);

void deinitialize(queue_t** queue);

node_t* front(queue_t* queue);

queue_t* initialize(int size);

bool is_full(queue_t* queue);

bool is_empty(queue_t* queue);

void pop(queue_t** queue);

void push(queue_t** queue, node_t* node);

#endif