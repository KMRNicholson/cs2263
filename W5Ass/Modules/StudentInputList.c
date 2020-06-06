/* 
    StudentInputList.h

    Description:
    Header file which contains function signatures for a StudentInputList struct.

    Author: 
    Kohdy Nicholson
    
    Date: 
    2020-06-03
*/

#include <stdio.h>
#include <stdlib.h>
#include "../Headers/Point2D.h"
#include "../Headers/Strings.h"
#include "../Headers/Line.h"
#include "../Headers/Student.h"
#include "../Headers/StudentInputList.h"

pStudentInputList mallocStudentInputList(){
    return (pStudentInputList)malloc(sizeof(StudentInputList));
}

void freeStudentInputList(pStudentInputList studentList){
    if(studentList->students != (pStudent*)NULL) freeStudentList(studentList->students, studentList->length);
    free(studentList);
}

pStudentInputList createStudentInputList(){
    pStudentInputList studentList = mallocStudentInputList();
    pPoint2D address = (pPoint2D)NULL;
    String name = (String)NULL;
    char input[255];
    double x, y;
    int i = 0;

    if(studentList != (pStudentInputList)NULL){
        studentList->students = mallocStudentList();
        while(scanf("%lf %lf %[^\n]", &x, &y, input) != EOF){
            studentList->students = (pStudent*)realloc(studentList->students, (i+1)*sizeof(pStudent));
            name = duplicateString(input);
            address = createPoint2D(x, y);
            if(name != (String)NULL && address != (pPoint2D)NULL && studentList->students != (pStudent*)NULL){
                studentList->students[i] = createStudent(name, address);
                if(studentList->students[i] == (pStudent)NULL){
                    freeString(name);
                    freePoint2D(address);
                    freeStudentInputList(studentList);
                    break;
                }
            }else{
                freeString(name);
                freePoint2D(address);
                freeStudentInputList(studentList);
            }
            i++;
        }
        studentList->length = i;
    }

    return studentList;
}

void studentInputListToString(pStudentInputList studentList){
    int i = 0;
    printf("\nlength\ttype: int\tval: %d", studentList->length);
    while(i < studentList->length){
        studentToString(studentList->students[i]);
        i++;
    }
}