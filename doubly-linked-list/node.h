#ifndef NODE_H
#define NODE_H

typedef struct node_t node_t;

struct node_t
{
    int data;
    node_t* prev;
    node_t* next;
};

#endif