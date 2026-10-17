#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "node.h"

typedef int bool;
#define TRUE    1
#define FALSE   0

void bfs(node_t* node);

int find_height(node_t* node);
int find_min(node_t* node);
int find_max(node_t* node);

void in_order(node_t* node);
void post_order(node_t* node);
void pre_order(node_t* node);

void insert_node(node_t** node, int data);
bool search(node_t* node, int key);

#endif