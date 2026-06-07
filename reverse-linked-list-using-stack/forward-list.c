#include "forward-list.h"

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

void init_list(forward_list* list)
{
    list->head = NULL;
    list->size = 0;
}

void deinit_list(forward_list* list)
{
    while(list->head)
    {
        node_t* target = list->head;
        list->head = list->head->next;
        target->next = NULL;
        free(target);
    }
    list->size = 0;
}

node_t* create_node(int data)
{
    node_t* new_node = malloc(sizeof(node_t));
    if(!new_node) { return NULL; }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

bool add_at_end(forward_list* list, int data)
{
    node_t* new_node = create_node(data);
    if(!new_node) { return false; }
    
    if(!list->head)
    {
        list->head = new_node;
    }
    else
    {
        node_t* last_node = list->head;

        while(last_node->next)
        {
            last_node = last_node->next;
        }

        last_node->next = new_node;
    }
    list->size++;

    return true;
}

bool add_at_front(forward_list* list, int data)
{
    node_t* new_node = create_node(data);
    if(!new_node) { return false; }

    new_node->next = list->head;
    list->head = new_node;
    list->size++;

    return true;
}

bool insert(forward_list* list, int data, int pos)
{
    bool success = false;
    if(!list->head || pos <= 1)
    {
        success = add_at_front(list, data);
    }
    else if(pos > list->size)
    {
        success = add_at_end(list, data);
    }
    else
    {
        uint16_t curr_pos = 1;
        node_t* curr_node = list->head;
        /*  Traverse upto one position before insert position  */
        while(curr_pos < pos - 1)
        {
            curr_node = curr_node->next;
            curr_pos++;
        }
        /*  Insert the new node after node currently pointed  */
        node_t* new_node = create_node(data);
        if(!new_node) { return false;}
        
        new_node->next = curr_node->next;
        curr_node->next = new_node;
        list->size++;
        success = true;
    }

    return success;
}

bool delete_at_pos(forward_list* list, int* item, int pos)
{
    if(!list || !list->head) { return false; }
    
    bool success = false;

    if(pos <= 1)
    {
        success = delete_from_front(list, item);
    }
    else if(pos > list->size)
    {
        success = delete_from_end(list, item);
    }
    else
    {
        uint16_t curr_pos = 1;
        node_t* target = list->head;
        node_t* prev_node = NULL;
        /*  Traverse upto position of target node  */
        while(curr_pos < pos)
        {
            prev_node = target;
            target = target->next;
            curr_pos++;
        }
        /*  Remove links to & from target node  */
        prev_node->next = target->next;
        target->next = NULL;
        *item = target->data;
        free(target);
        success = true;
        list->size--;
    }

    return success;
}

bool delete_from_end(forward_list* list, int* item)
{
    if(!list || !list->head) { return false; }

    bool success = false;

    if(list->size == 1)
    {
        success = delete_from_front(list, item);
    }
    else
    {
        node_t* target = list->head;
        node_t* prev_node = NULL;
        
        while(target->next)
        {
            prev_node = target;
            target = target->next;
        }

        prev_node->next = NULL;
        *item = target->data;
        free(target);
        list->size--;
        success = true;
    }

    return success;
}

bool delete_from_front(forward_list* list, int* item)
{
    bool success = false;
    if(list && list->head)
    {
        node_t* target = list->head;
        list->head = target->next;
        target->next = NULL;
        *item = target->data;
        free(target);
        list->size--;
        success = true;
    }

    return success;
}

void print(forward_list* list)
{
    if(!list->head)
    {
        printf("\nERROR: List is empty!");
        return;
    }

    node_t* curr = list->head;
    printf("\n");
    while(curr)
    {
        if(curr == list->head)
            printf("[%d]", curr->data);
        else
            printf("->[%d]", curr->data);

        curr = curr->next;
    }
    printf("\n");
}

bool reverse_list(forward_list* list)
{
    if(!list || !list->head) { return false; }

    node_t* prev_node = NULL;
    node_t* curr_node = list->head;

    while(curr_node)
    {
        node_t* next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }

    list->head = prev_node;

    return true;
}

bool reverse_list_using_stack(forward_list* list)
{
    if(!list || !list->head) { return false; }

    stack_t* stack = initialize(list->size);

    if(!stack) { return false; }

    /*  Traverse the list and push node addresses onto stack  */
    node_t* curr_node = list->head;
    while(curr_node)
    {
        push(stack, curr_node);
        curr_node = curr_node->next;
    }

    /*  Rearrange the links while popping node addresses from stack  */
    node_t* temp_node = NULL;
    pop(stack, &temp_node);
    /*  Make the last node as head  */
    list->head = temp_node;
    while(!is_empty(stack))
    {
        pop(stack, &temp_node->next);
        temp_node = temp_node->next;
    }
    temp_node->next = NULL;  /*  Set the next of last node to NULL  */

    deinitialize(stack);
    return true;
}