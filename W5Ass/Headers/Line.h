/* 
    Line.h

    Description:
    Header file which contains function signatures for a line struct.
    A line struct is essentially an array of Point2D pointers, with a length.

    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-06-06
*/

#ifndef LINE_H
#define LINE_H

#include <stdio.h>
#include "Point2D.h"
#include "Strings.h"

// Struct typedef
typedef struct line{
    int length;
    String name;
    pPoint2D* stops;
} Line, *pLine;

// Function that mallocs a single line
pLine mallocLine();
// Function that mallocs a list of lines
pLine* mallocLineList(int length);
// Function that free's a single line
void freeLine(pLine line);
// Function that free's a list of lines
void freeLineList(pLine* lines, int length);
// Function which creates a line, by calling a malloc and set functions above
pLine createLine(int length, String name, pPoint2D* stops);
// Function which scans a bus line from a file.
pLine fgetLine(FILE* file);
// Function which deep copies a given line.
pLine duplicateLine(pLine line);
// Function which prints the inner values of the line struct
void lineToString(pLine line);

#endif