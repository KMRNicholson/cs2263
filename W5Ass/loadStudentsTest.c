#include <stdlib.h>
#include <stdio.h>
#include "Headers/LineListFile.h"
#include "Headers/Strings.h"
#include "Headers/Point2D.h"
#include "Headers/Line.h"
#include "Headers/Student.h"
#include "Headers/StudentInputList.h"

int main(int argc, char** argv){
    pStudentInputList studentList = createStudentInputList();
    if(studentList == (pStudentInputList)NULL){
        printf("Failed to allocate memory. Exiting..");
        return EXIT_FAILURE;
    }
    
    studentInputListToString(studentList);
    freeStudentInputList(studentList);
    printf("\n");
    
    return EXIT_SUCCESS;
}