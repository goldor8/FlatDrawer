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
void DrawPoint(Screen* screen, Point* point, char c);

#endif //FLATDRAWER_POINT_H
