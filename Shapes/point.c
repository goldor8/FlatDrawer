//
// Created by Dimitri on 24/03/2023.
//

#include "point.h"
#include <stdlib.h>
#include <stdio.h>

Point* CreatePoint(int x, int y) {
    Point* point = malloc(sizeof(Point));
    point->x = x;
    point->y = y;
    return point;
}

void DestroyPoint(Point* point) {
    free(point);
}

void PrintPoint(Point* point) {
    printf("(%d, %d)\n", point->x, point->y);
}

void PrintPointName(Point* point, char* name){
    printf("%s: ", name);
    PrintPoint(point);
}
