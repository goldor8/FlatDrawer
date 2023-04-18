//
// Created by Dimitri on 24/03/2023.
//

#ifndef FLATDRAWER_CIRCLE_H
#define FLATDRAWER_CIRCLE_H
#include "../screen.h"
#include "point.h"

typedef struct {
    Point* center;
    int radius;
} Circle;

Circle* CreateCircle(Point* center, int radius);
void DestroyCircle(Circle* circle);
void DrawCircle(Screen* screen, Circle* circle, char c);
void PrintCircle(Circle* circle);

#endif //FLATDRAWER_CIRCLE_H
