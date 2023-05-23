//
// Created by Dimitri on 24/03/2023.
//

#ifndef FLATDRAWER_SHAPE_H
#define FLATDRAWER_SHAPE_H
#include "../screen.h"

int GetNextId();

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

Shape* CreateShape(enum ShapeType shapeType, void* shape);
void DestroyShape(Shape* shape);
void DrawShape(Screen* screen, Shape* shape);
void PrintShape(Shape* shape);
Shape* ReadShape();

Shape* CreateEmptyShape();
Shape* CreatePointShape(int px, int py);
Shape* CreateLineShape(int px1, int py1, int px2, int py2);
Shape* CreateSquareShape(int px, int py, int length);
Shape* CreateRectangleShape(int px, int py, int width, int height);
Shape* CreateCircleShape(int px, int py, int radus);
Shape* CreatePolygonShape(int lst[], int n);

#endif //FLATDRAWER_SHAPE_H
