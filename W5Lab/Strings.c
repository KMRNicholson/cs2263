#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef char* String;

// a cover function for malloc()
// malloc and return memory for a string of stringsize characters
// return (String)NULL on failure
String mallocString(int stringsize){
    String newString = (String)malloc(stringsize);
    return newString;
}

// just a cover function for free()
void freeString(String s){
    free(s);
}

// create a duplicate string of s
// return it
// return (String)NULL on failure
// should call mallocString(), and then strcpy()
String duplicateString(String s){
    int stringSize = strlen(s)+1;
    String sptr = mallocString(stringSize);
    if(sptr != (String)NULL){
        sptr = strncpy(sptr, s, stringSize-1);
	    sptr[stringSize-1] = '\0';
    }
    return sptr;
}

// create a duplicate list of strings
// return it
// return (String)NULL on failure
String* duplicateStringList(String* s, int listSize){
    int i = 0;
    String* dupList = (String*)malloc(listSize*sizeof(String));
    if(dupList != (String*)NULL){
        while(i < listSize){
            dupList[i] = duplicateString(s[i+1]);
            i++;
        }
    }
    return dupList;
}

// writes a string to a file, preceded by it's length
// return 0 on success
// return 1 on failure
int fputString(FILE* pFOut, String s){
    int stringLength = strlen(s);
    int write = fprintf(pFOut, "%d%s", stringLength, s);

    if(write < 0){
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}

// reads a string which is preceded by its length from a file.
// return pointer to the allocated string in the heap
// return (String)NULL on failure
String fgetString(FILE* pFIn){
    int stringLength;
    String string;

    fscanf(pFIn, "%d", &stringLength); // Scan string length

    string = mallocString(stringLength); // Allocate memory
    if(string != (String)NULL){
        fgets(string, stringLength+1, pFIn); // Get the rest of the line
    }

    return string;
}

// reads a string from stdin
// return pointer to the allocated string
String getString(String input, int n){
    fgets(input, n-1, stdin);
    return input;
}

// Takes two null pointers to two strings and compares them.
// usable in the qsort() function
// returns 0 if identical
int stringCompare(void* str1, void* str2){
    const String* ptr1 = (String*)str1;
    const String* ptr2 = (String*)str2;
    return strcmp(*ptr1, *ptr2);
}