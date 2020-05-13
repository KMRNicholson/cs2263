#include <stdio.h>
#include <stdlib.h>

void clear_row(int a[], int n){
    int i, j;

    i = 0;
    while(i < n){
        a[i] = 0;
        i++;
    }
}

void display_row(int a[], int n){
    int i, j;

    i = 0;
    while(i < n){
        printf("[%d] ", a[i]);
        i++;
    }
}

int main(int argc, char** argcv){
    int i, j;

    int n = 5;
    int arr[n][n];

    printf("\nBefore clearing array:\n");

    i = 0;
    while(i < n){
        printf("\n");
        display_row(arr[i], n);
        clear_row(arr[i], n);
        i++;
    }

    printf("\n\nAfter clearing array:\n");

    i = 0;
    while(i < n){
        printf("\n");
        display_row(arr[i], n);
        i++;
    }


}