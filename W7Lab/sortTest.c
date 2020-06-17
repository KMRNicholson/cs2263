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

#define SIZE 10

void merge(int arr[], int left, int mid, int right){
    int i = 0;
    int j = 0;
    int k = 0;
    int sizeL = mid - left + 1;
    int sizeR = right - mid;

    int Left[sizeL], Right[sizeR];

    while(i < sizeL){
        Left[i] = arr[left+i];
        i++;
    }

    while(j < sizeR){
        Right[j] = arr[mid+1+j];
        j++;
    }

    i = 0;
    j = 0;
    k = left;
    while(i < sizeL && j < sizeR){
        if(Left[i] <= Right[j]){
            arr[k] = Left[i];
            i++;
        }else{
            arr[k] = Right[j];
            j++;
        }
        k++;
    }

    while(i < sizeL){
        arr[k] = Left[i];
        i++;
        k++;
    }

    while(j < sizeR){
        arr[k] = Right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

void displayArr(int arr[]){
    int i = 0;
    while(i < SIZE){
        printf("%d\n", arr[i]);
        i++;
    }
}

void fillArr(int arr[]){
    int i = 0;
    while(i < SIZE){
        arr[i] = rand() % 20;
        i++;
    }
}

int main(int argc, char** argv){
    int arr[SIZE];

    fillArr(arr);

    printf("Before sorting:\n");
    displayArr(arr);

    mergeSort(arr, 0, SIZE-1);

    printf("After sorting:\n");
    displayArr(arr);

    return EXIT_SUCCESS;
}
