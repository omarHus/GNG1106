#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* GNG 1106 A: Hw 3 - Printing {0,1}-valued strings */

//Function prototypes
void print_zeros(int user_input);
void print_binary_rep(int user_input, int length);

int main(void)
{
    int n, rows = 0, total_rows;
    printf("Enter an integer\n");
    scanf("%d", &n);
    // number of rows for a given n is 2^n
    total_rows = (int) pow(2, (double) n);

    printf("\nThe binary valued strings for column length %d are: \n", n);
    // print first string entry which is always a string of 0s
    print_zeros(n);
    printf("\n");
    for(rows=1;rows<total_rows;rows++)
    {
        print_binary_rep(rows, n);
        printf("\n");
    }

    return 0;
}

void print_zeros(int user_input)
{
    int i;
    for(i=0;i<user_input;i++)
        printf("0");
}

void print_binary_rep(int user_input, int length)
{
    int out = 0;
    static int counter = 0;
    if (user_input != 0)
    {
        // even numbers
        if(user_input%2 == 0)
        {
            out = 0;
            printf("%d", out);
        }
        // odd numbers
        else
        {
            out = 1;
            printf("%d", out);
        }
        counter++;
        // recursive call
        print_binary_rep(user_input/2, length);
    }
    else
    {
        print_zeros(length-counter);
        counter = 0;
    }
}
