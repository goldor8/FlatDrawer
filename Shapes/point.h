//
// Created by Dimitri on 24/03/2023.
//

#ifndef FLATDRAWER_POINT_H
#define FLATDRAWER_POINT_H
#include "../screen.h"

struct {
    int x;
    int y;
} typedef Point;

Point* CreatePoint(int x, int y);
void DestroyPoint(Point* point);
//Print the point informations to the console
void PrintPoint(Point* point);
//Print the point informations to the console with a specified name
void PrintPointName(Point* point, char* name);
//Draw a point on the screen
void DrawPoint(Screen* screen, Point* point);
//Read a point from the user input
Point* ReadPoint();

#endif //FLATDRAWER_POINT_H
