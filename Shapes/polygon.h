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
//Draw a polygon on the screen
void DrawPolygon(Screen* screen, Polygon* polygon);
//Print the polygon informations to the console
void PrintPolygon(Polygon* polygon);
//Read a polygon from the user input
Polygon* ReadPolygon();

#endif //FLATDRAWER_POLYGON_H
