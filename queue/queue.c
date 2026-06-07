#include "queue.h"

#include <stdlib.h>

queue_t* initialize(int size)
{
    if(size <= 0) { return NULL; }

    queue_t* queue = malloc(sizeof(queue_t));
    if(!queue) { return NULL; }

    queue->data = malloc(sizeof(int) * size);
    if(!queue->data)
    {
        free(queue);
        return NULL;
    }
    queue->size = size;
    queue->front = 0;
    queue->rear = 0;

    return queue;
}

void deinitialize(queue_t* queue)
{
    if(queue && queue->data)
    {
        free(queue->data);
        queue->data = NULL;
        queue->size = 0;
        queue->front = queue->rear = 0;
    }
    
    if(queue)
    {
        free(queue);
        queue = NULL;
    }
}

bool dequeue(queue_t* queue, int* item)
{
    bool success = false;
    if(!is_empty(queue))
    {
        *item = queue->data[queue->front];
        queue->front++;
        success = true;
    }

    return success;
}

bool enqueue(queue_t* queue, int data)
{
    bool success = false;
    if(!is_full(queue))
    {
        queue->data[queue->rear] = data;
        queue->rear++;
        success = true;
    }
    return success;
}

bool front(queue_t* queue, int* item)
{
    bool success = false;
    if(!is_empty(queue))
    {
        *item = queue->data[queue->front];
        success = true;
    }

    return success;
}

bool rear(queue_t* queue, int* item)
{
    bool success = false;
    if(!is_empty(queue))
    {
        *item = queue->data[queue->rear - 1];
        success = true;
    }

    return success;
}

bool is_empty(queue_t* queue)
{
    if(queue->front == queue->rear)
    {
        /*  Reset front & rear to 0 to utilize array efficiently  */
        queue->front = queue->rear = 0;
        return true;
    }

    return false;
}

bool is_full(queue_t* queue)
{
    return queue->rear == queue->size;
}