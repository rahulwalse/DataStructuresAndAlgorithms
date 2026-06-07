#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct cqueue_t cqueue_t;

struct cqueue_t
{
    int* data;
    size_t size;
    size_t front;
    size_t rear;
};

cqueue_t* initialize(int size);
void deintialize(cqueue_t* queue);

bool dequeue(cqueue_t* queue, int* item);
bool enqueue(cqueue_t* queue, int data);
bool front(cqueue_t* queue, int* item);
bool rear(cqueue_t* queue, int* item);

bool is_empty(cqueue_t* queue);
bool is_full(cqueue_t* queue);

#endif