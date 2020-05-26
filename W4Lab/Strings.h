#include <stdio.h>

#ifndef STRINGS_H
#define STRINGS_H

// a cover function for malloc()
// malloc and return memory for a string of stringsize characters
// return (char*)NULL on failure
char* mallocString(int stringsize);

// just a cover function for free()
void freeString(char* s);

// create a duplicate string of s
// return it
// return (char*)NULL on failure
// should call mallocString(), and then strcpy()
char* duplicateString(char* s);

// writes a string to a file, preceded by it's length
// return 0 on success
// return 1 on failure
int fputString(FILE* pFOut, char* s);

// reads a string from file.
// return pointer to the allocated string in the heap
// return (char*)NULL on failure
char* fgetString(FILE* pFIn);

#endif