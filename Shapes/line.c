//
// Created by Dimitri on 24/03/2023.
//

#include "line.h"
#include "../screen.h"
#include "../utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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

void DrawLine(Screen* screen, Line* line){
    int x1, x2, y1, y2;
    if(line->a->x < line->b->x){
        x1 = line->a->x;
        x2 = line->b->x;
        y1 = line->a->y;
        y2 = line->b->y;
    } else {
        x1 = line->b->x;
        x2 = line->a->x;
        y1 = line->b->y;
        y2 = line->a->y;
    }

    int dx = x2 - x1;
    int dy = y2 - y1;

    int dmin = min(dx, abs(dy));
    int dmax = max(dx, abs(dy));

    int* segments = (int*) malloc(sizeof(int) * dmin + 1);
    int size = (dmax + 1) / (dmin + 1);
    int remain = (dmax + 1) % (dmin + 1);
    for (int i = 0; i < dmin + 1; ++i) {
        segments[i] = size + (((i+1)*remain)%(dmin+1) < (i*remain)%(dmin+1));
    }

    Set(screen, x1, y1);
    Set(screen, x2, y2);
    int inc = dy > 0 ? 1 : -1;
    if(dx > abs(dy)){
        for (int i = 0; i < dmin + 1; ++i) {
            for (int j = 0; j < segments[i]; ++j) {
                Set(screen, x1, y1);
                x1++;
            }
            y1 += inc;
        }
    } else {
        for (int i = 0; i < dmin + 1; ++i) {
            for (int j = 0; j < segments[i]; ++j) {
                Set(screen, x1, y1);
                y1 += inc;
            }
            x1++;
        }
    }
}
