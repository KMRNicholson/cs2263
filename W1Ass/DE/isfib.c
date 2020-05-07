/* 
    isfib.c

    Description:
    Simple function for determine whether or not a given value is part of the fib sequence.
    
    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-05-06
*/

#include <limits.h>
#include <math.h>

int isfib(int number){
    // Check for inputs outside limits.
    if(number < 0 || number > INT_MAX){
        return -1;
    }

    int fibnum = 0;
    int next_fib_num = 1;
    int temp;
    
    while(fibnum <= number){
        if(fibnum == number) return 1;
        temp = fibnum;
        fibnum = next_fib_num;
        next_fib_num += temp;
    }
    
    return 0;
}