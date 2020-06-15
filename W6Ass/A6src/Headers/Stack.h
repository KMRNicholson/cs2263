/* 
    Stack.h

    Description:
    Header file which contains function signatures for a stack

    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-06-14
*/

#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include "Point2D.h"
#include "Link.h"

// Struct typedef
typedef struct stack{
    pLink top;
    int size;
} Stack, *pStack;

// Function that mallocs a single List
pStack mallocStack();
// Function that free's a single List
void freeStack(pStack stack);
// Creates a List struct given x and y coordinates
pStack createStack();
// Displays the contents of the list
void readStack(pStack stack);
// Displays the next item in the list.
void peekStack(pStack stack);
// Pops and returns the next item off the stack list
pPoint2D pop(pStack stack);
// Pushing a link onto the stack list
void push(pStack stack, pLink link);
// function that destroys a stack
void destroyStack(pStack stack);

#endif