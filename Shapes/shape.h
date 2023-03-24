//
// Created by Dimitri on 24/03/2023.
//

#ifndef FLATDRAWER_SHAPE_H
#define FLATDRAWER_SHAPE_H
#include "../screen.h"

enum ShapeType {
    POINT,
    LINE,
    CIRCLE,
    SQUARE,
    RECT,
    POLYGON
};

struct {
    enum ShapeType shapeType;
    int id;
    void* shape;
} typedef Shape;

Shape* CreateShape(enum ShapeType shapeType);
void DestroyShape(Shape* shape);
void DrawShape(Screen* screen, Shape* shape, char c);

#endif //FLATDRAWER_SHAPE_H
