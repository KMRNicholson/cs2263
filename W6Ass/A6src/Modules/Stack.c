/* 
    Stack.c

    Description:
    Code file which contains function signatures for a stack

    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-06-14
*/

#include <stdio.h>
#include <stdlib.h>
#include "../Headers/Point2D.h"
#include "../Headers/Link.h"
#include "../Headers/Stack.h"

// Function that mallocs a stack
pStack mallocStack(){
    return (pStack)malloc(sizeof(Stack));
}

// Function that free's a stack
void freeStack(pStack stack){
    free(stack);
}

// Creates an empty stack
pStack createStack(){
    pStack newStack = mallocStack();
    
    if(newStack != (pStack)NULL){
        newStack->top = (pLink)NULL;
        newStack->size = 0;
    }
    
    return newStack;
}

// Displays the contents of the stack
void readStack(pStack stack){
    if(stack->size > 0){
        readLinks(stack->top);
    }else{
        printf("Stack is empty, nothing to read.\n");
    }
}

// Displays the top of the stack.
void peekStack(pStack stack){
    if(stack->size > 0){
        readLink(stack->top);
    }else{
        printf("Stack is empty, nothing to peek.\n");
    }
    
}

// Pops and returns the next item off the stack list
pPoint2D pop(pStack stack){
    pPoint2D item = (pPoint2D)NULL;
    pLink top;
    
    if(stack->size > 0){
        item = duplicatePoint2D(stack->top->point);
        top = stack->top;
        stack->top = stack->top->next;
        stack->size--;
        destroyLink(top);
    }
    
    return item;
}

// Pushing a point onto the stack list
void push(pStack stack, pLink link){
    link->next = stack->top;
    stack->top = link;
    stack->size++;
}

// function that destroys a stack
void destroyStack(pStack stack){
    destroyLinks(stack->top);
    freeStack(stack);
}