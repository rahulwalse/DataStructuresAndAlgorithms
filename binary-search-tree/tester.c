#include "binary-search-tree.h"

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/**
 * @brief Pre-build a Binary Search Tree.
 * 
 * @param root_node 
 */
void pre_build_tree(node_t** root_node);

int main()
{
    node_t* root_node = NULL;

    bool exit       = FALSE;
    bool success    = FALSE;
    int element     = 0;
    int option      = 0;
    node_t* result  = NULL;
    char pre_build  = 'Y';

    printf("\nDo you want to use a pre-build Binary Search Tree? (Y/N): ");
    scanf("%c", &pre_build);
    if(pre_build == 'y' || pre_build == 'Y')
    {
        pre_build_tree(&root_node);
    }

    /*  Display menu options  */
    while(!exit)
    {
        printf("\n==========Binary Search Tree==========");
        printf("\n1.  Insert Node\n2.  Delete Node\n3.  Search Node");
        printf("\n4.  Height of Tree\n5.  Smallest Element in Tree");
        printf("\n6.  Largest Element in Tree\n7.  In-order Traversal");
        printf("\n8.  Post-order Traversal\n9.  Pre-order Traversal");
        printf("\n10. Find In-order predecessor\n11. Find In-order Successor");
        printf("\n12. Breadth First Search (BFS)\n13. Exit\nChoose an option: ");
        scanf("%d", &option);

        switch(option)
        {
        case 1:
            printf("\nEnter element to insert in tree: ");
            scanf("%d", &element);
            insert_node(&root_node, element);
            break;
        
        case 2:
            printf("\nEnter element to delete from tree: ");
            scanf("%d", &element);
            delete_node(&root_node, element);
            break;

        case 3:
            printf("\nEnter element (key) to find in tree: ");
            scanf("%d", &element);
            success = search(root_node, element);
            if(success)
            {
                printf("\nFound %d in tree!", element);
            }
            else
            {
                printf("\n%d not found in tree!", element);
            }
            break;

        case 4:
            int height = find_height(root_node);
            printf("\nHeight of tree: %d", height);
            break;

        case 5:
            result = find_min(root_node);
            if(result)
            {
                printf("\nSmallest element in tree is %d.", result->data);
            }
            else
            {
                printf("\nTree is empty!");
            }
            break;

        case 6:
            result = find_max(root_node);
            if(result)
            {
                printf("\nLargest element in tree is %d.", result->data);
            }
            else
            {
                printf("\nTree is empty!");
            }
            break;

        case 7:
            printf("\nIn-order: ");
            in_order(root_node);
            break;

        case 8:
            printf("\nPost-order: ");
            post_order(root_node);
            break;

        case 9:
            printf("\nPre-order: ");
            pre_order(root_node);
            break;

        case 10:
            printf("\nEnter element (key) to find its predecessor: ");
            scanf("%d", &element);
            result = in_order_predecessor(root_node, element);
            if(result)
            {
                printf("\nPredecessor of %d is %d.", element, result->data);
            }
            else
            {
                printf("\nNo predecessor found for %d!", element);
            }
            break;

        case 11:
            printf("\nEnter element (key) to find its successor: ");
            scanf("%d", &element);
            result = in_order_successor(root_node, element);
            if(result)
            {
                printf("\nSuccessor of %d is %d.", element, result->data);
            }
            else
            {
                printf("\nNo successor found for %d!", element);
            }
            break;

        case 12:
            printf("\nBreadth First Search (BFS): ");
            bfs(root_node);
            break;

        case 13:
            printf("\nExiting the program...");
            exit = TRUE;
            break;
        
        default:
            printf("\nInvalid option! Please choose from options provided.");
            break;
        }
    }

    return 0;
}

void pre_build_tree(node_t** root_node)
{
    insert_node(root_node, 20);
    insert_node(root_node, 10);
    insert_node(root_node, 30);
    insert_node(root_node, 15);
    insert_node(root_node, 25);
    insert_node(root_node, 35);
    insert_node(root_node, 5);
    insert_node(root_node, 12);
}