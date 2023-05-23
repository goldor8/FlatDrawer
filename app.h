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

//Initialize the application
void StartApp();
//Stop the application
void StopApp();
//Draw all the shapes on the screen
void Draw();
//Clear all the shapes from the screen and the layers
void ClearLayersAndShapes();
//Add a layer to the application
Layer* AddLayer(char* name);
//Remove a layer from the application
void RemoveLayer(char* name);
//Get a layer from the application
Layer* GetLayer(char* name);
//List all the layers
void ListLayers();
//Set the active on wich the user will place shapes layer
int SetActiveLayer(char* name);
//ADd a shape to the active layer
void AddShapeToApp(Shape* shape);
//Remove a shape from the app
void RemoveShapeFromApp(int id);
//List all the shapes from the app
void ListShapes();
//Set the screen size
void SetScreenSize(int width, int height);
//Show a layer
void ShowLayer(char* name);
//Hide a layer
void HideLayer(char* name);


#endif //FLATDRAWER_APP_H
