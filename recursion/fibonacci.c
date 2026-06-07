/*
    This program is an example of recursion being inefficient and
    when it should not be used.
    
    Here in this example, for calculating nth Fibonacci number
    using recursion there are many redundant recursive calculations
    -- called recursive tree -- increasing time complexity dramatically
    for larger number.

    In case of iterative approach, each fibonacci number is calculated
    only once making it efficient and faster.
*/

#include <stdio.h>
#include <time.h>

int fibonacci_iterative(int num)
{
    int f1 = 0;
    int f2 = 1;
    int result = 0;

    for(int i = 2; i <= num; i++)
    {
        result = f1 + f2;
        f1 = f2;
        f2 = result;
    }

    return result;
}

int fibonacci_recursive(int num)
{
    /*  Base case  */
    if(num <= 1)
    {
        return num;
    }
    /*  Recursive case  */
    return fibonacci_recursive(num - 2) + fibonacci_recursive(num - 1);
}

int main()
{
    printf("\nEnter number: ");
    int num = 0;
    scanf("%d", &num);

    int result = 0;

    clock_t start;
    double elapsed_time = 0;

    /*  Iterative  */
    start = clock();
    result = fibonacci_iterative(num);
    elapsed_time = (double)(clock() - start) / CLOCKS_PER_SEC;
    
    printf("\nfibonacci_iterative(%d) = %d, execution time: %.2f seconds.\n", num, result, elapsed_time);

    /*  Recursive  */
    start = clock();
    result = fibonacci_recursive(num);
    elapsed_time = (double)(clock() - start) / CLOCKS_PER_SEC;
    
    printf("\nfibonacci_recursive(%d) = %d, execution time: %.2f seconds.\n", num, result, elapsed_time);

    return 0;
}