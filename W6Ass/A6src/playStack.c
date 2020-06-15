// playStack.c
#include <stdio.h>
#include <stdlib.h>
#include "Headers/Stack.h"
#include "Headers/Link.h"
#include "Headers/Point2D.h"

#define PUSH 1
#define POP 0
#define LIST 2
#define PEEK 3

int main(int argc, char* argv[])
{
  int iChoice;
  int iNRead;
  double x, y;
  pPoint2D point;
  pLink link;
  pStack stack = createStack();

  /* Processing loop */
  printf("Choice (1=add, 0=remove, 2=list, 3=peek): ");
  iNRead = scanf("%d", &iChoice);
  while(iNRead == 1)
  {
    switch(iChoice)
    {
      case PUSH:
        printf("Point value to add: "); // Obviously you need to read the x and y values
        // Read the element, add it to the stack
        scanf("%lf %lf", &x, &y);
        
        point = createPoint2D(x, y);
        if(point == (pPoint2D)NULL){
          printf("Failed to allocate memory. Exiting..");
          return EXIT_FAILURE;    
        }

        link = createLink(point);
        if(link == (pLink)NULL){
          printf("Failed to allocate memory. Exiting..");
          return EXIT_FAILURE;    
        }

        push(stack, link);
      break;
      case POP:
        // Pop the Point2D and print it out.
        point = pop(stack);
        if(point != (pPoint2D)NULL){
          point2DToString(point);
          freePoint2D(point);
        }else{
          printf("Stack is empty, nothing to pop.\n");
        }
      break;
      case LIST:
        // Print out the stack elements
        readStack(stack);
      break;
      case PEEK:
        // Print out the next value to be popped.
        peekStack(stack);
      break;
      default: 
        return 0;
    }
    printf("\nChoice (1=add, 0=remove, 2=list, 3=peek): ");
    iNRead = scanf("%d", &iChoice);
  }
  destroyStack(stack);
  return EXIT_SUCCESS;
}
