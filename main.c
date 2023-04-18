#include <stdio.h>
#include "app.h"
#include "shapes/point.h"
#include "shapes/circle.h"
#include "shapes/line.h"
#include "shapes/shape.h"
#include "layer.h"

int main() {
    Point *a = CreatePoint(1, 2);
    Point *b = CreatePoint(3, 4);
    Line *line = CreateLine(a, b);
    Circle *circle = CreateCircle(a, 5);
    return 0;
}
