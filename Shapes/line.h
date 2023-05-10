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
void PrintLine(Line* line);

#endif //FLATDRAWER_LINE_H
