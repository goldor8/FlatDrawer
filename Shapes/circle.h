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
//Draw a circle on the screen
void DrawCircle(Screen* screen, Circle* circle);
//Print the circle informations to the console
void PrintCircle(Circle* circle);
//Read a circle from the user input
Circle* ReadCircle();

#endif //FLATDRAWER_CIRCLE_H
