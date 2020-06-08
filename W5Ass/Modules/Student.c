/* 
    Student.h

    Description:
    Code file which contains functions for a Student struct.

    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-06-06
*/

#include <stdlib.h>
#include <stdio.h>
#include "../Headers/Point2D.h"
#include "../Headers/Strings.h"
#include "../Headers/Student.h"
#include "../Headers/Line.h"
#include "../Headers/LineListFile.h"

// Function that mallocs a single student
pStudent mallocStudent(){
    pStudent stud = (pStudent)malloc(sizeof(Student));
    return stud;
}

// Function that mallocs an array of students of size 1. Must be realloced to increase the size.
pStudent* mallocStudentList(){
    pStudent* stud = (pStudent*)malloc(sizeof(pStudent));
    return stud;
}

// Function that sets values for the student
void setStudent(pStudent student, String name, pPoint2D address){
    student->name = name;
    student->address = address;
    student->line = (pLine)NULL;
}

// Function that free's the student
void freeStudent(pStudent student){
    if(student->name != (String)NULL) freeString(student->name);
    if(student->address != (pPoint2D)NULL) freePoint2D(student->address);
    if(student->line != (pLine)NULL) freeLine(student->line);

    free(student);
}

// Function that free's the student list
void freeStudentList(pStudent* students, int length){
    int i = 0;
    while(i < length){
        freeStudent(students[i]);
        i++;
    }

    free(students);
}

// Function that creates a student
pStudent createStudent(String name, pPoint2D address){
    pStudent stud = mallocStudent();
    if(stud != (pStudent)NULL){
        setStudent(stud, name, address);
    }

    return stud;
}

// finds the closest stop to the student based on the line which they are assigned to
int findClosestStop(pStudent student){
    int i = 0;
    int index = 0;
    double min = getDistancePoint2D(student->address, student->line->stops[0]);
    double temp = 0;
    
    while(i < student->line->length){
        temp = getDistancePoint2D(student->address, student->line->stops[i]);
        if(temp < min){
            min = temp;
            index = i;
        }
        i++;
    }

    return index;
}

// Function that finds the shortest distance to any stop in a given line
double findShortestDistance(pStudent student, pLine line){
    int i = 0;
    double min = getDistancePoint2D(student->address, line->stops[0]);
    double temp = 0;
    while(i < line->length){
        temp = getDistancePoint2D(student->address, line->stops[i]);
        if(temp < min){
            min = temp;
        }
        i++;
    }

    return min;
}

// finds the line which has the closest stop to the student, and assigns that line to the student
void assignLineToStudent(pStudent student, pLineListFile lineList){
    int i = 0;
    double min = findShortestDistance(student, lineList->lines[0]);
    double temp;
    int line = 0;

    // We cycle through each routes bus stops to see which stop is the closest. This determines what line the student takes.
    while(i < lineList->length){
        temp = findShortestDistance(student, lineList->lines[i]);
        if(temp < min){
            min = temp;
            line = i;
        }
        i++;
    }

    student->line = duplicateLine(lineList->lines[line]);
}

// prints the student values to the console
void studentToString(pStudent student){
    printf("\nname\ttype: char*\tval: %s", student->name);
    point2DToString(student->address);
}