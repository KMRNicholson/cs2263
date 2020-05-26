/* 
    fputString.c

    Description:
    Program that utilizes various file operations with strings.
    
    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-05-26
*/

#include "Strings.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
    int n = 100;
    int i = 0;
    char stdString[n];
    
    FILE* file = fopen(argv[1], "w");
    if(file == (FILE*)NULL){
        printf("Failed to open file. Exiting..");
        return EXIT_FAILURE;
    }

    while(i < 2){
        fgets(stdString, n-1, stdin);
        fputString(file, stdString);
        i++;
    }

    return EXIT_SUCCESS;
}