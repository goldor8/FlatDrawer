//
// Created by Dimitri on 24/03/2023.
//

#ifndef FLATDRAWER_SQUARE_H
#define FLATDRAWER_SQUARE_H
#include "../screen.h"
#include "point.h"

struct {
    Point* point;
    int length;
} typedef Square;

Square* CreateSquare(Point* point, int length);
void DestroySquare(Square* square);
void DrawSquare(Screen* screen, Square* square, char c);
void PrintSquare(Square* square);

#endif //FLATDRAWER_SQUARE_H
