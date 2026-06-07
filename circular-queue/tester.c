#include <stdio.h>

#include "circular-queue.h"

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
    /*  Read the size of circular queue  */
    int queue_size = 0;
    printf("\nEnter the size of circular queue: ");
    scanf("%d", &queue_size);

    /*  Initialize circular queue  */
    cqueue_t* cqueue = initialize(queue_size);

    int option  = 0;
    int data    = 0;
    bool exit   = false;
    bool result = false;

    if(!cqueue)
    {
        exit = true;
        printf("\nFATAL: Queue was not initialized!");
    }

    while(!exit)
    {
        printf("\n--CIRCULAR QUEUE---------------------");
        printf("\n1. Enqueue\n2. Dequeue\n3. Front\n4. Rear\n5. Exit");
        printf("\nChoose an option: ");
        scanf("%d", &option);

        switch(option)
        {
        case ENQUEUE:
            printf("\nEnter the data to push into queue: ");
            scanf("%d", &data);
            result = enqueue(cqueue, data);
            if(!result)
            {
                printf("\nERROR: Circular queue is full!");
            }
            break;

        case DEQUEUE:
            result = dequeue(cqueue, &data);
            if(!result)
            {
                printf("\nERROR: Circular queue is empty!");
            }
            else
            {
                printf("\nDequeued data: %d", data);
            }
            break;

        case FRONT:
            result = front(cqueue, &data);
            if(!result)
            {
                printf("\nERROR: Circular queue is empty!");
            }
            else
            {
                printf("\nData at front: %d", data);
            }
            break;

        case REAR:
            result = rear(cqueue, &data);
            if(!result)
            {
                printf("\nERROR: Circular queue is empty!");
            }
            else
            {
                printf("\nData at rear: %d", data);
            }
            break;
        
        case EXIT:
            printf("\nExiting the program...");
            exit = true;
            break;

        default:
            printf("\nInvalid option chosen! Please choose from given option(s).");
            break;
        }
    }

    /*  Deinitialize the circular queue  */
    deintialize(cqueue);

    return 0;
}