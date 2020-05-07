/* 
    fibprime.c

    Description:
    Program that determines if a number is fib and prime.
    
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
    int lower, upper, prime, fib, result, range_size;
	double execution_time = 0.0;

    int input;

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

    // Declare array with the proper size.
    range_size = (upper - lower) + 1;

    for(int i = 0; i < range_size; i++){
        fib = isfib(lower);
        if(fib == 1){
            prime = isprime(lower);
            if(prime == 1){
                printf("\n%d is a fib prime number.", lower);
            }
        }      
        lower++;
    }

    clock_t finish = clock();
	execution_time += (double)(finish - start) / CLOCKS_PER_SEC;

	printf("\n\nThis program took %f seconds to execute.\n\n", execution_time);
    return EXIT_SUCCESS;
}