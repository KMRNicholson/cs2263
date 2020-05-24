/* 
    remove_comments_test.c

    Description:
    Test program for removing comments from html input.
    
    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-05-24
*/

#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
    // Only allowable data structure for holding a string
    char contents[100000];

    // base pointers for the html contents, index table and occurences table.
    char* contents_base_ptr = contents;

    // Stack pointer to be used by the program for stack sizes
    char* stack_size;

    // Size of the contents string
    int size;

    // variable for storing individual characters into the contents string
    char input;

    /*

    *** STEP ONE: FILL THE contents ARRAY WITH HTML FILE CONTENTS ***  
    
    */
    while(scanf("%c", &input) != EOF){
        *contents_base_ptr = input;
        contents_base_ptr++;
    }

    /*

    *** STEP TWO: REMOVE CONTENT WITHIN COMMENT TAGS ***  
    
    */
    size = strlen(contents);
    contents_base_ptr = contents;
    stack_size = contents_base_ptr + size;
    while(contents_base_ptr < stack_size){ // First we need to remove comments from the html contents.
        if(*contents_base_ptr == '<'){
            if(is_comment(contents_base_ptr)){
                remove_comment(contents_base_ptr + 4); // We add 4 to the base pointer address to skip the comment start '<!--'
            }
        }
        contents_base_ptr++;
    }

    /*

    *** STEP THREE: DISPLAY HTML WITH EMPTY COMMENTS ***  
    
    */
    contents_base_ptr = contents;
    while(contents_base_ptr < stack_size){
        printf("%c", *contents_base_ptr);
        contents_base_ptr++;
    }

    return EXIT_SUCCESS;
}