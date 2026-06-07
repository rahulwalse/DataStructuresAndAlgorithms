#include "queue.h"

#include <stdbool.h>

void init_queue(queue_t* queue)
{
    init_list(&queue->list);
}

void deinit_queue(queue_t* queue)
{
    deinit_list(&queue->list);
}

bool push(queue_t* queue, int data)
{
    return add_at_end(&queue->list, data);
}

bool pop(queue_t* queue, int* item)
{
    return delete_from_front(&queue->list, item);
}

bool front(queue_t* queue, int* item)
{
    if(!queue->list.head) { return false; }

    *item = queue->list.head->data;

    return true;
}

bool is_empty(queue_t* queue)
{
    return queue->list.head == NULL;
}

void print_queue(queue_t* queue)
{
    print(&queue->list);
}

size_t queue_size(queue_t* queue)
{
    return queue->list.size;
}