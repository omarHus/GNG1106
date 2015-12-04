#include <stdio.h>
#include <stdlib.h>

/* GNG1106A - HW4-Q8 - getEvenNumbers: write a function that takes an array as input and returns the even numbers */

int *getEvenNumbers(int *ptr2ArrayElements, int array_length);

int main(void)
{
    int N, i;
    int *even_array=NULL;

    printf("Enter a positive integer.\n");
    scanf("%d", &N);

    srand(N);
    int myArray[N];

    // Fill the array with random values
    printf("The original array is:\n");
    for(i=0;i<N;i++)
    {
        myArray[i]=rand()%100;
        printf("\t%d", myArray[i]);
    }
    printf("\n");

    // call function to get the even numbers in our array
    even_array = getEvenNumbers(myArray, N);

    // if the function call worked print the array of even numbers
    if(even_array)
    {
        printf("The array of even numbers is:\n");
        for(i=0;i<N;i++)
        {
            if(*(even_array+i) != 0)
            {
                printf("\t%d", *(even_array+i));
            }
        }
        printf("\n");
    }

    free(even_array);
    return 0;
}

int *getEvenNumbers(int *arrayIn, int array_length)
{
    int *out=NULL;
    int i, j=0;

    // allocate memory to copy value of even numbers from arrayIn
    out = (int *)malloc(array_length*sizeof(int));

    if(out)
    {
        // find the even numbers in the arrayIn and copy those to out
        for(i=0;i<array_length;i++)
        {
            while(j<array_length)
            {
                if(arrayIn[j]%2==0)
                {
                    out[i]=arrayIn[j];
                    j++;
                    break;
                }
                j++;
            }
        }
    }
    else
    {
        printf("Memory allocation failed!\n");
    }

    return out;
}
