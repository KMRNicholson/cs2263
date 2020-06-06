/* 
    LineList.h

    Description:
    Code file which contains function for a LineList struct.
    A LineList struct is essentially an array of Line pointers, with a length.

    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-06-06
*/

#include <stdio.h>
#include <stdlib.h>
#include "../Headers/Point2D.h"
#include "../Headers/Strings.h"
#include "../Headers/Line.h"
#include "../Headers/LineListFile.h"

// Functions for creating a LineList struct
pLineListFile mallocLineListFile(){
    return (pLineListFile)malloc(sizeof(LineListFile));
}

void freeLineListFile(pLineListFile lineList){
    freeLineList(lineList->lines, lineList->length);
    free(lineList);
}

int fgetLineNum(FILE* file){
    int lineNum = 0;
    fscanf(file, "%d\n", &lineNum);
    return lineNum;
}

pLineListFile createLineListFile(FILE* file){
    pLineListFile lineList = mallocLineListFile();
    int i = 0;

    if(lineList != (pLineListFile)NULL){
        lineList->length = fgetLineNum(file);
        lineList->lines = mallocLineList(lineList->length);
        if(lineList->lines != (pLine*)NULL){
            while(i < lineList->length){
                lineList->lines[i] = fgetLine(file);
                if(lineList->lines[i] == (pLine)NULL){
                    freeLineListFile(lineList);
                    break;
                }
                i++;
            }
        }else{
            freeLineListFile(lineList);
        }
    }

    return lineList;
}

void lineListFileToString(pLineListFile lineList){
    int i = 0;
    printf("\nlength\ttype: int\tval: %d", lineList->length);
    while(i < lineList->length){
        lineToString(lineList->lines[i]);
        i++;
    }
}