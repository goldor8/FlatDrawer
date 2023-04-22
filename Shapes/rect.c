//
// Created by Dimitri on 24/03/2023.
//

#include "rect.h"
#include <stdlib.h>
#include <stdio.h>

Rect* CreateRect(Point* p1, int width, int height){
    Rect* rect = malloc(sizeof(Rect));
    rect->p1 = p1;
    rect->width = width;
    rect->height = height;
    return rect;
}

void DestroyRect(Rect* rect){
    DestroyPoint(rect->p1);
    free(rect);
}

void DrawRect(Screen* screen, Rect* rect, char c);

void PrintRect(Rect* rect){
    printf("Rect: \n");
    PrintPointName(rect->p1, "\ttop left");
    printf("\twidth: %d\n", rect->width);
    printf("\theight: %d\n", rect->height);
}

Rect* ReadRect(){
    printf("Enter top left point: \n");
    Point* point = ReadPoint();
    int width;
    int height;
    printf("Enter width: ");
    scanf("%d", &width);
    printf("Enter height: ");
    scanf("%d", &height);
    return CreateRect(point, width, height);
}