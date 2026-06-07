/*
    Insertion Sort Algorithm

    The key (starting with second element), is inserted in
    correct position by comparing the elements in left sub-array.
    The elements in left sub-array are shifted right until correct
    position is found.
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int* arr, int size)
{
    if(!arr || size <= 1) { return; }
    /*  Start scanning from second element  */
    for(int i = 1; i < size; i++)
    {
        int key = arr[i];
        int insert_pos = i;
        /*  Find correct position for key and shift elements to right */
        while(insert_pos > 0 && arr[insert_pos - 1] > key)
        {
            arr[insert_pos] = arr[insert_pos - 1];
            insert_pos--;
        }
        arr[insert_pos] = key;
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
    printf("\n---Insertion Sort---");
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
    insertion_sort(arr, size);
    double elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;

    printf("\nAfter sorting");
    print(arr, size);

    printf("\nExecution time: %.2f ms", elapsed_time * 1000);

    free(arr);

    return EXIT_SUCCESS;
}