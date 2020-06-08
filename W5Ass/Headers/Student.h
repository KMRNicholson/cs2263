/* 
    Student.h

    Description:
    Header file which contains function signatures for a Student struct.

    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-06-03
*/

#ifndef STUDENT_H
#define STUDENT_H

#include "Point2D.h"
#include "Strings.h"
#include "Line.h"
#include "LineListFile.h"

// Struct typedef
typedef struct student{
    String name;
    pPoint2D address;
    pLine line;
} Student, *pStudent;

// Function that mallocs a single student
pStudent mallocStudent();
// Function that mallocs an array of students of size 1. Must be realloced to increase the size.
pStudent* mallocStudentList();
// Function that free's the student
void freeStudent(pStudent pThis);
// Function that free's the student list
void freeStudentList(pStudent* students, int length);
// Function that creates a student
pStudent createStudent(String name, pPoint2D address, pLine line);
// finds the closest stop to the student based on the line which they are assigned to
int findClosestStop(pStudent student);
// finds the line which has the closest stop to the student, and assigns that line to the student
void assignLineToStudent(pStudent student, pLineListFile lineList);
// prints the student values to the console
void studentToString(pStudent student);

#endif