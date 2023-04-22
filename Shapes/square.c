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

void DrawSquare(Screen* screen, Square* square, char c);

void PrintSquare(Square* square){
    printf("Square: \n");
    PrintPointName(square->point, "\tp1: ");
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