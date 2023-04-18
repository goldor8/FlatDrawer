//
// Created by Dimitri on 24/03/2023.
//

#ifndef FLATDRAWER_POLYGON_H
#define FLATDRAWER_POLYGON_H
#include "../screen.h"
#include "point.h"

typedef struct {
    Point** points;
    int count;
} Polygon;

Polygon* CreatePolygon(Point** points, int count);
void DestroyPolygon(Polygon* polygon);
void DrawPolygon(Screen* screen, Polygon* polygon, char c);
void PrintPolygon(Polygon* polygon);

#endif //FLATDRAWER_POLYGON_H
