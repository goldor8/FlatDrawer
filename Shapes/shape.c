//
// Created by Dimitri on 24/03/2023.
//

#include "shape.h"
#include <stdlib.h>
#include <stdio.h>
#include "point.h"
#include "line.h"
#include "circle.h"

Shape* CreateShape(enum ShapeType type, int id, void* genericShape) {
    Shape* shape = malloc(sizeof(Shape));
    shape->shapeType = type;
    shape->id = id;
    shape->shape = genericShape;
    return shape;
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
            break;
        case RECT:
            break;
        case POLYGON:
            break;
    }
    free(shape);
}
