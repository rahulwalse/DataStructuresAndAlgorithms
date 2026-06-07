#include "circular-queue.h"

#include <stdlib.h>

cqueue_t* initialize(int size)
{
    if(size <= 0) { return NULL; }

    cqueue_t* queue = malloc(sizeof(cqueue_t));
    if(!queue) { return NULL; }

    queue->data = malloc(sizeof(int) * (size + 1));
    if(!queue->data)
    {
        free(queue);
        return NULL;
    }
    queue->size = size + 1;
    queue->front = 0;
    queue->rear = 0;

    return queue;
}

void deintialize(cqueue_t* queue)
{
    if(queue && queue->data)
    {
        free(queue->data);
        queue->data = NULL;
        queue->size = 0;
        queue->front = 0;
        queue->rear = 0;
    }

    if(queue)
    {
        free(queue);
        queue = NULL;
    }
}

bool dequeue(cqueue_t* queue, int* item)
{
    bool success = false;

    if(!is_empty(queue))
    {
        queue->front = (queue->front + 1) % queue->size;
        *item = queue->data[queue->front];
        success = true;
    }

    return success;
}

bool enqueue(cqueue_t* queue, int data)
{
    bool success = false;

    if(!is_full(queue))
    {
        queue->rear = (queue->rear + 1) % queue->size;
        queue->data[queue->rear] = data;
        success = true;
    }

    return success;
}

bool front(cqueue_t* queue, int* item)
{
    bool success = false;

    if(!is_empty(queue))
    {
        size_t front = (queue->front + 1) % queue->size;
        *item = queue->data[front];
        success = true;
    }

    return success;
}

bool rear(cqueue_t* queue, int* item)
{
    bool success = false;

    if(!is_empty(queue))
    {
        *item = queue->data[queue->rear];
        success = true;
    }

    return success;
}

bool is_empty(cqueue_t* queue)
{
    return queue->front == queue->rear;
}

bool is_full(cqueue_t* queue)
{
    return (queue->rear + 1) % queue->size == queue->front;
}