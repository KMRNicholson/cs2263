/* 
    Queue.h

    Description:
    Header file which contains function signatures for a Queue

    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-06-14
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include "Point2D.h"
#include "Link.h"

// Struct typedef
typedef struct queue{
    pLink front;
    pLink back;
    int size;
} Queue, *pQueue;

// Function that mallocs a single List
pQueue mallocQueue();
// Function that free's a single List
void freeQueue(pQueue Queue);
// Creates a List struct given x and y coordinates
pQueue createQueue();
// Displays the contents of the list
void readQueue(pQueue Queue);
// Displays the next item in the list.
void peekQueue(pQueue Queue);
// Pops and returns the next item off the Queue list
pPoint2D dequeue(pQueue Queue);
// Pushing a link onto the Queue list
void enqueue(pQueue Queue, pLink link);
// function that destroys a Queue
void destroyQueue(pQueue Queue);

#endif