/* 
    stringListSortTest.c

    Description:
    Program that utilizes various file operations with strings.
    
    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-06-16
*/

#include "Headers/Strings.h"
#include "Headers/Point2D.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void** x, void** y){
    void* temp = *x;
    *x = *y;
    *y = temp;
}

void customSort(void** arr, int arr_size, int byte_size, int (*fun_ptr)(const void* x, const void* y)){
    int i, j, min, result;

    i = 0;
    while(i < arr_size-1){
        min = i;
        j = i + 1;
        while(j < arr_size){
            if((*fun_ptr)(&arr[j], &arr[min]) < 0){
                min = j;    
            }
            j++;
        }
        swap(&arr[min], &arr[i]);
        i++;
    }
}

int main(int argc, char** argv){
    int i = 0;
    String* dupList;

    dupList = duplicateStringList(argv, argc-1);
    if(dupList == (String*)NULL){
        printf("Failed to allocate memory. Exiting...");
        return EXIT_FAILURE;
    }

    customSort((void**)dupList, argc-1, sizeof(String), stringCompare);

    i = 0;
    while(i < argc-1){
        printf("%s\n", dupList[i]);
        freeString(dupList[i]);
        i++;
    }

    free(dupList);

    return EXIT_SUCCESS;
}
