#include "queue.h"

#include <stdlib.h>

#define DEFAULT_SIZE    5

node_t* back(queue_t* queue)
{
    node_t* back_node = NULL;
    if(!is_empty(queue))
    {
        back_node = queue->nodes[queue->rear - 1];
    }
    return back_node;
}

void deinitialize(queue_t** queue)
{
    /*  Free memory allocated to store node pointers.  */
    if(*queue && (*queue)->nodes)
    {
        free((*queue)->nodes);
        (*queue)->nodes = NULL;
        (*queue)->size = 0;
        (*queue)->front = (*queue)->rear = 0;
    }
    /*  Free memory allocated to queue.  */
    if(*queue)
    {
        free(*queue);
        *queue = NULL;
    }
}

node_t* front(queue_t* queue)
{
    node_t* front_node = NULL;
    if(!is_empty(queue))
    {
        front_node = queue->nodes[queue->front];
    }
    return front_node;
}

queue_t* initialize(int size)
{
    if(size <= 0) { return NULL; }

    queue_t* queue = malloc(sizeof(queue_t));
    /*  Memory allocation failed!  */
    if(!queue) { return NULL; }
    /*  Allocate memory to store node pointers.  */
    queue->nodes = malloc(sizeof(node_t*) * size);
    /*  Memory allocation failed!  */
    if(!queue->nodes)
    {
        free(queue);
        return NULL;
    }
    queue->size = size;
    queue->front = 0;
    queue->rear = 0;

    return queue;
}

bool is_full(queue_t* queue)
{
    return queue->rear == queue->size;
}

bool is_empty(queue_t* queue)
{
    if(queue && queue->front == queue->rear)
    {
        /*  Reset front & rear to utilize memory efficiently.  */
        queue->front = queue->rear = 0;
        return TRUE;
    }
    return FALSE;
}

void pop(queue_t** queue)
{
    if(!is_empty(*queue))
    {
        (*queue)->front++;
    }
}

void push(queue_t** queue, node_t* node)
{
    /*  If node is NULL, do nothing.  */
    if(!node) { return; }
    /*  If queue is empty, allocate memory with default size.  */
    if(!*queue)
    {
        *queue = initialize(DEFAULT_SIZE);
    }
    /*  Queue is full, double the size of queue.  */
    if(is_full(*queue))
    {
        reallocate_memory(queue);
    }
    /*  Push the node (pointer) on the queue.  */
    (*queue)->nodes[(*queue)->rear] = node;
    (*queue)->rear++;
}

void reallocate_memory(queue_t** queue)
{
    /*  Queue is empty, do nothing.  */
    if(!*queue) { return; }    
    /*  Allocate double memory.  */
    size_t double_size = (*queue)->size * 2;
    node_t** doubled_nodes = malloc(sizeof(node_t*) * double_size);    
    /*  Memory allocation failed!  */
    if(!doubled_nodes) { return; }
    /*  Copy the elements (pointers) to new memory.  */
    for(size_t index = 0; index < (*queue)->size; index++)
    {
        doubled_nodes[index] = (*queue)->nodes[index];
    }
    /*  Free the existing memory.  */
    free((*queue)->nodes);
    /*  Queue now points to doubled memory.  */
    (*queue)->nodes = doubled_nodes;
    (*queue)->size = double_size;
}