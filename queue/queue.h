#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct queue_t queue_t;

struct queue_t
{
    int* data;
    size_t size;
    size_t front;
    size_t rear;
};

queue_t* initialize(int size);
void deinitialize(queue_t* queue);

bool dequeue(queue_t* queue, int* item);
bool enqueue(queue_t* queue, int data);
bool front(queue_t* queue, int* item);
bool rear(queue_t* queue, int* item);

bool is_empty(queue_t* queue);
bool is_full(queue_t* queue);

#endif