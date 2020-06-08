/* 
    StudentInputList.h

    Description:
    Code file which contains function signatures for a StudentInputList struct.

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

// Function for freeing a student input list
void freeStudentInputList(pStudentInputList studentList){
    if(studentList->students != (pStudent*)NULL) freeStudentList(studentList->students, studentList->length);
    free(studentList);
}

// Function that creates a student input list based on the input provided from stdin
pStudentInputList createStudentInputList(){
    pStudentInputList studentList = mallocStudentInputList();
    pPoint2D address = (pPoint2D)NULL;
    String name = (String)NULL;
    pLine line = mallocLine();
    char input[255];
    double x, y;
    int i = 0;

    /* Logic and steps behind this chunk of spaghetti:
            Step 1: Create list of students, of size 1. (holds only 1 student);
            Step 2: Attempt to scan x & y coordinates, and a name from stdin in.
            Step 3: If successful, reallocate 1 extra block of memory to the list (to hold 1 extra student). If not successful, skip to step 7.
            Step 4: Create relevant structs (String, Point2D). *** See Note ***
            Step 5: Create a Student, using the new String and Point2D structs (name and address) *** See Note ***
            Step 6: Add the newly created Student to the list. Repeat steps 2-6 until we cannot scan anymore data from stdin.
            Step 7: Assign the length of the student list struct, the value of our iterator variable i which was being incremented throughout the loop.
            Step 8: Return the student list.

            *** Note: ***

            If at anytime, memory allocation fails, free everything created up until point of failure
            and return the free'd list pointer (NULL). This will eventually be checked and exited safely
            later in the program's execution.
    */

    if(studentList != (pStudentInputList)NULL){
        studentList->students = mallocStudentList();
        while(scanf("%lf %lf %[^\n]", &x, &y, input) != EOF){
            studentList->students = (pStudent*)realloc(studentList->students, (i+1)*sizeof(pStudent));
            name = duplicateString(input);
            address = createPoint2D(x, y);
            if(name != (String)NULL && address != (pPoint2D)NULL && line != (pLine)NULL && studentList->students != (pStudent*)NULL){
                studentList->students[i] = createStudent(name, address, line);
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

// prints the student list values to the console
void studentInputListToString(pStudentInputList studentList){
    int i = 0;
    printf("\nlength\ttype: int\tval: %d", studentList->length);
    while(i < studentList->length){
        studentToString(studentList->students[i]);
        i++;
    }
}