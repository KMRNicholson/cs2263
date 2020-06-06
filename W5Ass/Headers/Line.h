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

// Functions for creating a Line struct
pLine mallocLine();
pLine* mallocLineList(int length);
void freeLine(pLine line);
void freeLineList(pLine* lines, int length);
void setLine(pLine line, int length, String name, pPoint2D* stops);
pLine createLine(int length, String name, pPoint2D* stops);
pLine fgetLine(FILE* file);
void lineToString(pLine line);

#endif