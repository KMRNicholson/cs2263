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

pPoint2D mallocPoint2D(){
    pPoint2D point;
    point = (pPoint2D)malloc(sizeof(Point2D));

    return point;
}

pPoint2D* mallocPoint2DList(int length){
    pPoint2D* points;
    points = (pPoint2D*)malloc(sizeof(pPoint2D)*length);
    return points;
}

void freePoint2D(pPoint2D point){
    free(point);
}

void freePoint2DList(pPoint2D* points, int length){
    int i = 0;
    while(i < length){
        freePoint2D(points[i]);
        i++;
    }

    free(points);
}

void setPoint2D(pPoint2D point, double x, double y){
    point->x = x;
    point->y = y;
}

pPoint2D createPoint2D(double x, double y){
    pPoint2D point = mallocPoint2D();
    if(point != (pPoint2D)NULL){
        setPoint2D(point, x, y);
    }
    return point;
}

pPoint2D duplicatePoint2D(pPoint2D point){
    pPoint2D pt = createPoint2D(point->x, point->y);
    return pt;
}

double getDistancePoint2D(pPoint2D pt1, pPoint2D pt2){
    int xDiff = pt1->x - pt2->x;
    int yDiff = pt1->y - pt2->y;
    int squaredDist = (xDiff * xDiff) + (yDiff * yDiff);
    return sqrt(squaredDist);
}

pPoint2D fgetPoint2D(FILE* file){
    int x, y;
    pPoint2D point;

    fscanf(file, "%d %d ", &x, &y);

    point = createPoint2D(x, y);

    return point;
}

void point2DToString(pPoint2D point){
    printf("\nx\ttype: double\tval: %lf\n", point->x);
    printf("y\ttype: double\tval: %lf", point->y);
}