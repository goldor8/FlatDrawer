//
// Created by Dimitri on 24/03/2023.
//

#ifndef FLATDRAWER_LAYER_H
#define FLATDRAWER_LAYER_H
#include "screen.h"
#include "Shapes/shape.h"

struct {
    Screen* screen;
    Shape** shapes;
} typedef Layer;

#endif //FLATDRAWER_LAYER_H
