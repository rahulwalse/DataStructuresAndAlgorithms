#include <stdio.h>

#include "linked-list.h"

typedef enum operation operation;

enum operation
{
    ADD_FRONT = 1,
    ADD_END,
    INSERT,
    DELETE_FRONT,
    DELETE_END,
    DELETE,
    PRINT,
    EXIT
};

int main()
{
    /*  Initialize doubly-linked list  */
    linked_list list;
    init_list(&list);

    bool is_running = true;
    bool result = false;
    int data = 0;
    int option = 0;
    size_t pos = 0;

    /*  Display menu options  */
    while(is_running)
    {
        printf("\n--DOUBLY-LINKED LIST-----------------");
        printf("\n1. Add at front\n2. Add at end\n3. Insert\n4. Delete from front");
        printf("\n5. Delete from end\n6. Delete at specified position\n7. Print list");
        printf("\n8. Exit\nChoose an option: ");
        scanf("%d", &option);

        switch (option)
        {
        case ADD_FRONT:
            printf("\nEnter the data: ");
            scanf("%d", &data);
            result = add_front(&list, data);
            if(!result)
            {
                printf("\nERROR: Failed to create and add node to the list!");
            }
            break;
        
        case ADD_END:
            printf("\nEnter the data: ");
            scanf("%d", &data);
            result = add_end(&list, data);
            if(!result)
            {
                printf("\nERROR: Failed to create and add node to the list!");
            }
            break;

        case INSERT:
            printf("\nEnter the position & data to insert into the list");
            printf("\nPosition: ");
            scanf("%zu", &pos);
            printf("Data: ");
            scanf("%d", &data);
            result = insert(&list, data, pos);
            if(!result)
            {
                printf("\nERROR: Failed to create and add node to the list!");
            }
            break;

        case DELETE_FRONT:
            result = delete_front(&list, &data);
            if(!result)
            {
                printf("\nERROR: List is empty!");
            }
            else
            {
                printf("\nRemoved data: %d", data);
            }
            break;

        case DELETE_END:
            result = delete_end(&list, &data);
            if(!result)
            {
                printf("\nERROR: List is empty!");
            }
            else
            {
                printf("\nRemoved data: %d", data);
            }
            break;

        case DELETE:
            printf("\nEnter position of node from list: ");
            scanf("%zu", &pos);
            result = delete_at(&list, &data, pos);
            if(!result)
            {
                printf("\nERROR: List is empty!");
            }
            else
            {
                printf("\nRemoved data: %d", data);
            }
            break;

        case PRINT:
            print_list(&list);
            break;

        case EXIT:
            printf("\nExiting the program...");
            is_running = false;
            break;

        default:
            printf("\nInvalid option chosen! Please choose from provided option(s).");
            break;
        }
    }

    /*  Deinitialize doubly-linked list  */
    deinit_list(&list);

    return 0;
}