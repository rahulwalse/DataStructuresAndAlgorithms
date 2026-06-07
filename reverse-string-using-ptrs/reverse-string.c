#include <stdio.h>
#include <string.h>
#include <time.h>

void reverse_string(char* arr, int size);

int main()
{
    char str[51];
    printf("\nEnter string: ");
    scanf("%s", str);

    printf("\nString: %s", str);

    clock_t start_time = clock();
    reverse_string(str, strlen(str));
    double execution_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;
    printf("\nReverse string: %s\nExecution Time: %.2f", str, execution_time);    

    return 0;
}

void reverse_string(char* arr, int size)
{
    if(!arr || size <= 1) { return; }

    int left = 0;
    int right = size - 1;

    while(left < right)
    {
        char temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
}