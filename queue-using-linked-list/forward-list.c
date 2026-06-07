#include "forward-list.h"

#include <stdlib.h>

void init_list(forward_list* list)
{
    list->head = NULL;
    list->size = 0;
}

void deinit_list(forward_list* list)
{
    while(list->head)
    {
        node_t* target_node = list->head;
        list->head = list->head->next;
        target_node->next = NULL;
        free(target_node);
    }
    list->size = 0;
}

node_t* create_node(int data)
{
    node_t* new_node = (node_t*)malloc(sizeof(node_t));

    if(!new_node) { return NULL; }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

bool add_at_end(forward_list* list, int data)
{
    if(!list) { return false; }

    node_t* new_node = create_node(data);

    if(!new_node) { return false; }

    if(!list->head)
    {
        list->head = new_node;
    }
    else
    {
        node_t* curr_node = list->head;
        while(curr_node->next)
        {
            curr_node = curr_node->next;
        }
        curr_node->next = new_node;
    }
    list->size++;

    return true;
}

bool add_at_front(forward_list* list, int data)
{
    if(!list) { return false; }

    node_t* new_node = create_node(data);

    if(!new_node) { return false; }

    new_node->next = list->head;
    list->head = new_node;
    list->size++;

    return true;
}

bool insert(forward_list* list, int data, size_t pos)
{
    if(!list || pos == 0 || pos > list->size + 1)
    {
        return false;
    }

    bool result = false;

    if(pos == 1)
    {
        result = add_at_front(list, data);
    }
    else if(pos > list->size)
    {
        result = add_at_end(list, data);
    }
    else
    {
        size_t curr_pos = 1;
        node_t* curr_node = list->head;
        node_t* prev_node = NULL;
        /*  Traverse the list upto specified position  */
        while(curr_pos < pos)
        {
            prev_node = curr_node;
            curr_node = curr_node->next;
            curr_pos++;
        }
        /*  Create new node  */
        node_t* new_node = create_node(data);
        if(!new_node) { return false; }
        /*  Update links  */
        new_node->next = curr_node;
        prev_node->next = new_node;
        list->size++;
        result = true;
    }

    return result;
}

bool delete_at_pos(forward_list* list, int* item, size_t pos)
{
    if(!list || !list->head || pos == 0 || pos > list->size)
    {
        return false;
    }

    bool result = false;

    if(pos == 1)
    {
        result = delete_from_front(list, item);
    }
    else
    {
        size_t curr_pos = 1;
        node_t* target_node = list->head;
        node_t* prev_node = NULL;
        /*  Traverse the list  upto specified position  */
        while(curr_pos < pos)
        {
            prev_node = target_node;
            target_node = target_node->next;
            curr_pos++;
        }
        /*  Update links  */
        prev_node->next = target_node->next;
        target_node->next = NULL;
        /*  Retrieve data  */
        *item = target_node->data;
        free(target_node);

        list->size--;
        result = true;
    }

    return result;
}

bool delete_from_end(forward_list* list, int* item)
{
    if(!list || !list->head) { return false; }

    /*  Special case: single node in list  */
    if(list->size == 1)
    {
        *item = list->head->data;
        free(list->head);
        list->head = NULL;
    }
    else
    {
        node_t* curr_node = list->head;
        node_t* prev_node = NULL;

        while(curr_node->next)
        {
            prev_node = curr_node;
            curr_node = curr_node->next;
        }
        prev_node->next = NULL;
        *item = curr_node->data;
        free(curr_node);
    }
    list->size--;

    return true;    
}

bool delete_from_front(forward_list* list, int* item)
{
    if(!list || !list->head) { return false; }

    node_t* target_node = list->head;
    list->head = list->head->next;

    *item = target_node->data;
    target_node->next = NULL;
    free(target_node);
    list->size--;

    return true;
}

void print(forward_list* list)
{
    if(!list || !list->head) { return; }

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
            printf(" -> [%d]", curr_node->data);
        }
        curr_node = curr_node->next;
    }
    printf("\n");
}

bool reverse_list(forward_list* list)
{
    if(!list || !list->head) { return false; }

    node_t* curr_node = list->head;
    node_t* prev_node = NULL;
    /*  Traverse the list and update links  */
    while(curr_node)
    {
        node_t* next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }
    /*  Update head  */
    list->head = prev_node;

    return true;
}