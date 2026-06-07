#include <stdio.h>
#include <string.h>
#include <time.h>

#include "stack.h"

void reverse_using_stack(char* arr, int size);

int main()
{
    char str[50];
    printf("\nEnter string: ");
    scanf("%s", str);

    int size = strlen(str);

    printf("\nString: %s", str);
    clock_t start_time = clock();
    reverse_using_stack(str, size);
    double execution_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;
    printf("\nReversed string: %s\nExecution Time: %.2f", str, execution_time);

    return 0;
}

void reverse_using_stack(char* arr, int size)
{
    stack_t* stack = initialize(size);

    /*  Store characters on stack  */
    for(int i = 0; i < size; i++)
    {
        push(stack, arr[i]);
    }

    /*  Reverse the string popping characters from stack  */
    for(int i = 0; i < size; i++)
    {
        pop(stack, &arr[i]);
    }

    deinitialize(stack);    
}