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
    PrintPointName(circle->center, "\tcenter");
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

void DrawCircle(Screen* screen, Circle* circle){
    int x = 0;
    int y = circle->radius;
    int centerX = circle->center->x;
    int centerY = circle->center->y;
    int d = 1 - circle->radius;

    while(x <= y){
        Set(screen, centerX + x, centerY + y);
        Set(screen, centerX + y, centerY + x);
        Set(screen, centerX - x, centerY + y);
        Set(screen, centerX - y, centerY + x);
        Set(screen, centerX + x, centerY - y);
        Set(screen, centerX + y, centerY - x);
        Set(screen, centerX - x, centerY - y);
        Set(screen, centerX - y, centerY - x);

        if(d < 0) {
            x++;
            d += 2 * x + 1;
        } else {
            y--;
            x++;
            d += 2 * (x - y) + 2;
        }

    }
}