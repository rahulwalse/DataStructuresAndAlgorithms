/*
    This is an example of recursion with memoization.
    Compared with iterative implementation it still has
    higher memory complexity.
*/

#include <stdio.h>
#include <time.h>

int f[51];

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

int fibonacci_memoized(int num)
{
    if(num <= 1)
    {
        return num;
    }
    else if(f[num] != -1)
    {
        return f[num];
    }

    f[num] = fibonacci_memoized(num - 1) + fibonacci_memoized(num - 2);
    return f[num];
}

int main()
{
    for(int i = 0; i < 51; i++)
    {
        f[i] = -1;
    }

    printf("\nEnter number: ");
    int num = 0;
    scanf("%d", &num);

    int result = 0;
    double elapsed_time = 0;
    clock_t start;

    /*  Iterative  */
    start  = clock();    
    result = fibonacci_iterative(num);
    elapsed_time = (double)(clock() - start) / CLOCKS_PER_SEC;

    printf("\nfibonacci_iterative(%d) = %d, execution time: %.2f seconds.", num, result, elapsed_time);

    /*  Recursive memoized  */
    start  = clock();    
    result = fibonacci_memoized(num);
    elapsed_time = (double)(clock() - start) / CLOCKS_PER_SEC;

    printf("\nfibonacci_memoized(%d) = %d, execution time: %.2f seconds.", num, result, elapsed_time);

    return 0;
}