/* 
    Line.c

    Description:
    Code file which contains functions for a line struct.
    A line struct is essentially an array of Point2D pointers, with a length.

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

// Function that mallocs a single line
pLine mallocLine(){
    return (pLine)malloc(sizeof(Line));
}

// Function that mallocs a list of lines
pLine* mallocLineList(int length){
    return (pLine*)malloc(sizeof(pLine)*length);
}

// Function that free's a single line
void freeLine(pLine line){
    if(line->stops != (pPoint2D*)NULL){ // check to see if there are other members to free
        freePoint2DList(line->stops, line->length);
    }

    if(line->name != (String)NULL){ // check to see if there are other members to free
        freeString(line->name);
    }

    free(line);
}

// Function that free's a list of lines
void freeLineList(pLine* lines, int length){
    int i = 0;
    
    while(i < length){ // For each line, we must free it from the list
        freeLine(lines[i]);
        i++;
    }
    
    free(lines); // free the list pointer
}

// Simply sets the properties of the line struct
void setLine(pLine line, int length, String name, pPoint2D* stops){
    line->length = length;
    line->name = name;
    line->stops = stops;
}

// Function which creates a line, by calling a malloc and set functions above
pLine createLine(int length, String name, pPoint2D* stops){
    pLine line = mallocLine();
    
    if(line != (pLine)NULL){
        setLine(line, length, name, stops);
    }

    return line;
}

// Function which scans a bus line from a file.
pLine fgetLine(FILE* file){
    int i, stops;
    fscanf(file, "%d ", &stops); // get the number of bus stop for a line
    pLine line = (pLine)NULL;

    pPoint2D* points = mallocPoint2DList(stops);

    i = 0;
    if(points != (pPoint2D*)NULL){
        while(i < stops){ // For each stop, we need to get the related data from the routes file
            points[i] = fgetPoint2D(file);
            if(points[i] == (pPoint2D)NULL){ // If we somehow manage to fail to allocate memory, abort, free everything, fail program
                freePoint2DList(points, stops);
                return line; // This will return a NULL, which will cause the program to exit safely in later checks
            }
            i++;
        }
    }

    String streetName = fgetString(file);

    if(streetName != (String)NULL && points != (pPoint2D*)NULL){ // If all structs allocated properly, create the line
        line = createLine(stops, streetName, points);
    }

    return line;
}

// Function which deep copies a given line.
pLine duplicateLine(pLine line){
    int i = 0;
    pLine dupLine = mallocLine();
    String name = duplicateString(line->name); // We must also deep copy the structs pointed to by the given line
    pPoint2D* stops = mallocPoint2DList(line->length);

    while(i < line->length){ // This deep copies all the bus stops for a line
        stops[i] = duplicatePoint2D(line->stops[i]);
        if(stops[i] == (pPoint2D)NULL){
            freePoint2DList(stops, line->length);
            break;
        }
        i++;
    }

    if(name != (String)NULL && stops != (pPoint2D*)NULL && dupLine != (pLine)NULL){
        setLine(dupLine, line->length, name, stops);
    }

    return dupLine;
}

// Function which prints the inner values of the line struct
void lineToString(pLine line){
    int i = 0;
    printf("\nname\ttype: char*\tval: %s\nlength\ttype: int\tval: %d", line->name, line->length);
    while(i < line->length){
        point2DToString(line->stops[i]);
        i++;
    }
}