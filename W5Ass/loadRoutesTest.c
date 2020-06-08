/* 
    loadRoutesTest.c

    Description:
    Test driver to ensure bus routes are loaded from a file, into a LineListFile struct.

    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-06-07
*/

#include <stdlib.h>
#include <stdio.h>
#include "Headers/LineListFile.h"
#include "Headers/Strings.h"
#include "Headers/Point2D.h"
#include "Headers/Line.h"
#include "Headers/Student.h"

int main(int argc, char** argv){
    if(argc < 2){
        printf("File not specified. Exiting..\n");
        return EXIT_FAILURE;
    }

    FILE* file = fopen(argv[1], "r");

    if(file == NULL){
        printf("Failed to load file. Exiting..\n");
        return EXIT_FAILURE;
    }

    pLineListFile lineListFile = createLineListFile(file);
    if(lineListFile == (pLineListFile)NULL){
        printf("Failed to allocate memory. Exiting..\n");
        return EXIT_FAILURE;
    }

    fclose(file);
    
    lineListFileToString(lineListFile);
    freeLineListFile(lineListFile);
    printf("\n");
    
    return EXIT_SUCCESS;
}