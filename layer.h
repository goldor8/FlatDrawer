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
    int visible;
    ShapeElement* shapeList;
} typedef Layer;

Layer* CreateLayer(char* name);
void DestroyLayer(Layer* layer);
//Add a shape to the layer
void AddShape(Layer* layer, Shape* shape);
//Remove a shape from the layer
int RemoveShape(Layer* layer, int id);
//Draw all the shapes from the layer
void DrawLayer(Screen* screen, Layer* layer);

#endif //FLATDRAWER_LAYER_H
