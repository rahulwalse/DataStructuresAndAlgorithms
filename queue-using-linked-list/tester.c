#include "queue.h"

#include <stdio.h>

int main()
{
    queue_t queue;

    init_queue(&queue);
    push(&queue, 10);
    push(&queue, 20);
    push(&queue, 30);

    print_queue(&queue);
    int retrieved_data = 0;
    front(&queue, &retrieved_data);
    printf("\nFront: %d", retrieved_data);

    pop(&queue, &retrieved_data);
    printf("\nRetrieved data from queue: %d", retrieved_data);

    deinit_queue(&queue);

    return 0;
}