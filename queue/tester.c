#include <stdio.h>

#include "queue.h"

typedef enum operation operation;

enum operation
{
    DEQUEUE = 2,
    ENQUEUE = 1,
    EXIT    = 5,
    FRONT   = 3,
    REAR    = 4
};

int main()
{
    /*  Read the stack size  */
    int queue_size = 0;
    printf("\nEnter the queue size: ");
    scanf("%d", &queue_size);

    /*  Initialize queue  */
    queue_t* queue = initialize(queue_size);

    /*  Menu for stack operations  */
    int option  = 0;
    int data    = 0;
    bool exit   = false;
    bool result = false;

    if(!queue)
    {
        exit = true;
        printf("\nFATAL: Queue was not initialized!\n");
    }

    while(!exit)
    {
        printf("\n--QUEUE------------------------------");
        printf("\n1. Enqueue\n2. Dequeue\n3. Front\n4. Rear\n5. Exit");
        printf("\nChoose an option: ");
        scanf("%d", &option);

        switch (option)
        {
        case ENQUEUE:
            printf("\nEnter data to push into queue: ");
            scanf("%d", &data);
            result = enqueue(queue, data);            
            if(!result)
            {
                printf("\nERROR: Queue is full!");
            }
            break;

        case DEQUEUE:
            result = dequeue(queue, &data);
            if(!result)
            {
                printf("\nERROR: Queue is empty!");
            }
            else
            {
                printf("\nDequeued data: %d", data);
            }
            break;

        case FRONT:
            result = front(queue, &data);
            if(!result)
            {
                printf("\nERROR: Queue is empty!");
            }
            else
            {
                printf("\nData at front: %d", data);
            }
            break;

        case REAR:
            result = rear(queue, &data);
            if(!result)
            {
                printf("\nERROR: Queue is empty!");
            }
            else
            {
                printf("\nData at rear: %d", data);
            }
            break;

        case EXIT:
            printf("\nExiting the program...\n");
            exit = true;
            break;
        
        default:
            printf("\nInvalid option chosen! Please choose from given option(s).\n");
            break;
        }
    }

    /*  Deinitialize queue  */
    deinitialize(queue);

    return 0;
}