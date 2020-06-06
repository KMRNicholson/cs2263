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

// typede struct
typedef struct point2d{
    double x;
    double y;
} Point2D, *pPoint2D;

// struct creation/free
pPoint2D mallocPoint2D();
pPoint2D* mallocPoint2DList(int length);
void freePoint2D(pPoint2D point);
void freePoint2DList(pPoint2D* points, int length);
void setPoint2D(pPoint2D point, double x, double y);
pPoint2D createPoint2D(double x, double y);

// getters
pPoint2D duplicatePoint2D(pPoint2D point);
double getDistancePoint2D(pPoint2D pt1, pPoint2D pt2);
pPoint2D fgetPoint2D(FILE* file);

void point2DToString(pPoint2D point);

#endif