//
// Created by Dimitri on 24/03/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include "circle.h"

Circle* CreateCircle(Point* center, int radius) {
    Circle* circle = malloc(sizeof(Circle));
    circle->center = center;
    circle->radius = radius;
    return circle;
}

void DestroyCircle(Circle* circle) {
    free(circle);
}

void PrintCircle(Circle* circle) {
    printf("Circle: \n");
    PrintPointName(circle->center, "\tcenter: ");
    printf("\tradius: %d\n", circle->radius);
}
