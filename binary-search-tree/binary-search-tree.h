#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "node.h"

typedef int bool;
#define TRUE    1
#define FALSE   0

void bfs(node_t* node);
bool is_binary_search_tree_check(node_t* node);

int find_height(node_t* node);
node_t* find_min(node_t* node);
node_t* find_max(node_t* node);
node_t* find_node(node_t* node, int key);

node_t* in_order_predecessor(node_t* node, int key);
node_t* in_order_successor(node_t* node, int key);

void in_order(node_t* node);
void post_order(node_t* node);
void pre_order(node_t* node);

void delete_node(node_t** node, int key);
void insert_node(node_t** node, int data);
bool search(node_t* node, int key);

#endif