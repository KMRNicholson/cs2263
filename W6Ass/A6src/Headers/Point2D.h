/* 
    Point2D.h

    Description:
    Header file which contains function signatures for a Point2D struct.

    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-06-03
*/

#ifndef POINT2D_H
#define POINT2D_H

#include <stdio.h>

// Struct typedef
typedef struct point2d{
    double x;
    double y;
} Point2D, *pPoint2D;

// Function that mallocs a single Point2D
pPoint2D mallocPoint2D();
// Function that mallocs a list of Point2D objects
pPoint2D* mallocPoint2DList(int length);
// Function that free's a single Point2D
void freePoint2D(pPoint2D point);
// Function that free's a list of Point2D structs
void freePoint2DList(pPoint2D* points, int length);
// Creates a point2d struct given x and y coordinates
pPoint2D createPoint2D(double x, double y);
// Deep copies a Point2D object
pPoint2D duplicatePoint2D(pPoint2D point);
// Gets the distance between 2 given Point2D objects
double getDistancePoint2D(pPoint2D pt1, pPoint2D pt2);
// Gets x y coordinates from a file
pPoint2D fgetPoint2D(FILE* file);
// Print the point2d inner values to stdout
void point2DToString(pPoint2D point);

#endif