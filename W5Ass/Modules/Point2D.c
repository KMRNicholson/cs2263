/* 
    Point2D.c

    Description:
    Code which contains functions for a Point2D struct.

    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-06-03
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../Headers/Point2D.h"

// Function that mallocs a single Point2D
pPoint2D mallocPoint2D(){
    return (pPoint2D)malloc(sizeof(Point2D));
}

// Function that mallocs a list of Point2D objects
pPoint2D* mallocPoint2DList(int length){
    return (pPoint2D*)malloc(sizeof(pPoint2D)*length);
}

// Function that free's a single Point2D
void freePoint2D(pPoint2D point){
    free(point);
}

// Function that free's a list of Point2D structs
void freePoint2DList(pPoint2D* points, int length){
    int i = 0;
    while(i < length){
        freePoint2D(points[i]);
        i++;
    }

    free(points);
}

// Function that sets the coordinates for a given point
void setPoint2D(pPoint2D point, double x, double y){
    point->x = x;
    point->y = y;
}

// Creates a point2d struct given x and y coordinates
pPoint2D createPoint2D(double x, double y){
    pPoint2D point = mallocPoint2D();
    if(point != (pPoint2D)NULL){
        setPoint2D(point, x, y);
    }
    return point;
}

// Deep copies a Point2D object
pPoint2D duplicatePoint2D(pPoint2D point){
    pPoint2D pt = createPoint2D(point->x, point->y);
    return pt;
}

// Gets the distance between 2 given Point2D objects using pythagorean theorem
double getDistancePoint2D(pPoint2D pt1, pPoint2D pt2){
    int xDiff = pt1->x - pt2->x;
    int yDiff = pt1->y - pt2->y;
    int squaredDist = (xDiff * xDiff) + (yDiff * yDiff);
    return sqrt(squaredDist);
}

// Gets x y coordinates from a file
pPoint2D fgetPoint2D(FILE* file){
    double x, y;
    pPoint2D point;

    fscanf(file, "%lf %lf ", &x, &y);

    point = createPoint2D(x, y);

    return point;
}

// Print the point2d inner values to stdout
void point2DToString(pPoint2D point){
    printf("\nx\ttype: double\tval: %lf\n", point->x);
    printf("y\ttype: double\tval: %lf", point->y);
}