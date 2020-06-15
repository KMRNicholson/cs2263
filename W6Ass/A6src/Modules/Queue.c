/* 
    Queue.c

    Description:
    Code file which contains function signatures for a queue

    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-06-14
*/

#include <stdio.h>
#include <stdlib.h>
#include "../Headers/Point2D.h"
#include "../Headers/Link.h"
#include "../Headers/Queue.h"

// Function that mallocs a queue
pQueue mallocQueue(){
    return (pQueue)malloc(sizeof(Queue));
}

// Function that free's a queue
void freeQueue(pQueue queue){
    free(queue);
}

// Creates an empty queue
pQueue createQueue(){
    pQueue newQueue = mallocQueue();
    
    if(newQueue != (pQueue)NULL){
        newQueue->front = (pLink)NULL;
        newQueue->back = (pLink)NULL;
        newQueue->size = 0;
    }
    
    return newQueue;
}

// Displays the contents of the queue
void readQueue(pQueue queue){
    if(queue->size > 0){
        readLinks(queue->front);
    }else{
        printf("Queue is empty, nothing to read.\n");
    }
}

// Displays the top of the queue.
void peekQueue(pQueue queue){
    if(queue->size > 0){
        readLink(queue->front);
    }else{
        printf("Queue is empty, nothing to peek.\n");
    }
    
}

// Pops and returns the next item off the queue list
pPoint2D dequeue(pQueue queue){
    pPoint2D item = (pPoint2D)NULL;
    pLink front;
    
    if(queue->size > 0){
        item = duplicatePoint2D(queue->front->point);
        front = queue->front;
        queue->front = queue->front->next;
        queue->size--;
        destroyLink(front);
    }
    
    return item;
}

// Pushing a point onto the queue list
void enqueue(pQueue queue, pLink link){
    if(queue->size == 0){
        queue->front = link;
        queue->back = link;
    }else{
        queue->back->next = link;
        queue->back = link;
    }
    queue->size++;
}

// function that destroys a queue
void destroyQueue(pQueue queue){
    destroyLinks(queue->front);
    freeQueue(queue);
}