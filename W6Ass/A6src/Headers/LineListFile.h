/* 
    LineList.h

    Description:
    Header file which contains function signatures for a LineListFile struct.
    A LineListFile struct is essentially a c struct representation of data found
    in the busroutes.txt files provided to the program.

    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-06-06
*/

#ifndef LINELISTFILE_H
#define LINELISTFILE_H

#include <stdio.h>
#include "Point2D.h"
#include "Strings.h"
#include "Line.h"

// Struct typedef
typedef struct lineListFile{
    int length;
    pLine* lines;
} LineListFile, *pLineListFile;

// Function that free's a lineListFile struct
void freeLineListFile(pLineListFile lineList);
// Function which creates a lineListFile struct based on the given busroutes file
pLineListFile createLineListFile(FILE* file);
// Function which displayes the inner values of the lineListFile struct
void lineListFileToString(pLineListFile lineList);

#endif