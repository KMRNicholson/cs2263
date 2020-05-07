/* 
    untittests.c

    Description:
    Tests for the isfib.c function. Mainly testing limits and functionality.
    
    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-05-06
*/

#include <stdio.h>
#include <limits.h>
#include "helpers.h"

int isFibTest(){
    printf("isFibTest(): \t\t\t\t");
    
    int result;
    int param = 13;

    printf("%d\t\t", param);
    
    result = isfib(param);

    if(result != 1){
        printf("FAILED\n");
    }else{
        printf("SUCCESS\n");
    }
}

int isNotFibTest(){
    printf("isNotFibTest(): \t\t\t");
    
    int result;
    int param = 24;

    printf("%d\t\t", param);
    
    result = isfib(param);

    if(result != 0){
        printf("FAILED\n");
    }else{
        printf("SUCCESS\n");
    }
}

int passOnLowerBoundTest(){
    printf("passOnLowerBoundTest(): \t\t");
    
    int result;
    int param = 0;

    printf("%d\t\t", param);
    
    result = isfib(param);

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

    result = isfib(param);

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

    result = isfib(param);

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
    
    result = isfib(param);

    if(result != -1){
        printf("FAILED\n");
    }else{
        printf("SUCCESS\n");
    }
}

int main(int argc, char** argv){
    printf("\n*** Running tests for isfib.c ***\n\n");
    printf("\nNAME\t\t\t\t\tINPUTS\t\tRESULT\n");
    printf("----\t\t\t\t\t------\t\t------\n");

    isFibTest();
    isNotFibTest();
    passOnLowerBoundTest();
    passOnUpperBoundTest();
    failOnGreaterThanIntMaxValueTest();
    failOnNegativeValueTest();

    printf("\n*** Running tests completed! ***\n\n");
    return 0;
}