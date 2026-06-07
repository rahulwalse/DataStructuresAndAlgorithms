/*
    Merge Sort Algorithm
    
    This algorithm uses divide-and-conquer strategy, dividing
    the arrays into halfs and call the merge sort recursively on
    the sub arrays.
    Then merging the sub-arrays by comparing elements from each sub-array
    and inserting elements in order (ascending).
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void merge_arr(int* merge_arr, int* left_arr, int left_arr_size, int* right_arr, int right_arr_size)
{
    int left_idx     = 0;
    int right_idx    = 0;
    int index        = 0;
    /*  Compare the elements in left & right sub-arrays and merge in order  */
    while(left_idx < left_arr_size && right_idx < right_arr_size)
    {
        if(left_arr[left_idx] <= right_arr[right_idx])
        {
            merge_arr[index] = left_arr[left_idx];
            left_idx++;
        }
        else
        {
            merge_arr[index] = right_arr[right_idx];
            right_idx++;
        }
        index++;
    }

    /*  Copy the remaining elements (if any) from left and right sub-array  */
    while(left_idx < left_arr_size)
    {
        merge_arr[index] = left_arr[left_idx];
        left_idx++;
        index++;
    }

    while(right_idx < right_arr_size)
    {
        merge_arr[index] = right_arr[right_idx];
        right_idx++;
        index++;
    }
}

void merge_sort(int* arr, int size)
{
    if(size <= 1) { return; }

    /*  Compute mid of array  */
    int mid_index        = size / 2;
    int left_arr_size    = mid_index;
    int right_arr_size   = size - mid_index;

    /*  Create left and right sub-arrays and exit if allocation fails  */
    int* left_arr = malloc(sizeof(int) * left_arr_size);
    int* right_arr = malloc(sizeof(int) * right_arr_size);
    if(!left_arr || !right_arr)
    {
        free(left_arr);
        free(right_arr);
        exit(EXIT_FAILURE);
    }

    /*  Copy elments from left and right sub-array into new left and right arrays respectively  */
    for(int i = 0; i < left_arr_size; i++)
    {
        left_arr[i] = arr[i];
    }
    for(int i = mid_index; i < size; i++)
    {
        right_arr[i - mid_index] = arr[i];    /*  Subtract mid from i to get current index  */
    }

    /*  Call merge sort recursively to further divide left and right sub-arrays respectively  */
    merge_sort(left_arr, left_arr_size);
    merge_sort(right_arr, right_arr_size);
    merge_arr(arr, left_arr, mid_index, right_arr, right_arr_size);
    /*  Free memory for left and right sub-arrays  */
    free(left_arr);
    free(right_arr);
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
    printf("\n---Merge Sort---");
    printf("\nEnter the size of array: ");
    int input_size = 0;
    scanf("%d", &input_size);

    if(input_size <= 0)
    {
        printf("\nInvalid size! Exiting the program...");
        return EXIT_SUCCESS;
    }
    int size = (int)input_size;
    
    /*  Create array  */
    int* arr = malloc(sizeof(int) * size);

    if(!arr)
    {
        printf("\nERROR! Memory allocation failed.");
        return EXIT_FAILURE;
    }

    printf("\nEnter %zd values: ", size);
    for(int i = 0; i < size; i++)
    {
        printf("#%zd: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\nBefore sorting");
    print(arr, size);

    clock_t start_time = clock();
    merge_sort(arr, size);
    double elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;

    printf("\nAfter sorting");
    print(arr, size);

    printf("\nExecution time: %.2f ms", elapsed_time * 1000);

    free(arr);

    return EXIT_SUCCESS;
}