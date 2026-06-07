#include <stdio.h>

int factorial(int num)
{
    printf("Computing factorial(%d)\n", num);
    /*  Base case  */
    if(num == 0)
    {
        return 1;
    }
    /*  Recursive case  */
    int fact =  num * factorial(num - 1);
    printf("Computed factorial(%d) = %d\n", num, fact);
    return fact;
}

int main()
{
    printf("\nEnter number: ");
    int num = 0;
    scanf("%d", &num);

    printf("%d! = %d", num, factorial(num));

    return 0;
}