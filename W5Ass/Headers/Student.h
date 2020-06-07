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

// Functions for creating a student struct
pStudent mallocStudent();
pStudent* mallocStudentList();
void freeStudent(pStudent pThis);
void freeStudentList(pStudent* students, int length);
pStudent createStudent(String name, pPoint2D address);
void studentToString(pStudent student);
int findClosestStop(pStudent student);
void assignLineToStudent(pStudent student, pLineListFile lineList);

#endif