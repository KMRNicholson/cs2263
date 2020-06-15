/* 
    Strings.c

    Description:
    Code file which contains function for a char*.

    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-06-08
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../Headers/Strings.h"

// mallocs a string
String mallocString(int stringsize){
    String newString = (String)malloc(stringsize);
    return newString;
}

// free's a string
void freeString(String s){
    free(s);
}

// deep copies a string
String duplicateString(String s){
    int stringSize = strlen(s);
    String sptr = mallocString(stringSize+1);
    if(sptr != (String)NULL){
        sptr = strncpy(sptr, s, stringSize);
	    sptr[stringSize] = '\0';
    }
    return sptr;
}

// writes a string to a file
int fputString(FILE* pFOut, String s){
    int stringLength = strlen(s);
    int write = fprintf(pFOut, "%d%s", stringLength, s);

    if(write < 0){
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}

// reads a string from file
String fgetString(FILE* pFIn){
    char fileInput[255];
    String string;
    fscanf(pFIn, "%[^\n]", fileInput);
    string = duplicateString(fileInput);
    return string;
}

// reads a string from stdin
String getString(){
    char input[255];
    String string;
    scanf("%[^\n]", input);
    string = duplicateString(input);
    return string;
}

// Takes two null pointers to two strings and compares them.
int stringCompare(const void* str1, const void* str2){
    const String* ptr1 = (String*)str1;
    const String* ptr2 = (String*)str2;
    return strcmp(*ptr1, *ptr2);
}

// prints a string
void stringToString(String string){
    printf("%s", string);
}