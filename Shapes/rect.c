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
    printf("\tp1: ");
    PrintPoint(rect->p1);
    printf("\twidth: %d\n", rect->width);
    printf("\theight: %d\n", rect->height);
}