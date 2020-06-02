#include <stdio.h>

#ifndef STRINGS_H
#define STRINGS_H

typedef char* String;

// a cover function for malloc()
// malloc and return memory for a string of stringsize characters
// return (char*)NULL on failure
String mallocString(int stringsize);

// just a cover function for free()
void freeString(String s);

// create a duplicate string of s
// return it
// return (char*)NULL on failure
// should call mallocString(), and then strcpy()
String duplicateString(String s);

// create a duplicate list of strings
// return it
// return (char*)NULL on failure
// should call mallocString(), and then strcpy()
String* duplicateStringList(String* s, int listSize);

// writes a string to a file, preceded by it's length
// return 0 on success
// return 1 on failure
int fputString(FILE* pFOut, String s);

// reads a string from file.
// return pointer to the allocated string in the heap
// return (char*)NULL on failure
String fgetString(FILE* pFIn);

// reads a string from stdin
// return pointer to the allocated string
String getString(String input);

// Takes two null pointers to two strings and compares them.
// usable in the qsort() function
// returns 0 if identical
int stringCompare(void* str1, void* str2);

#endif