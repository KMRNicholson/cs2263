/* 
    LinkedList.h

    Description:
    Code file which contains functions for a Linked List

    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-06-14
*/

#include <stdio.h>
#include <stdlib.h>
#include "../Headers/Point2D.h"
#include "../Headers/Link.h"

/* private functions */

// Function that mallocs a link
pLink mallocLink(){
    return (pLink)malloc(sizeof(Link));
}


/* public functions */

// Creates an empty list
pLink createLink(pPoint2D point){
    pLink newLink = mallocLink();

    if(newLink != (pLink)NULL){
        newLink->point = point;
        newLink->next = (pLink)NULL;
    }

    return newLink;
}

void readLink(pLink link){
    printf("\nLink address: %p\n", link);
    printf("Link values:\n");
    printf("point\ttype: Point2D\tval:\n");
    point2DToString(link->point);
    printf("Next link address: %p\n", link->next);
}

void readLinks(pLink link){
    if(link != (pLink)NULL){
        readLinks(link->next);
        readLink(link);
    }   
}

void destroyLink(pLink link){
    freePoint2D(link->point);
    free(link);
}

void destroyLinks(pLink link){
    if(link != (pLink)NULL){
        destroyLinks(link->next);
        destroyLink(link);
    }
}