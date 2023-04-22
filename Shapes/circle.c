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
    DestroyPoint(circle->center);
    free(circle);
}

void PrintCircle(Circle* circle) {
    printf("Circle: \n");
    PrintPointName(circle->center, "\tcenter: ");
    printf("\tradius: %d\n", circle->radius);
}

Circle* ReadCircle() {
    printf("Enter center point: \n");
    Point* center = ReadPoint();
    int radius;
    printf("Enter radius: ");
    scanf("%d", &radius);
    return CreateCircle(center, radius);
}