// exercisethree.c
#include <stdio.h>
#include <stdlib.h>

int arrindex(int* bp, int* sp){
    return sp - bp;
}

int main (int argc ,char * * argv)
{
  int arr[] = {10, 11, 12, 13, 14, 15, 16};
  int len = sizeof(arr) / sizeof(int); // Get length of array

  for(int i = 0; i < len; i++){
    printf("%d\t%d\n", i, arrindex(&arr[0], &arr[i]));
  }
  return EXIT_SUCCESS;
}
