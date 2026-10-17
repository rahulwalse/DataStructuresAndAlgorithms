#include "binary-search-tree.h"

#include "queue.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/*  Helper functions.  */
static node_t* create_node(int data);
static int get_max(int num_one, int num_two);

void bfs(node_t* node)
{
    if(!node) { return; }

    /*
        Calculate the size of queue using the height
        of tree. At any instance, the queue will have
        maximum nodes at level and a current parent node.
        So, size of queue will be 2 to power height + 1.
    */
    int height = find_height(node);
    int size = (int)round(pow(2, height)) + 1;

    queue_t* queue = initialize(size);
    /*  Push the current node on to queue.  */
    push(&queue, node);
    /*
        While there is node to process, push its children
        on the queue.
    */
    while(!is_empty(queue))
    {
        node_t* visited_node = front(queue);
        int element = visited_node->data;
        printf("%d ", element);
        /*
            If the current visited node has children,
            push them on queue.
        */
        if(visited_node->left)
        {
            push(&queue, visited_node->left);
        }
        if(visited_node->right)
        {
            push(&queue, visited_node->right);
        }
        /*  Remove the processed node from queue.  */
        pop(&queue);
    }
    deinitialize(&queue);
}

static node_t* create_node(int data)
{
    node_t* new_node = malloc(sizeof(node_t));

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

int find_height(node_t* node)
{
    /*  Base case: root is NULL. */
    if(!node) { return -1; }

    /*  Recursive case: Scan the left & right sub-trees.  */
    int left_sub_tree_height = find_height(node->left);
    int right_sub_tree_height = find_height(node->right);

    /*  Height is added 1 to maximum from left & right sub trees.  */
    return get_max(left_sub_tree_height, right_sub_tree_height) + 1;
}

int find_min(node_t* node)
{
    if(!node)
    {
        printf("ERROR: Tree is empty!");
        return -1;
    }

    /*  Base case: Value of leaf node in left sub-tree.  */
    if(!node->left) { return node->data; }

    /*  Recursive case: Call min on left sub-tree.  */
    return find_min(node->left);
}

int find_max(node_t* node)
{
    if(!node)
    {
        printf("ERROR: Tree is empty!");
        return -1;
    }

    /*  Base case: Value of leaf node in right sub-tree.  */
    if(!node->right) { return node->data; }

    /*  Recursive case: Call max on right sub-tree.  */
    return find_max(node->right);
}

static int get_max(int num_one, int num_two)
{
    return num_one > num_two ? num_one : num_two;
}

void in_order(node_t* node)
{
    /*  Base case: if the root node is NULL, do nothing.  */
    if(!node) { return; }

    /*
        Recursive case: traverse left sub-tree, process visited
        node and traverse right sub-tree.
    */
    in_order(node->left);
    printf("%d ", node->data);
    in_order(node->right);
}

void post_order(node_t* node)
{
    /*  Base case: if the root node is NULL, do nothing.  */
    if(!node) { return; }

    /*
        Recursive case: traverse to left sub-tree, traverse right
        sub-tree and process visited node.
    */
    post_order(node->left);
    post_order(node->right);
    printf("%d ", node->data);
}

void pre_order(node_t* node)
{
    /*  Base case: if the root node is NULL, do nothing.  */
    if(!node) { return; }

    /*
        Recursive case: process visited node, traverse left sub-tree
        and traverse right sub-tree.
    */
    printf("%d ", node->data);
    pre_order(node->left);
    pre_order(node->right);
}

void insert_node(node_t** node, int data)
{
    /*  Base case: first node in tree.  */
    if(!*node)
    {
        *node = create_node(data);
        return;
    }

    /*
        Recursive case: if element is smaller than element at current
        node, traverse to left sub-tree, if not then to right sub-tree
        for insertion.
    */
    if(data <= (*node)->data)
    {
        insert_node(&(*node)->left, data);
    }
    else
    {
        insert_node(&(*node)->right, data);
    }
}


bool search(node_t* node, int key)
{
    /*
        Base case: If node is empty return false,
        if current element matches key, return true.
    */
    if(!node) { return FALSE; }

    if(node->data == key) { return TRUE; }
    
    /*
        Recursive case: If key is less than current
        element, search left sub-tree, else search
        right sub-tree.
    */
    if(key < node->data)
    {
        return search(node->left, key);
    }
    else
    {
        return search(node->right, key);
    }
}