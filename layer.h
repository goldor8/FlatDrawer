//
// Created by Dimitri on 24/03/2023.
//

#ifndef FLATDRAWER_LAYER_H
#define FLATDRAWER_LAYER_H
#include "screen.h"
#include "Shapes/shape.h"

typedef struct shapeNode {
    Shape* data;
    struct shapeNode* next;
} ShapeElement;

struct {
    char* name;
    ShapeElement* shapeList;
} typedef Layer;

Layer* CreateLayer(char* name);
void DestroyLayer(Layer* layer);
void AddShape(Layer* layer, Shape* shape);
int RemoveShape(Layer* layer, int id);
void DrawLayer(Screen* screen, Layer* layer);

#endif //FLATDRAWER_LAYER_H
