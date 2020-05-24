/* 
    htags.c

    Description:
    Program that counts the occurence of html tags from std input.
    
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
    int n = 100000;
    char* contents = (char*)malloc(n);
    if(contents == (char*)NULL){
		fprintf(stderr,"Memory failure, terminating");
		return EXIT_FAILURE;
	}

    // Table of character pointers to the first occurence of html tags
    //char* index_table[100];
    char** index_table = (char**)malloc(n);
    if(index_table == (char**)NULL){
		fprintf(stderr,"Memory failure, terminating");
		return EXIT_FAILURE;
	}

    // Parallel integer table for the amount of occurences of each html tag in the index table
    int occurences[100];

    // base pointers for the html contents, index table and occurences table.
    char* contents_base_ptr = contents;
    int* occurence_base_ptr = occurences;
    char** index_base_ptr = index_table;

    // Stack pointers for the occurence and index tables
    int* occurrence_stack_ptr = occurences;
    char** index_stack_ptr = index_table; 

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

    *** STEP THREE: FIND FIRST OCCURENCE OF HTML TAGS ***

    */
    contents_base_ptr = contents;
    while(contents_base_ptr < stack_size){
        if(*contents_base_ptr == '<'){
            if(is_letter(*(contents_base_ptr+1)) == 1){

                /*

                *** STEP FOUR: FIND OTHER OCCURENCES OF HTML TAG. REMOVE TAGS ONCE CONFIRMED.

                */
                *index_stack_ptr = contents_base_ptr + 1;
                *occurrence_stack_ptr = find_occurrences(contents, *index_stack_ptr);
                occurrence_stack_ptr++;
                index_stack_ptr++;
            }
        }
        contents_base_ptr++;
    }

    /*

    *** STEP FIVE: PRINT DETAILS FOR HTML TAGS ***

    */
    char* char_ptr;
    while(index_base_ptr != index_stack_ptr){
        char_ptr = *index_base_ptr;
        while(is_letter(*char_ptr) == 1 || is_num(*char_ptr) == 1){
            printf("%c", *char_ptr);
            char_ptr++;
        }

        printf("\t\t%d\n", *occurence_base_ptr);

        index_base_ptr++;
        occurence_base_ptr++;
    }
    
    free(contents);
    free(index_table);

    return EXIT_SUCCESS;
}