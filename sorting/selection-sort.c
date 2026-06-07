/*
    Selection Sort Algorithm

    For each pass, finds the index of smallest element and
    swapped with the index of current pass (starting with 0).
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int* arr, int size)
{
    if(!arr || size <= 1) { return; }
    /*  Scan elements except last one  */
    for(int pass = 0; pass < size - 1; pass++)
    {
        int min_idx = pass;
        /*  Compare element with elements in right sub-array  */
        for(int i = pass + 1; i < size; i++)
        {
            if(arr[min_idx] > arr[i]) { min_idx = i; }
        }

        if(min_idx != pass)
        {
            /*  Swap elements  */
            int temp = arr[min_idx];
            arr[min_idx] = arr[pass];
            arr[pass] = temp;
        }
    }
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
    printf("\n---Selection Sort---");
    printf("\nEnter the size of array: ");
    int input_size = 0;
    scanf("%d", &input_size);

    int size = input_size <= 0 ? 0 : input_size;
    if(size == 0)
    {
        printf("\nNothing to sort! Exiting the program...");
        return EXIT_SUCCESS;
    }
    
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
    selection_sort(arr, size);
    double elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;

    printf("\nAfter sorting");
    print(arr, size);

    printf("\nExecution time: %.2f ms", elapsed_time * 1000);

    free(arr);

    return EXIT_SUCCESS;
}