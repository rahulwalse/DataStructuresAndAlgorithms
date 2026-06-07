#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "node.h"

typedef struct stack_t stack_t;

struct stack_t
{
    node_t** data;
    size_t capacity;
    size_t size;
};

stack_t* initialize(int capacity);
void deinitialize(stack_t* stack);

bool peek(stack_t* stack, node_t** item);
bool pop(stack_t* stack, node_t** item);
bool push(stack_t* stack, node_t* item);

bool is_empty(stack_t* stack);
bool is_full(stack_t* stack);

#endif