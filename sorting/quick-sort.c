/*
    Quick Sort Algorithm
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* one, int* two)
{
    int temp = *one;
    *one = *two;
    *two = temp;
}

int partition(int* arr, int start, int end)
{
    /*  Last element as pivot  */
    int pivot = arr[end];
    /*  Partition index from start  */
    int partition_index = start;

    /*  If current element is less than pivot, swap current element at partition index  */
    for(int i = start; i < end; i++)
    {
        if(arr[i] <= pivot)
        {
            swap(&arr[i], &arr[partition_index]);
            partition_index++;
        }
    }
    /*  Insert the pivot into its position  */
    swap(&arr[partition_index], &arr[end]);

    return partition_index;
}

void quick_sort(int* arr, int start, int end)
{
    if(start >= end) { return; }
    /*  Find the partition index  */
    int partition_idx = partition(arr, start, end);
    /*  Recursively call quick sort on left sub-array and right sub-array of partition index  */
    quick_sort(arr, start, partition_idx - 1);
    quick_sort(arr, partition_idx + 1, end);
}

void print(int* arr, int size)
{
    printf("\n[");
    for(int i = 0; i < size; i++)
    {
        if(i == 0)
        {
            printf("%d", arr[i]);
        }
        else
        {
            printf(", %d", arr[i]);
        }
    }
    printf("]\n");
}

int main()
{
    printf("\n---Quick Sort---");
    printf("\nEnter the size of array: ");
    int size = 0;
    scanf("%d", &size);

    if(size <= 0)
    {
        printf("\nInvalid size! Exiting the program...");
        return EXIT_SUCCESS;
    }
    
    /*  Create array  */
    int* arr = malloc(sizeof(int) * size);

    if(!arr)
    {
        printf("\nERROR! Memory allocation failed.");
        return EXIT_FAILURE;
    }

    printf("\nEnter %d values: ", size);
    for(int i = 0; i < size; i++)
    {
        printf("#%d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\nBefore sorting");
    print(arr, size);

    clock_t start_time = clock();
    quick_sort(arr, 0, size - 1);
    double elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;

    printf("\nAfter sorting");
    print(arr, size);

    printf("\nExecution time: %.2f ms", elapsed_time * 1000);

    free(arr);

    return EXIT_SUCCESS;
}