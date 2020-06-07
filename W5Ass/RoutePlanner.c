/* 
    RoutePlanner.c

    Description:
    Code file which takes a file of bus routes and assigns the closest line
    to the students which are fed in through stdin.

    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-06-07
*/

#include <stdlib.h>
#include <stdio.h>
#include "Headers/LineListFile.h"
#include "Headers/Strings.h"
#include "Headers/Point2D.h"
#include "Headers/Line.h"
#include "Headers/Student.h"
#include "Headers/StudentInputList.h"

int main(int argc, char** argv){
    int i = 0;
    int closestStop;

    if(argc < 2){
        printf("Please provide a file name.\n");
        return EXIT_FAILURE;
    }

    FILE* file = fopen(argv[1], "r");

    if(file == NULL){
        printf("Failed to open file.\n");
        return EXIT_FAILURE;
    }

    pLineListFile lineListFile = createLineListFile(file);
    if(lineListFile == (pLineListFile)NULL){
        printf("Failed to allocate memory. Exiting..");
        return EXIT_FAILURE;
    }

    fclose(file);

    pStudentInputList studentList = createStudentInputList();
    if(studentList == (pStudentInputList)NULL){
        printf("Failed to allocate memory. Exiting..");
        return EXIT_FAILURE;
    }
    
    while(i < studentList->length){
        assignLineToStudent(studentList->students[i], lineListFile);
        closestStop = findClosestStop(studentList->students[i]);
        printf("Name: %s\n", studentList->students[i]->name);
        printf("Address Coordinates: %lf %lf\n", studentList->students[i]->address->x, studentList->students[i]->address->y);
        printf("Assigned Line: %s\n", studentList->students[i]->line->name);
        printf("Stop Number: %d\n", closestStop);
        printf("Stop Coordinates: %lf %lf\n\n", studentList->students[i]->line->stops[closestStop]->x, studentList->students[i]->line->stops[closestStop]->y);
        i++;
    }

    freeStudentInputList(studentList);
    freeLineListFile(lineListFile);
    
    return EXIT_SUCCESS;
}