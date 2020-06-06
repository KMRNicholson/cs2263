#include <stdlib.h>
#include <stdio.h>
#include "Headers/LineList.h"
#include "Headers/Strings.h"
#include "Headers/Point2D.h"
#include "Headers/Line.h"
#include "Headers/Student.h"

int main(int argc, char** argv){
    FILE* file = fopen(argv[1], "r");
    pLineListFile lineListFile = createLineListFile(file);
    fclose(file);
    int i = 0;
    int j = 0;
    lineListFileToString(lineListFile);
    freeLineListFile(lineListFile);
}