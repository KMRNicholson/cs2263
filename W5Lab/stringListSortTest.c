/* 
    stringListSortTest.c

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
    int i = 0;
    String* dupList;

    dupList = duplicateStringList(argv, argc-1);
    if(dupList == (String*)NULL){
        printf("Failed to allocate memory. Exiting...");
        return EXIT_FAILURE;
    }

    qsort(dupList, argc-1, sizeof(String), stringCompare);

    i = 0;
    while(i < argc-1){
        printf("%s\n", dupList[i]);
        freeString(dupList[i]);
        i++;
    }

    free(dupList);

    return EXIT_SUCCESS;
}
