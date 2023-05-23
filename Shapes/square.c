//
// Created by Dimitri on 24/03/2023.
//

#include "square.h"
#include <stdlib.h>
#include <stdio.h>

Square* CreateSquare(Point* point, int length){
    Square* square = malloc(sizeof(Square));
    square->point = point;
    square->length = length;
    return square;
}

void DestroySquare(Square* square){
    DestroyPoint(square->point);
    free(square);
}

void PrintSquare(Square* square){
    printf("Square: \n");
    PrintPointName(square->point, "\ttop left");
    printf("\tlength: %d\n", square->length);
}

Square* ReadSquare(){
    printf("Enter top left point: \n");
    Point* point = ReadPoint();
    int length;
    printf("Enter length: ");
    scanf("%d", &length);
    return CreateSquare(point, length);
}

void DrawSquare(Screen* screen, Square* square){
    int x = square->point->x;
    int y = square->point->y;
    int length = square->length;

    for(int i = 0; i < length; i++){
        Set(screen, x + i, y);
        Set(screen, x + i, y + length - 1);
        Set(screen, x, y + i);
        Set(screen, x + length - 1, y + i);
    }
}