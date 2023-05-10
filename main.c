#include <stdio.h>
#include <stdlib.h>
#include "app.h"
#include "shapes/shape.h"
#include "shapes/point.h"
#include "shapes/circle.h"
#include "shapes/line.h"
#include "Shapes/polygon.h"
#include "Shapes/point.h"
#include "Shapes/rect.h"
#include "Shapes/square.h"

int main() {
    printf("Hello, World!\n");
    Point* p1 = CreatePoint(10, 10);
    Point* p2 = CreatePoint(50, 80);
    Line* line = CreateLine(p1, p2);
    Screen* screen = CreateScreen(100, 100, '.', '#');
    DrawLine(screen, line);
    Display(screen);
    DestroyScreen(screen);
    DestroyLine(line);
    return 0;
}
