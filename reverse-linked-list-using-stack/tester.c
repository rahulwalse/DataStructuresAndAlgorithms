#include <stdbool.h>
#include <stdio.h>

#include "forward-list.h"

typedef enum operation operation;

enum operation
{
    ADD_AT_FRONT = 1,
    ADD_AT_END,
    INSERT,
    DELETE_FRONT,
    DELETE_END,
    DELETE,
    REVERSE,
    REVERSE_STACK,
    PRINT,
    EXIT
};

int main()
{
    /*  Declare and initialize linked list  */
    forward_list list;
    init_list(&list);

    bool is_running = true;
    bool result = false;
    int data = 0;
    int option = 0;
    int pos = 0;

    while(is_running)
    {
        printf("\n--SINGLY LINKED LIST-----------------");
        printf("\n1. Add at front\n2. Add at end\n3. Insert\n4. Delete from front");
        printf("\n5. Delete from end\n6. Delete at specified position\n7. Reverse list");
        printf("\n8. Reverse List using Stack\n9. Print list\n10. Exit");
        printf("\nChoose an option: ");
        scanf("%d", &option);

        switch(option)
        {
        case ADD_AT_FRONT:
            printf("\nEnter the data to add at front of list: ");
            scanf("%d", &data);
            result = add_at_front(&list, data);
            if(!result)
            {
                printf("\nERROR: Could not create and add node to list!");
            }
            break;

        case ADD_AT_END:
            printf("\nEnter the data to add at end of list: ");
            scanf("%d", &data);
            result = add_at_end(&list, data);
            if(!result)
            {
                printf("\nERROR: Could not create and add node to list!");
            }
            break;

        case INSERT:
            printf("\nEnter the data and position to insert the data in list:\n");
            printf("Data: ");
            scanf("%d", &data);
            printf("Position: ");
            scanf("%d", &pos);
            result = insert(&list, data, pos);
            if(!result)
            {
                printf("\nERROR: Could not create and add node to list!");
            }
            break;

        case DELETE_FRONT:
            result = delete_from_front(&list, &data);
            if(!result)
            {
                printf("\nERROR: List is empty!");
            }
            else
            {
                printf("\nRemoved %d from the list", data);
            }
            break;

        case DELETE_END:
            result = delete_from_end(&list, &data);
            if(!result)
            {
                printf("\nERROR: List is empty!");
            }
            else
            {
                printf("\nRemoved %d from the list", data);
            }
            break;

        case DELETE:
            printf("\nEnter the position of node to delete from the list: ");
            scanf("%d", &pos);
            result = delete_at_pos(&list, &data, pos);
            if(!result)
            {
                printf("\nERROR: List is empty!");
            }
            else
            {
                printf("\nRemoved %d from position %d in the list", data, pos);
            }
            break;

        case REVERSE:
            result = reverse_list(&list);
            if(!result)
            {
                printf("\nERROR: Failed to reverse the list!");
            }
            break;

        case REVERSE_STACK:
            result = reverse_list_using_stack(&list);
            if(!result)
            {
                printf("\nERROR: Failed to reverse the list!");
            }
            break;

        case PRINT:
            print(&list);
            break;

        case EXIT:
            is_running = false;
            printf("\nExiting the program...");
            break;
        
        default:
            printf("\nInvalid option chosen! Please choose from given option(s).");
            break;
        }
    }

    /*  Deinitialize the linked list  */
    deinit_list(&list);

    return 0;
}