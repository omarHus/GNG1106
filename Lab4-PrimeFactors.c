#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PRIME_MAX 1000000

// function prototypes
int isPrime(int user_input);
void print_prime_factors(int user_input);

int main(void)
{
    int user_input, is_prime;
    printf("Enter an integer between 2 and %d\n", PRIME_MAX);
    scanf("%d", &user_input);

    // check if input is within range
    if(user_input<2 || user_input>PRIME_MAX)
        printf("You did not enter an integer in the required range.\n");
    else
    {
        // determine whether number is prime
        is_prime = isPrime(user_input);

        if(is_prime)
        {
            printf("The number %d is prime!\n", user_input);
        }
        else
        {
            printf("The number %d is not prime!\n", user_input);
            printf("%d = ", user_input);
            // call the function to print prime factors of our input when not prime
            print_prime_factors(user_input);
        }
    }
    return 0;
}

int isPrime(int user_input)
{
    int i, is_prime = 1;

    for(i=2;i<user_input; i++)
    {
        // if any number factors into our input then it is not a prime
        if(user_input%i == 0)
        {
            // not a prime
            is_prime = 0;
            break;
        }
    }

    return is_prime;
}

void print_prime_factors(int user_input)
{
    int divisor, number, counter;
    number = user_input;
    divisor = 2;
    counter = 0;

    while(number > 1)
    {
        // check if divisor is a prime factor
        if(number%divisor == 0)
        {
            // checking counter in order to place multiplication sign ("x") in the correct spot
            if(counter == 0)
                printf("%d", divisor);
            else
                printf("x%d", divisor);
            // divide our number by the divisor to generate the next factor
            number = number/divisor;
            counter++;
        }
        else
            divisor++;
    }
}
