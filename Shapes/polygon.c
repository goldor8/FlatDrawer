//
// Created by Dimitri on 24/03/2023.
//

#include "polygon.h"
#include <stdlib.h>
#include <stdio.h>
#include "line.h"

Polygon* CreatePolygon(Point** points, int count){
    Polygon* polygon = malloc(sizeof(Polygon));
    polygon->points = points;
    polygon->count = count;
    return polygon;
}

void DestroyPolygon(Polygon* polygon){
    for (int i = 0; i < polygon->count; i++) {
        DestroyPoint(polygon->points[i]);
    }
    free(polygon->points);
    free(polygon);
}

void PrintPolygon(Polygon* polygon){
    printf("Polygon with %d points:\n", polygon->count);
    for (int i = 0; i < polygon->count; i++) {
        printf("\tPoint %d: ", i);
        PrintPoint(polygon->points[i]);
    }
}

Polygon* ReadPolygon(){
    int count;
    printf("Enter number of points: ");
    scanf("%d", &count);
    Point** points = malloc(sizeof(Point*) * count);
    for (int i = 0; i < count; i++) {
        printf("Enter point %d: \n", i);
        points[i] = ReadPoint();
    }
    return CreatePolygon(points, count);
}

void DrawPolygon(Screen* screen, Polygon* polygon){
    for (int i = 0; i < polygon->count; ++i) {
        Point *pa = polygon->points[i];
        Point *pb = polygon->points[(i + 1) % polygon->count];
        StaticDrawLine(screen, pa->x, pa->y, pb->x, pb->y);
    }
}