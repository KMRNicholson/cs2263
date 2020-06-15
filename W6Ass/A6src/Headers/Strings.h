/* 
    Strings.h

    Description:
    Header file which contains function signatures for a char*.

    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-06-03
*/

#include <stdio.h>

#ifndef STRINGS_H
#define STRINGS_H

// Typedef
typedef char* String;

// mallocs a string
String mallocString(int stringsize);
// free's a string
void freeString(String s);
// deep copies a string
String duplicateString(String s);
// writes a string to a file
int fputString(FILE* pFOut, String s);
// reads a string from file
String fgetString(FILE* pFIn);
// reads a string from stdin
String getString();
// Takes two null pointers to two strings and compares them.
int stringCompare(const void* str1, const void* str2);
// prints a string
void stringToString(String string);

#endif