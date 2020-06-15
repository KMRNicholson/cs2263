/* 
    StudentInputList.h

    Description:
    Header file which contains function signatures for a StudentInputList struct.

    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-06-03
*/

#ifndef STUDENTINPUTLIST_H
#define STUDENTINPUTLIST_H

#include "Point2D.h"
#include "Strings.h"
#include "Line.h"
#include "Student.h"

// Struct typedef
typedef struct studentInputList{
    int length;
    pStudent* students;
} StudentInputList, *pStudentInputList;

// Function for freeing a student input list
void freeStudentInputList(pStudentInputList students);
// Function that creates a student input list based on the input provided from stdin
pStudentInputList createStudentInputList();
// prints the student list values to the console
void studentInputListToString(pStudentInputList StudentInputList);

#endif