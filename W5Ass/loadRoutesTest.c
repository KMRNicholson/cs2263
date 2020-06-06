#include <stdlib.h>
#include <stdio.h>
#include "Headers/LineListFile.h"
#include "Headers/Strings.h"
#include "Headers/Point2D.h"
#include "Headers/Line.h"
#include "Headers/Student.h"

int main(int argc, char** argv){
    FILE* file = fopen(argv[1], "r");

    pLineListFile lineListFile = createLineListFile(file);
    if(lineListFile == (pLineListFile)NULL){
        printf("Failed to allocate memory. Exiting..");
        return EXIT_FAILURE;
    }

    fclose(file);
    
    lineListFileToString(lineListFile);
    freeLineListFile(lineListFile);
    
    return EXIT_SUCCESS;
}