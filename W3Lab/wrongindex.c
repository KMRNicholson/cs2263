/*
 * wrongindex.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char * * argv)
{
  int x = -2;
  int arr[] = {0, 1, 2, 3, 4};
  int len = sizeof(arr) / sizeof(int);
  int y = 15;
  int i;
  printf("& x      = %p, & y      = %p\n", & x, & y);

  i = 0;
  while(i < len){
    printf("& arr[%d] = %p\n", i, & arr[i]);
    i++;
  }
  printf("x = %d, y = %d\n", x, y);
  printf("& x      = %p, & y      = %p\n", & x, & y);
  arr[-1] = 7;
  arr[5]  = -23;
  printf("x = %d, y = %d\n", x, y);
  printf("& x      = %p, & y      = %p\n", & x, & y);
  arr[6]  = 108;
  printf("x = %d, y = %d\n", x, y);
  printf("& x      = %p, & y      = %p\n", & x, & y);
  arr[7]  = -353;
  printf("x = %d, y = %d\n", x, y);
  printf("& x      = %p, & y      = %p\n", & x, & y);
  return EXIT_SUCCESS;
}

