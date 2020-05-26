/* 
    fgetString.c

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
    int eof;
    char* stdString;
    
    FILE* file = fopen(argv[1], "r");
    if(file == (FILE*)NULL){
        printf("Failed to open file. Exiting...");
        return EXIT_FAILURE;
    }

    fseek(file, 0, SEEK_END);
    eof = ftell(file); // Get the file position at the end of the file.
    rewind(file); // reset file position to beginning.
    
    printf("EOF: %d\n", eof);

    //while(ftell(file) != eof){
    //    stdString = fgetString(file);
    //    if(stdString == (char*)NULL){
    //        printf("Failed to allocate memory. Exiting...\n");
    //        return EXIT_FAILURE;
    //    }
    //    printf("%s\n", stdString);
    //    freeString(stdString);
    //}
    
    fclose(file);

    return EXIT_SUCCESS;
}