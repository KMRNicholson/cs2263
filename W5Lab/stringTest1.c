/* 
    stringTest1.c

    Description:
    Program that utilizes various file operations with strings.
    
    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-06-02
*/

#include "Strings.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
    String dupString;

    dupString = duplicateString(argv[0]);
    if(dupString == (String)NULL){
        printf("Failed to allocate memory. Exiting...");
        return EXIT_FAILURE;
    }

    printf("%s", dupString);

    return EXIT_SUCCESS;
}