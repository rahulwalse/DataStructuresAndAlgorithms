#include "binary-search-tree.h"

#include <stdio.h>

int main()
{
    node_t* root_node = NULL;
    insert_node(&root_node, 20);
    insert_node(&root_node, 10);
    insert_node(&root_node, 30);
    insert_node(&root_node, 15);
    insert_node(&root_node, 25);
    insert_node(&root_node, 35);
    insert_node(&root_node, 5);
    insert_node(&root_node, 12);

    bool is_bst = is_binary_search_tree_check(root_node);
    if(is_bst)
    {
        printf("Tree is a binary search tree!\n");
    }
    else
    {
        printf("Tree is not a binary search tree!\n");
    }

    bool found = search(root_node, 30);

    if(found)
    {
        printf("Found!\n");
    }
    else
    {
        printf("Not found!\n");
    }

    int min_element = find_min(root_node);
    int max_element = find_max(root_node);
    int tree_height = find_height(root_node);

    printf("Min: %d, Max: %d, Height: %d", min_element, max_element, tree_height);

    printf("\nBFS: ");
    bfs(root_node);

    printf("\nIn-order Traversal: ");
    in_order(root_node);

    printf("\nPost-order Traversal: ");
    post_order(root_node);

    printf("\nPre-order Traversal: ");
    pre_order(root_node);

    return 0;
}