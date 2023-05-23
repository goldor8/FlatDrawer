//
// Created by Dimitri on 24/03/2023.
//

#ifndef FLATDRAWER_RECT_H
#define FLATDRAWER_RECT_H
#include "../screen.h"
#include "point.h"

struct {
    Point* p1;
    int width;
    int height;
} typedef Rect;

Rect* CreateRect(Point* p1, int width, int height);
void DestroyRect(Rect* rect);
//Draw a rect on the screen
void DrawRect(Screen* screen, Rect* rect);
//Print the rect informations to the console
void PrintRect(Rect* rect);
//Read a rect from the user input
Rect* ReadRect();

#endif //FLATDRAWER_RECT_H
