//
// Created by Dimitri on 24/03/2023.
//

#ifndef FLATDRAWER_LAYER_H
#define FLATDRAWER_LAYER_H
#include "screen.h"
#include "Shapes/shape.h"

struct shapeNode {
    Shape* data;
    struct shapeNode* next;
};
typedef struct shapeNode ShapeElement;

struct {
    Screen* screen;
    ShapeElement* shapeList;
} typedef Layer;

Layer* CreateLayer(Screen* screen);
void DestroyLayer(Layer* layer);
void AddShape(Layer* layer, Shape* shape);
void RemoveShape(Layer* layer, int id);

#endif //FLATDRAWER_LAYER_H
