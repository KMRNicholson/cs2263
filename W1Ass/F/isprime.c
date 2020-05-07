/* 
    isprime.c

    Description:
    Simple function for determine whether or not a given value is prime
    
    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-05-06
*/

#include <limits.h>

int isprime(int number){
    // Check for inputs outside limits.
    if(number < 1 || number > INT_MAX){
        return -1;
    }

    int divisor = number - 1;
    while(divisor > 1){
        if(number % divisor == 0){
            return 0;
        }

        divisor--;
    }
    return 1;
}