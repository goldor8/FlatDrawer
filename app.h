//
// Created by Dimitri on 24/03/2023.
//

#ifndef FLATDRAWER_APP_H
#define FLATDRAWER_APP_H

#include "layer.h"

typedef struct layerNode {
    Layer* data;
    struct layerNode* next;
} LayerElement;

void StartApp();
void StopApp();
void Draw();
void ClearLayersAndShapes();
Layer* AddLayer(char* name);
void RemoveLayer(char* name);
void ListLayers();
int SetActiveLayer(char* name);
void AddShapeToApp(Shape* shape);
void RemoveShapeFromApp(int id);
void ListShapes();
void SetScreenSize(int width, int height);


#endif //FLATDRAWER_APP_H
