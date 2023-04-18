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
    printf("Line: ");
    PrintPoint(line->a);
    printf(" -> ");
    PrintPoint(line->b);
}
