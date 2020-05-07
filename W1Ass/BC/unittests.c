/* 
    unittests.c

    Description:
    Tests for the isprime.c function. Mainly testing limits and functionality.
    
    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-05-06
*/

#include <stdio.h>
#include <limits.h>
#include "helpers.h"

int isPrimeTest(){
    printf("isPrimeTest(): \t\t\t\t");
    
    int result;
    int param = 13;

    printf("%d\t\t", param);
    
    result = isprime(param);

    if(result != 1){
        printf("FAILED\n");
    }else{
        printf("SUCCESS\n");
    }
}

int isNotPrimeTest(){
    printf("isNotPrimeTest(): \t\t\t");
    
    int result;
    int param = 8;

    printf("%d\t\t", param);
    
    result = isprime(param);

    if(result != 0){
        printf("FAILED\n");
    }else{
        printf("SUCCESS\n");
    }
}

int passOnLowerBoundTest(){
    printf("passOnLowerBoundTest(): \t\t");
    
    int result;
    int param = 1;

    printf("%d\t\t", param);
    
    result = isprime(param);

    if(result != -1){
        printf("SUCCESS\n");
    }else{
        printf("FAILED\n");
    }
}

int passOnUpperBoundTest(){
    printf("passOnUpperBoundTest(): \t\t");

    int result;
    int param = INT_MAX;

    printf("%d\t", param);

    result = isprime(param);

    if(result != -1){
        printf("SUCCESS\n");
    }else{
        printf("FAILED\n");
    }
}

int failOnGreaterThanIntMaxValueTest(){
    printf("failOnGreaterThanIntMaxValueTest(): \t");
    
    int result;
    unsigned int param = UINT_MAX;

    printf("%u\t", param);

    result = isprime(param);

    if(result != -1){
        printf("FAILED\n");
    }else{
        printf("SUCCESS\n");
    }
}

int failOnNegativeValueTest(){
    printf("failOnNegativeValueTest(): \t\t");
    
    int result;
    int param = -42;

    printf("%d\t\t", param);
    
    result = isprime(param);

    if(result != -1){
        printf("FAILED\n");
    }else{
        printf("SUCCESS\n");
    }
}

int failOnZeroValueTest(){
    printf("failOnZeroValueTest(): \t\t\t");
    
    int result;
    int param = 0;

    printf("%d\t\t", param);
    
    result = isprime(param);

    if(result != -1){
        printf("FAILED\n");
    }else{
        printf("SUCCESS\n");
    }
}

int main(int argc, char** argv){
    printf("\n*** Running tests for isprime.c ***\n\n");
    printf("\nNAME\t\t\t\t\tINPUTS\t\tRESULT\n");
    printf("----\t\t\t\t\t------\t\t------\n");

    isPrimeTest();
    isNotPrimeTest();
    passOnLowerBoundTest();
    passOnUpperBoundTest();
    failOnGreaterThanIntMaxValueTest();
    failOnNegativeValueTest();
    failOnZeroValueTest();

    printf("\n*** Running tests completed! ***\n\n");
    return 0;
}