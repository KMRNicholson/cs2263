/* 
    Line.h

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

// Functions for creating a Line struct
pLine mallocLine(){
    pLine line = (pLine)malloc(sizeof(Line));
    return line;
}

pLine* mallocLineList(int length){
    pLine* lines = (pLine*)malloc(sizeof(pLine)*length);
    return lines;
}

void freeLine(pLine line){
    if(line->stops != (pPoint2D*)NULL){
        freePoint2DList(line->stops, line->length);
    }

    if(line->name != (String)NULL){
        freeString(line->name);
    }

    free(line);
}

void freeLineList(pLine* lines, int length){
    int i = 0;
    while(i < length){
        freeLine(lines[i]);
        i++;
    }
}

void setLine(pLine line, int length, String name, pPoint2D* stops){
    line->length = length;
    line->name = name;
    line->stops = stops;
}

pLine createLine(int length, String name, pPoint2D* stops){
    pLine line = mallocLine();
    
    if(line != (pLine)NULL){
        setLine(line, length, name, stops);
    }

    return line;
}

pLine fgetLine(FILE* file){
    int i, stops;
    fscanf(file, "%d ", &stops);
    pLine line = (pLine)NULL;

    pPoint2D* points = mallocPoint2DList(stops);

    i = 0;
    if(points != (pPoint2D*)NULL){
        while(i < stops){
            points[i] = fgetPoint2D(file);
            if(points[i] == (pPoint2D)NULL){
                freePoint2DList(points, stops);
                return line;
            }
            i++;
        }
    }

    String streetName = fgetString(file);

    if(streetName != (String)NULL && points != (pPoint2D*)NULL){
        line = createLine(stops, streetName, points);
    }

    return line;
}

void lineToString(pLine line){
    int i = 0;
    printf("\nname\ttype: char*\tval: %s\nlength\ttype: int\tval: %d", line->name, line->length);
    while(i < line->length){
        point2DToString(line->stops[i]);
        i++;
    }
}