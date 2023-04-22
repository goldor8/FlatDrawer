//
// Created by Dimitri on 24/03/2023.
//

#include "line.h"
#include <stdlib.h>
#include <stdio.h>

Line* CreateLine(Point* a, Point* b) {
    Line* line = malloc(sizeof(Line));
    line->a = a;
    line->b = b;
    return line;
}

void DestroyLine(Line* line) {
    free(line->a);
    free(line->b);
    free(line);
}

void PrintLine(Line* line) {
    printf("Line: \n");
    PrintPointName(line->a, "\tp1");
    PrintPointName(line->b, "\tp2");
}

Line* ReadLine() {
    printf("Enter point 1: \n");
    Point* a = ReadPoint();
    printf("Enter point 2: \n");
    Point* b = ReadPoint();
    return CreateLine(a, b);
}
