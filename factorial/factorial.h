#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
    if (n < 0)
    {
        printf("Error\n");
        return n;
    }
    else if (n < 2)
        return 1;
    else
        return n*factorial(n-1);
}

