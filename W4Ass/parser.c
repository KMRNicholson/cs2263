/* 
    parser.c

    Description:
    Functions for parsing html elements.
    
    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-05-24
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
a cover function for malloc()
malloc and return memory for a string of stringsize characters
return (char*)NULL on failure
*/
char* mallocString(int stringsize){
    char* newString = (char*)malloc(stringsize);
    return newString;
}

/*
Function to check if the pointer contains a letter value
*/
int is_letter(char ch){
    int result = 0;
    if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) result = 1;
    return result;
}

/*
Function to check if the pointer contains a number value
*/
int is_num(char ch){
    int result = 0;
    if(ch >= '0' && ch <= '9') result = 1;
    return result;
}

char* extract_tag(char* tag_start){
    char* tag_end = tag_start;
    char* tag;
    int stringSize = 1; // stringsize will be 1 even if emtpy, for the null character
    int i = 0;

    //This will loop through the input until the end of the tag name, capturing the stringSize as well
    while(is_letter(*tag_end) || is_num(*tag_end)){
        tag_end++;
        stringSize++;
    }

    tag = mallocString(stringSize);

    if(tag != (char*)NULL){
        // deep copy the tag into the newly allocated string on the heap
        while(tag_start != tag_end){
            tag[i] = *tag_start;
            tag_start++;
            i++;
        }

        tag[i] = '\0'; // null terminate the string
    }

    return tag;
}

/*
Function which checks to see if the given tag is already in the list
returns the index if in the list, returns -1 if not;
*/
int check_tag_list(char** list, char* tag, int n){
    int i = 0;
    while(i < n){
        if(strcmp(list[i], tag) == 0){
            return i;
        }
        i++;
    }
    return -1;
}

/*
Function for checking to see if we have encountered a comment.
*/
int is_comment(char* start){
    int result = 0;
    
    if(*start == '<'){
        start++;
        if(*start == '!'){
            start++;
            if(*start == '-'){
                start++;
                if(*start == '-'){
                    result = 1;
                }
            }
        }
    }

    return result;
}

/*
Function for removing comment contents. Loop will only terminate when we reach the comment ending '-->'.
*/
void remove_comment(char* start){
    char* ending_dash = start + 1;
    char* ending_arrow = ending_dash + 1;
    while(*start != '-' || *ending_dash != '-' || *ending_arrow != '>'){
        
        *start = ' '; // This will begin removing everything inside the comment.

        start++;
        ending_dash++;
        ending_arrow++;
    }
}