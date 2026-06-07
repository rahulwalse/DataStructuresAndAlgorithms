#include "linked-list.h"

#include <stdlib.h>
#include <stdio.h>

void init_list(linked_list* list)
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void deinit_list(linked_list* list)
{
    if(!list) { return; }

    node_t* target = NULL;

    while(list->head)
    {
        target = list->head;
        list->head = list->head->next;
        target->next = NULL;
        target->prev = NULL;
        free(target);
    }

    list->tail = NULL;
    list->size = 0;
}

node_t* create_node(int data)
{
    node_t* new_node = malloc(sizeof(node_t));
    if(!new_node) { return NULL; }

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}

bool add_end(linked_list* list, int data)
{
    if(!list) { return false; }

    node_t* new_node = create_node(data);
    if(!new_node) { return false; }

    if(!list->tail)
    {
        list->head = new_node;
        list->tail = new_node;
    }
    else
    {
        list->tail->next = new_node;
        new_node->prev = list->tail;
        list->tail = new_node;
    }
    list->size++;

    return true;
}

bool add_front(linked_list* list, int data)
{
    if(!list) { return false; }

    node_t* new_node = create_node(data);
    if(!new_node) { return false; }

    if(!list->head)
    {
        list->head = new_node;
        list->tail = new_node;
    }
    else
    {
        list->head->prev = new_node;
        new_node->next = list->head;
        list->head = new_node;
    }
    list->size++;

    return true;
}

bool insert(linked_list* list, int data, size_t pos)
{
    if(!list || pos == 0 || pos > list->size + 1)
    {
        return false;
    }

    bool success = false;

    if(pos == 1)
    {
        success = add_front(list, data);
    }
    else if(pos > list->size)
    {
        success = add_end(list, data);
    }
    else
    {
        node_t* new_node = create_node(data);
        if(!new_node) { return false; }

        size_t mid_pos = (list->size / 2) + 1;

        if(pos <= mid_pos)
        {
            /*  Forward traversal  */
            size_t curr_pos = 1;
            node_t* next_node = list->head;

            while(curr_pos < pos)
            {
                curr_pos++;
                next_node = next_node->next;
            }

            new_node->next = next_node;
            new_node->prev = next_node->prev;
            next_node->prev->next = new_node;
            next_node->prev = new_node;
        }
        else
        {
            /*  Backward traversal  */
            size_t curr_pos = list->size;
            node_t* next_node = list->tail;

            while(curr_pos > pos)
            {
                curr_pos--;
                next_node = next_node->prev;
            }

            new_node->next = next_node;
            new_node->prev = next_node->prev;
            next_node->prev->next = new_node;
            next_node->prev = new_node;
        }
        list->size++;
        success = true;
    }

    return success;
}

bool delete_at(linked_list* list, int* item, size_t pos)
{
    if(!list || !list->head || pos < 1 || pos > list->size)
    {
        return false;
    }

    bool success = false;

    if(pos == 1)
    {
        success = delete_front(list, item);
    }
    else if(pos == list->size)
    {
        success = delete_end(list, item);
    }
    else
    {
        node_t* target_node = NULL;
        size_t mid_pos = (list->size / 2) + 1;

        if(pos <= mid_pos)
        {
            /*  Forward traversal  */
            size_t curr_pos = 1;
            target_node = list->head;

            while(curr_pos < pos)
            {
                curr_pos++;
                target_node = target_node->next;
            }

            target_node->prev->next = target_node->next;
            target_node->next->prev = target_node->prev;
            target_node->prev = NULL;
            target_node->next = NULL;
            *item = target_node->data;
            free(target_node);
            list->size--;
            success = true;
        }
        else
        {
            /*  Backward traversal  */
            size_t curr_pos = list->size;
            target_node = list->tail;

            while(curr_pos > pos)
            {
                curr_pos--;
                target_node = target_node->prev;
            }

            target_node->prev->next = target_node->next;
            target_node->next->prev = target_node->prev;
            target_node->prev = NULL;
            target_node->next = NULL;
            *item = target_node->data;
            free(target_node);
            list->size--;
            success = true;
        }
    }

    return success;
}

bool delete_end(linked_list* list, int* item)
{
    if(!list || !list->tail) { return false; }

    node_t* target = list->tail;
    /*  Special case: one node in list  */
    if(list->head == list->tail)
    {
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
        target->prev = NULL;
    }

    *item = target->data;
    free(target);
    list->size--;

    return true;
}

bool delete_front(linked_list* list, int* item)
{
    if(!list || !list->head) { return false; }

    node_t* target = list->head;
    /*  Special case: one node in list  */
    if(list->head == list->tail)
    {
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        list->head = list->head->next;
        list->head->prev = NULL;
        target->next = NULL;
    }

    *item = target->data;
    free(target);
    list->size--;
    
    return true;
}

void print_list(linked_list* list)
{
    if(!list) { return; }

    node_t* curr_node = list->head;

    printf("\n");
    while(curr_node)
    {
        if(curr_node == list->head)
        {
            printf("[%d]", curr_node->data);
        }
        else
        {
            printf("<-->[%d]", curr_node->data);
        }
        curr_node = curr_node->next;
    }
    printf("\n");
}