/*
    Bubble sort algorithm.

    It compares adjacent elements in each pass and swaps the elements.
    At the end of each pass the largest (or smallest depending on order)
    bubbles out to the end of array.
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int* arr, int size)
{
    if(!arr || size <= 1) { return; }

    int array_size = size;

    /*
        After each pass, last element will be in its sorted place, hence
        passes will be one less than the size of array.
    */
    for(int pass = 1; pass <= size - 1; pass++)
    {
        /*
            Scan & compare adjacent elements in updated sub-array for
            each pass.
        */
        for(int idx = 0; idx < array_size - 1; idx++)
        {
            if(arr[idx] > arr[idx + 1])
            {
                int temp = arr[idx];
                arr[idx] = arr[idx + 1];
                arr[idx + 1] = temp;
            }
        }
        /*  Reduce the size of sub-array for next pass.  */
        array_size--;
    }
}

void print_arr(int* arr, int size)
{
    printf("[");
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
    printf("\n---Bubble Sort---");
    printf("\nEnter the number of elements to be sorted: ");
    int input_size = 0;
    scanf("%d", &input_size);

    int size = input_size <= 0 ? 0 : input_size;
    if(size == 0)
    {
        printf("\nNothing to sort! Exiting the program...");
        return EXIT_SUCCESS;
    }

    int* arr = malloc(sizeof(int) * size);
    
    if(!arr)
    {
        printf("\nERROR! Memory allocation failed.");
        return EXIT_FAILURE;
    }

    printf("\nEnter the %zd numbers: ", size);
    for(int i = 0; i < size; i++)
    {
        printf("#%zd: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nElements before sorting:\n");
    print_arr(arr, size);

    bubble_sort(arr, size);

    printf("\nElements after sorting:\n");
    print_arr(arr, size);

    free(arr);

    return EXIT_SUCCESS;
}