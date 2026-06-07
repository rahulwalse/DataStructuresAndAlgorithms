#include <stdio.h>

#include "stack.h"

typedef enum operation operation;

enum operation
{
    EXIT    = 4,
    PEEK    = 3,
    POP     = 2,
    PUSH    = 1
};

int main()
{
    /*  Read the stack size  */
    int stack_size = 0;
    printf("\nEnter the stack size: ");
    scanf("%d", &stack_size);

    /*  Initialize stack  */
    stack_t* stack = initialize(stack_size);

    /*  Menu for stack operations  */
    int option  = 0;
    int data    = 0;
    bool exit   = false;
    bool result = false;

    if(!stack)
    {
        exit = true;
        printf("\nFATAL: Stack was not initialized!");
    }

    while(!exit)
    {
        printf("\n--STACK------------------------------");
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Exit");
        printf("\nChoose an option: ");
        scanf("%d", &option);

        switch (option)
        {
        case PUSH:
            printf("\nEnter data to push onto stack: ");
            scanf("%d", &data);
            result = push(stack, data);            
            if(!result)
            {
                printf("\nERROR: Stack is full!");
            }
            break;

        case POP:
            result = pop(stack, &data);
            if(!result)
            {
                printf("\nERROR: Stack is empty!");
            }
            else
            {
                printf("\nPopped data: %d", data);
            }
            break;

        case PEEK:
            result = peek(stack, &data);
            if(!result)
            {
                printf("\nERROR: Stack is empty!");
            }
            else
            {
                printf("\nData at top: %d", data);
            }
            break;

        case EXIT:
            printf("\nExiting the program...\n");
            exit = true;
            break;
        
        default:
            printf("\nInvalid operation chosen! Please choose from given option(s)\n");
            break;
        }
    }

    /*  Deinitialize stack  */
    deinitialize(stack);

    return 0;
}