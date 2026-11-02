#include "binary-search-tree.h"

#include "queue.h"

#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/*  Helper functions.  */
static bool bst_check_recursive(node_t* root, int min_val, int max_val);
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

bool is_binary_search_tree_check(node_t* node)
{
    return bst_check_recursive(node, INT_MIN, INT_MAX);
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

node_t* find_min(node_t* node)
{
    if(!node) { return NULL; }

    /*  Base case: Leaf node in left sub-tree.  */
    if(!node->left) { return node; }

    /*  Recursive case: find min in left sub-tree.  */
    return find_min(node->left);
}

node_t* find_max(node_t* node)
{
    if(!node) { return NULL; }

    /*  Base case: Leaf node in right sub-tree.  */
    if(!node->right) { return node; }

    /*  Recursive case: find max in right sub-tree.  */
    return find_max(node->right);
}

node_t* find_node(node_t* node, int key)
{
    /*  If the tree is empty, return NULL  */
    if(!node) { return NULL; }
    /*  If the key is found, return node  */
    if(node->data == key) { return node; }

    /*
        Recursive case: if the key is less than current node,
        search for key in left sub-tree, otherwise search in
        right sub-tree.
    */
    if(key < node->data)
    {
        return find_node(node->left, key);
    }
    else
    {
        return find_node(node->right, key);
    }
}

node_t* in_order_predecessor(node_t* node, int key)
{
    if(!node) { return NULL; }

    node_t* key_node = find_node(node, key);

    if(!key_node) { return NULL; }

    /*
        If the node does not have left sub-tree, then
        the node does not have predecessor.
    */
    if(!key_node->left) { return NULL; }

    /*
        Node has left sub-tree, find the maximum in the
        left sub-tree.
    */
    return find_max(key_node->left);
}

node_t* in_order_successor(node_t* node, int key)
{
    if(!node) { return NULL; }

    node_t* key_node = find_node(node, key);

    if(!key_node) { return NULL; }

    /*
        If node has right child, find node with minimum element
        in its right sub-tree.
    */
    if(key_node->right)
    {
        return find_min(key_node->right);
    }
    else
    {
        /*  No right child, find the ancestor of the node.  */
        node_t* ancestor_node = node;
        node_t* successor_node = NULL;

        /*
            Traverse from root node to key node, if the 
            element in node is less than root node (ancestor),
            mark the current ancestor as successor and move to
            left sub-tree. Otherwise, move to right sub-tree.
        */
        while(ancestor_node != key_node)
        {
            if(key_node->data < ancestor_node->data)
            {
                successor_node = ancestor_node;
                ancestor_node = ancestor_node->left;
            }
            else
            {
                ancestor_node = ancestor_node->right;
            }
        }
        return successor_node;
    }
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

void delete_node(node_t** node, int key)
{
    /*  Base case: if root is NULL, do nothing.  */
    if(!*node) { return; }

    if(key < (*node)->data)
    {
        /*  Recursive delete call in left sub-tree.  */
        delete_node(&(*node)->left, key);
    }
    else if(key > (*node)->data)
    {
        /*  Recursive delete call in right sub-tree.  */
        delete_node(&(*node)->right, key);
    }
    else
    {
        if(!(*node)->left && !(*node)->right)
        {
            /*  Leaf node.  */
            free(*node);
            *node = NULL;
        }
        else if(!(*node)->left)
        {
            /*  Only right child.  */
            node_t* temp_node = *node;
            *node = (*node)->right;
            temp_node->right = NULL;
            free(temp_node);
        }
        else if(!(*node)->right)
        {
            /*  Only left  child.  */
            node_t* temp_node = *node;
            *node = (*node)->left;
            temp_node->left = NULL;
            free(temp_node);
        }
        else
        {
            /*
                Two children: To Keep the tree balanced after
                deleting a node, find the maximum element in the
                left sub-tree and copy it in current node.
            */
            (*node)->data = find_max((*node)->left)->data;
            /*
                Recursive call to delete node with duplicate element
                from left sub-tree.
            */
            delete_node(&(*node)->left, (*node)->data);
        }
    }
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

void free_tree(node_t* node)
{
    /*  Tree is empty, nothing to delete.  */
    if(!node) { return; }

    /*
        Recursively traverse left & right sub-trees
        to ensure the child nodes  are freed first.
    */
    free_tree(node->left);
    free_tree(node->right);
    /*  Free the current node (parent).  */
    free(node);
}

/*  Helper function definitions  */
static bool bst_check_recursive(node_t* root, int min_val, int max_val)
{
    /*  If root node is NULL, return true  */
    if(!root) { return TRUE; }

    bool is_bst = FALSE;
    int key = root->data;
    /*
        Check if the current element is within range, and then
        recursively check if the elements in left & right sub-trees
        are within range.
    */
    if(key > min_val && key <= max_val
    && bst_check_recursive(root->left, min_val, key)
    && bst_check_recursive(root->right, key, max_val))
    {
        is_bst = TRUE;
    }

    return is_bst;
}

static node_t* create_node(int data)
{
    node_t* new_node = malloc(sizeof(node_t));

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

static int get_max(int num_one, int num_two)
{
    return num_one > num_two ? num_one : num_two;
}