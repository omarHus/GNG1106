#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PRIME_MAX 1000000

int main(void)
{
    int user_input, i, isPrime = 1;
    printf("Enter an integer between 2 and %d\n", PRIME_MAX);
    scanf("%d", &user_input);

    // check if input is within range
    if(user_input<2 || user_input>PRIME_MAX)
        printf("You did not enter an integer in the required range.\n");
    else
    {
        for(i=1;i<user_input/2;i++)
        {
            while (user_input!= 0)
            {
                if(user_input%i==0)
                {
                    printf("%d", i);
                    user_input=user_input/2;
                    isPrime++;
                }
            }
        }
        if(is_prime==1)
        {
            printf("The number %d is prime!\n", user_input);
        }
        else
        {
            printf("The number %d is not prime!\n", user_input);
        }
    }
    return 0;
}

