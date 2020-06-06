/* 
    LineList.h

    Description:
    Header file which contains function signatures for a LineList struct.
    A LineList struct is essentially an array of Line pointers, with a length.

    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-06-06
*/

#ifndef LINELIST_H
#define LINELIST_H

#include <stdio.h>
#include "Point2D.h"
#include "Strings.h"
#include "Line.h"

// Struct typedef
typedef struct lineListFile{
    int length;
    pLine* lines;
} LineListFile, *pLineListFile;

void freeLineListFile(pLineListFile LineList);
pLineListFile createLineListFile(FILE* file);
void lineListFileToString(pLineListFile lineList);

#endif