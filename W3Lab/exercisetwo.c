// exercisetwo.c
#include <stdio.h>
#include <stdlib.h>

void print_twice(int arr[], int n){
    int* iptr = arr;
    int i = 0;

    while(i < n){
        printf("\n%d\t%d\t%p\t%d", i, arr[i], iptr, *iptr);
        iptr ++;
        i++;
    }
}

int main (int argc ,char * * argv)
{
  int arr[] = {10, 11, 12, 13, 14, 15, 16};
  int len = sizeof(arr) / sizeof(int);
  
  print_twice(arr, len);

  return EXIT_SUCCESS;
}
