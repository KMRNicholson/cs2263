/* 
    fibprime_optimal.c

    Description:
    Program that determines if a number is fib and prime in an optimal way.
    
    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-05-06
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "helpers.h"

int main(int argc, char** argv){
    int lower, upper, input, prime;
    int fib_num, next_fib_num, i, j;
    int arr[255];
	double execution_time = 0.0;

    printf("\nPlease enter a lower range value: ");
    input = scanf("%d", &lower);

    if(input != 1){
        printf("Unable to read the value.\n");
        return 1;
    }

    printf("Now, enter an upper range value: ");
    input = scanf("%d", &upper);

    if(input != 1){
        printf("Unable to read the value.\n");
        return 1;
    }

    clock_t start = clock();

    if(lower > upper){
        printf("Please ensure the lower value is either equal to or lower than the upper value. Exiting...\n\n");
        return EXIT_FAILURE;
    }

    // Initialize array with fib sequence until we surpass the upper value
    fib_num = 0;
    next_fib_num = 1;
    i = 0;
    while(fib_num <= upper){
        arr[i] = fib_num;
        fib_num = next_fib_num;
        next_fib_num += arr[i];
        i++;
    }

    j = 0;
    while(j < i){
        if(arr[j] >= lower){
            prime = isprime(arr[j]);
            if(prime == 1){
                printf("\n%d is a fib prime number.", arr[j]);
            }
        }
        j++;
    }

    clock_t finish = clock();
	execution_time += (double)(finish - start) / CLOCKS_PER_SEC;

	printf("\n\nThis program took %f seconds to execute.\n\n", execution_time);
    return EXIT_SUCCESS;
}