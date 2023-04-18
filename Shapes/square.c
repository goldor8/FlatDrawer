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
    printf("\tp1: ");
    PrintPoint(square->point);
    printf("\tlength: %d\n", square->length);
}