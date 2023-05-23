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
void DrawLine(Screen* screen, Line* line);
void StaticDrawLine(Screen* screen, int p1x, int p1y, int p2x, int p2y);
void PrintLine(Line* line);
Line* ReadLine();

#endif //FLATDRAWER_LINE_H
