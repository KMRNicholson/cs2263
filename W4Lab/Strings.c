#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// a cover function for malloc()
// malloc and return memory for a string of stringsize characters
// return (char*)NULL on failure
char* mallocString(int stringsize){
    char* newString = (char*)malloc(stringsize);
    return newString;
}

// just a cover function for free()
void freeString(char* s){
    free(s);
}

// create a duplicate string of s
// return it
// return (char*)NULL on failure
// should call mallocString(), and then strcpy()
char* duplicateString(char* s){
    int stringSize = strlen(s) + 1;
    char* sptr = mallocString(stringSize);
    if(sptr != (char*)NULL){
        sptr = strncpy(sptr, s, stringSize);
    }
    return sptr;
}

// writes a string to a file, preceded by it's length
// return 0 on success
// return 1 on failure
int fputString(FILE* pFOut, char* s){
    int stringLength = strlen(s);
    int write = fprintf(pFOut, "%d%s", stringLength, s);

    if(write < 0){
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}

// reads a string which is preceded by its length from a file.
// return pointer to the allocated string in the heap
// return (char*)NULL on failure
char* fgetString(FILE* pFIn){
    int stringLength;
    char* string;

    fscanf(pFIn, "%d", &stringLength); // Scan string length

    string = mallocString(stringLength); // Allocate memory
    if(string != (char*)NULL){
        fgets(string, stringLength, pFIn); // Get the rest of the line
    }

    return string;
}