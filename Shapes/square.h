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
//Draw a square on the screen
void DrawSquare(Screen* screen, Square* square);
//Print the square informations to the console
void PrintSquare(Square* square);
//Read a square from the user input
Square* ReadSquare();

#endif //FLATDRAWER_SQUARE_H
