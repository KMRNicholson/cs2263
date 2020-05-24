/* 
    htags.c

    Description:
    Program that counts the occurence of html tags from std input.
    
    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-05-24
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv){
    char* tag;

    while(scanf("%s", &tag) != EOF){
        printf("%s", tag);
    }

    return EXIT_SUCCESS;
}