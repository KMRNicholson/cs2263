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

void customSort(void** arr, int arr_size, int (*fun_ptr)(const void* x, const void* y)){
    int i, j, min, result;

    i = 0;
    while(i < arr_size-1){
        min = i;
        j = i + 1;
        while(j < arr_size){
            if((*fun_ptr)(arr[j], arr[min]) < 0){
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
    double x, y;
    int size;
    pPoint2D* pointList;

    if(argc < 2){
        printf("please provide number of points.\n");
        return EXIT_FAILURE;
    }

    size = atoi(argv[1]);

    pointList = mallocPoint2DList(size);
    if(pointList == (pPoint2D*)NULL){
        printf("Failed to allocate memory. Exiting...\n");
        return EXIT_FAILURE;
    }

    while(i < size){
        x = rand() % 100;
        y = rand() % 100;
        pointList[i] = createPoint2D(x, y);
        if(pointList[i] == (pPoint2D)NULL){
            printf("Failed to allocate memory. Exiting..\n");
            return EXIT_FAILURE;
        }
        i++;
    }

    customSort((void**)pointList, size, compareXCoord);

    i = 0;
    while(i < size){
        point2DToString(pointList[i]);
        i++;
    }

    freePoint2DList(pointList, size);

    return EXIT_SUCCESS;
}
