//
// Created by Dimitri on 24/03/2023.
//

#include "shape.h"
#include <stdlib.h>
#include <stdio.h>
#include "point.h"
#include "line.h"
#include "circle.h"
#include "square.h"
#include "rect.h"
#include "polygon.h"

static unsigned int currentId = 0;

int GetNextId() {
    return currentId++;
}

void printShapesTypes() {
    printf("Shape types:\n");
    printf("0 - Point\n");
    printf("1 - Line\n");
    printf("2 - Circle\n");
    printf("3 - Square\n");
    printf("4 - Rectangle\n");
    printf("5 - Polygon\n");
}

Shape* CreateShape(enum ShapeType type, void* genericShape) {
    Shape* shape = CreateEmptyShape();
    shape->shapeType = type;
    shape->shape = genericShape;
    return shape;
}

void PrintShape(Shape* shape){
    printf("Shape id: %d\n", shape->id);
    switch (shape->shapeType) {
        case POINT:
            PrintPointName(shape->shape, "Point");
            break;
        case LINE:
            PrintLine(shape->shape);
            break;
        case CIRCLE:
            PrintCircle(shape->shape);
            break;
        case SQUARE:
            PrintSquare(shape->shape);
            break;
        case RECT:
            PrintRect(shape->shape);
            break;
        case POLYGON:
            PrintPolygon(shape->shape);
            break;
    }
}

Shape* CreateEmptyShape() {
    Shape* shape = malloc(sizeof(Shape));
    shape->id = GetNextId();
    return shape;
}

Shape* CreatePointShape(int px, int py) {
    Point* point = CreatePoint(px, py);
    return CreateShape(POINT, point);
}

Shape* CreateLineShape(int px1, int py1, int px2, int py2) {
    Point* p1 = CreatePoint(px1, py1);
    Point* p2 = CreatePoint(px2, py2);
    Line* line = CreateLine(p1, p2);
    return CreateShape(LINE, line);
}

Shape* CreateSquareShape(int px, int py, int length) {
    Point* point = CreatePoint(px, py);
    Square* square = CreateSquare(point, length);
    return CreateShape(SQUARE, square);
}

Shape* CreateRectangleShape(int px, int py, int width, int height) {
    Point* point = CreatePoint(px, py);
    Rect* rect = CreateRect(point, width, height);
    return CreateShape(RECT, rect);
}

Shape* CreateCircleShape(int px, int py, int radius) {
    Point* point = CreatePoint(px, py);
    Circle* circle = CreateCircle(point, radius);
    return CreateShape(CIRCLE, circle);
}

Shape* CreatePolygonShape(int lst[], int n) {
    Polygon* polygon = CreatePolygon(lst, n);
    return CreateShape(POLYGON, polygon);
}

void DestroyShape(Shape* shape) {
    switch (shape->shapeType) {
        case POINT:
            DestroyPoint(shape->shape);
            break;
        case LINE:
            DestroyLine(shape->shape);
            break;
        case CIRCLE:
            DestroyCircle(shape->shape);
            break;
        case SQUARE:
            DestroySquare(shape->shape);
            break;
        case RECT:
            DestroyRect(shape->shape);
            break;
        case POLYGON:
            DestroyPolygon(shape->shape);
            break;
    }
    free(shape);
}

Shape* ReadShape() {
    int shapeType;
    printShapesTypes();
    printf("Enter shape type: ");
    scanf("%d", &shapeType);
    void* shape;
    switch (shapeType) {
        case POINT:
            shape = ReadPoint();
            break;
        case LINE:
            shape = ReadLine();
            break;
        case CIRCLE:
            shape = ReadCircle();
            break;
        case SQUARE:
            shape = ReadSquare();
            break;
        case RECT:
            shape = ReadRect();
            break;
        case POLYGON:
            shape = ReadPolygon();
            break;
        default:
            printf("Invalid shape type\n");
            return ReadShape();
    }
    Shape* shapeData = CreateEmptyShape();
    shapeData->shapeType = shapeType;
    shapeData->shape = shape;
    return shapeData;
}

