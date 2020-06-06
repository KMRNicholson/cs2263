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

pStudent mallocStudent(){
    pStudent stud = (pStudent)malloc(sizeof(Student));
    return stud;
}

void setStudent(pStudent student, String name, pPoint2D address){
    student->name = name;
    student->address = address;
}

void freeStudent(pStudent student){
    if(student->name != (String)NULL) freeString(student->name);
    if(student->address != (pPoint2D)NULL) freePoint2D(student->address);

    free(student);
}

pStudent createStudent(String name, pPoint2D address){
    pStudent stud = mallocStudent();
    if(stud != (pStudent)NULL){
        setStudent(stud, name, address);
    }
    return stud;
}

// Functions for getting student data
String getStudentName(pStudent student){
    return duplicateString(student->name);
}

pPoint2D getStudentAddress(pStudent student){
    return duplicatePoint2D(student->address);
}

void studentToString(pStudent student){
    printf("\nname\ttype: char*\tval: ");
    stringToString(student->name);
    printf("\naddress\ttype: struct point2D\tval: ");
    point2DToString(student->address);
}