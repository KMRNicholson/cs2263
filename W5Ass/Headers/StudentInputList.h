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

// Functions for creating a StudentInputList struct
void freeStudentInputList(pStudentInputList students);
pStudentInputList createStudentInputList();
void studentInputListToString(pStudentInputList StudentInputList);

#endif