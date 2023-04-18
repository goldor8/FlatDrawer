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
    Shape** shapes = malloc(sizeof(Shape*) * 3);
    shapes[0] = CreatePointShape(1, 2);
    shapes[1] = CreateLineShape(1, 2, 3, 4);
    shapes[2] = CreateCircleShape(1, 2, 3);
    for (int i = 0; i < 3; i++) {
        PrintShape(shapes[i]);
        DestroyShape(shapes[i]);
    }
    return 0;
}
