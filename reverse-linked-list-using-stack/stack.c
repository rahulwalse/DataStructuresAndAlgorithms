#include "stack.h"

#include <stdlib.h>

stack_t* initialize(int capacity)
{
    if(capacity <= 0) { return NULL; }

    stack_t* stack = malloc(sizeof(stack_t));
    
    if(!stack) { return NULL; }

    stack->data = malloc(sizeof(node_t*) * capacity);
    if(!stack->data)
    {
        free(stack);
        return NULL;
    }
    stack->capacity = capacity;
    stack->size = 0;

    return stack;
}

void deinitialize(stack_t* stack)
{
    if(stack && stack->data)
    {
        free(stack->data);
        stack->data = NULL;
        stack->capacity = stack->size = 0;
    }

    if(stack)
    {
        free(stack);
        stack = NULL;
    }
}

bool peek(stack_t* stack, node_t** item)
{
    bool success = false;

    if(!is_empty(stack))
    {
        *item = stack->data[stack->size - 1];
        success = true;
    }

    return success;
}

bool pop(stack_t* stack, node_t** item)
{
    bool success = false;

    if(!is_empty(stack))
    {
        *item = stack->data[stack->size - 1];
        stack->size--;
        success = true;
    }

    return success;
}

bool push(stack_t* stack, node_t* item)
{
    bool success = false;

    if(!is_full(stack))
    {
        stack->data[stack->size] = item;
        stack->size++;
        success = true;
    }

    return success;
}

bool is_empty(stack_t* stack)
{
    return stack->size == 0;
}

bool is_full(stack_t* stack)
{
    return stack->capacity == stack->size;
}