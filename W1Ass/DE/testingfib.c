/* 
    testingfib.c

    Description:
    Tests for the user for isfib().
    
    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-05-06
*/

#include <stdio.h>
#include <limits.h>
#include "helpers.h"

int main(int argc, char** argv){
    int val;
    int result;
    int input;

    printf("\nPlease enter a value: ");
    input = scanf("%d", &val);

    if(input != 1){
        printf("Unable to read the value.\n");
        return 1;
    }

    result = isfib(val);

    switch (result){
        case 0:
            printf("%d is not a fib number.\n\n", val);
            break;
        case 1:
            printf("%d is a fib number.\n\n", val);
            break;
        case -1:
            printf("Invalid input. Please enter a valid integer.\n\n");
            break;
        default:
            break;
    }

    return 0;
}