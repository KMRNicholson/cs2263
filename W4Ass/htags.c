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
    // open html file specified on cmd line
    FILE* html = fopen(argv[1], "r");

    // String for storing the html input
    int n = 100000;
    char* contents = (char*)malloc(n);
    if(contents == (char*)NULL){
        fprintf(stderr,"Memory failure, terminating");
        return EXIT_FAILURE;
    }

    // list of tags
    char** tag_list = (char**)malloc(100);
    if(tag_list == (char**)NULL){
        fprintf(stderr,"Memory failure, terminating");
        return EXIT_FAILURE;
    }

    // Parallel integer table for the amount of occurences of each html tag in the list of tags
    int* occurences = (int*)malloc(100);
    if(occurences == (int*)NULL){
        fprintf(stderr,"Memory failure, terminating");
        return EXIT_FAILURE;
    }

    // variable for holding a pointer to the extracted tag in the heap
    char* tag;

    // Size of the contents string
    int size;

    // size of the list of tags
    int list_size;
    
    // index of the tag in the list
    int index;

    // variable for storing individual characters into the contents string
    char input;
    
    int i;
    
    /*

    *** STEP ONE: FILL THE contents ARRAY WITH HTML FILE CONTENTS ***  
    
    */
    i = 0;
    while(fscanf(html, "%c", &input) != EOF){
        contents[i] = input;
        i++;
    }
    contents[i] = '\0'; //Null terminate the html contents
    
    /*

    *** STEP TWO: REMOVE CONTENT WITHIN COMMENT TAGS ***  
    
    */
    size = strlen(contents);
    i = 0;
    while(i < size){ // First we need to remove comments from the html contents.
        if(contents[i] == '<'){
            if(is_comment(&contents[i])){
                remove_comment(&contents[i] + 4); // We add 4 to the base pointer address to skip the comment start '<!--'
            }
        }
        i++;
    }

    /*

    *** STEP THREE: FIND FIRST OCCURENCE OF HTML TAGS ***

    */
    i = 0;
    list_size = 0;
    while(i < size){
        if(contents[i] == '<'){
            if(is_letter(contents[i+1]) == 1){

                /*

                *** STEP FOUR: FIND OTHER OCCURENCES OF HTML TAG. REMOVE TAGS ONCE CONFIRMED.

                */
                
                tag = extract_tag(&contents[i+1]);
                index = check_tag_list(tag_list, tag, list_size);
                if(index == -1){
                    tag_list[list_size] = tag;
                    occurences[list_size] = 1;
                    list_size++;
                }else{
                    occurences[index]++;
                    free(tag);
                }
            }
        }
        i++;
    }

    /*

    *** STEP FIVE: PRINT DETAILS FOR HTML TAGS ***

    */
    i = 0;
    while(i < list_size){
        printf("%s", tag_list[i]);
        printf("\t\t%d\n", occurences[i]);

        free(tag_list[i]); // Free the memory, no longer needed.

        i++;
    }
    
    free(contents);
    free(tag_list);
    free(occurences);

    return EXIT_SUCCESS;
}
