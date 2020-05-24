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

/*
Function which matches an html tag, then removes it.
*/
int is_match(char* source, char* target){
    char* tgt_base_ptr = target;
    int result = 0;

    // compare characters from the source to the target, based on letters and numbers.
    while(is_letter(*source) == 1 || is_num(*source) == 1){
        if(*source == *target){
            result = 1;
        }else{
            result = 0;
            break; // break if a difference is found. not a match.
        }
        source++;
        target++;      
    }

    // If everything in source is in target
    if(result == 1){
        if(is_letter(*target) == 1 || is_num(*target) == 1){
            result = 0; // Extra check incase source is something like 'col', and target is 'colgroup' 
        }else{
            while(tgt_base_ptr != target){
                target--;
                *target = ' '; // Begin removing the duplicate tag
            }
        }
    }

    return result;
}

/*
Function for finding the occurences of an html tag.
*/
int find_occurrences(char* contents, char* current){
    int size = strlen(contents);
    int occured = 1;
    int i = (int)(current - contents);
    
    contents = current;
    while(i < size){
        if(*contents == '<'){
            if(is_letter(*(contents + 1)) == 1){
                if(is_match(current, (contents + 1)) == 1){
                    occured++;
                }
            }
        }
        contents++;
        i++;
    }

    return occured;
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