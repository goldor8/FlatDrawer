//
// Created by Dimitri on 24/03/2023.
//

#ifndef FLATDRAWER_LINE_H
#define FLATDRAWER_LINE_H
#include "../screen.h"
#include "point.h"

struct {
    Point* a;
    Point* b;
} typedef Line;

Line* CreateLine(Point* a, Point* b);
void DestroyLine(Line* line);
//Draw a line on the screen
void DrawLine(Screen* screen, Line* line);
//Draw a line on the screen without using Point or Line struct (can be called without having to create a Line or Point)
void StaticDrawLine(Screen* screen, int p1x, int p1y, int p2x, int p2y);
//Print the line informations to the console
void PrintLine(Line* line);
//Read a line from the user input
Line* ReadLine();

#endif //FLATDRAWER_LINE_H
