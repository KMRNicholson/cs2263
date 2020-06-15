// playQueue.c
#include <stdio.h>
#include <stdlib.h>
#include "Headers/Queue.h"
#include "Headers/Link.h"
#include "Headers/Point2D.h"

#define ENQUEUE 1
#define DEQUEUE 0
#define LIST 2
#define PEEK 3

int main(int argc, char * * argv)
{
  int iChoice;
  int iNRead;
  double x, y;
  pPoint2D point;
  pLink link;
  pQueue queue = createQueue();

  /* Processing loop */
  printf("Choice (1=enqueue, 0=dequeue, 2=list, 3=peek): ");
  iNRead = scanf("%d", &iChoice);
  while(iNRead == 1)
  {
    switch(iChoice)
    {
      case ENQUEUE:
        printf("Point value to add: "); // Obviously you need to read the x and y values
        // Read the element, add it to the queue
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

        enqueue(queue, link);
      break;
      case DEQUEUE:
        // dequeue the Point2D and print it out.
        point = dequeue(queue);
        if(point != (pPoint2D)NULL){
          point2DToString(point);
          freePoint2D(point);
        }else{
          printf("Queue is empty, nothing to dequeue.\n");
        }
      break;
      case LIST:
        // Print out the queue elements
        readQueue(queue);
      break;
      case PEEK:
        // Print out the next value to be popped.
        peekQueue(queue);
      break;
      default: 
        return 0;
    }
    printf("\nChoice (1=enqueue, 0=dequeue, 2=list, 3=peek): ");
    iNRead = scanf("%d", &iChoice);
  }
  destroyQueue(queue);
  return EXIT_SUCCESS;
}
