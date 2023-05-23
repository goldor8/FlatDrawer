//
// Created by Dimitri on 24/03/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "app.h"
#include "commands.h"
#include "layer.h"

int running = 0;
LayerElement* layers = NULL;
Layer* activeLayer = NULL;
Screen* screen = NULL;

void ClearLayersAndShapes(){
    LayerElement* current = layers;
    while (current != NULL) {
        LayerElement* next = current->next;
        DestroyLayer(current->data);
        free(current);
        current = next;
    }
    layers = NULL;
}

void StartApp() {
    running = 1;
    printf("Welcome to FlatDrawer!\n");
    screen = CreateScreen(100, 100, '.', '#');
    activeLayer = AddLayer("default");

    InitCommands();

    printf("Type 'help' for a list of commands.\n");
    while (running) {
        ReadCommand();
    }

    DestroyScreen(screen);
    FreeCommands();
    printf("Goodbye!\n");
}

void StopApp() {
    running = 0;
}

Layer* AddLayer(char* name){
    Layer* layer = CreateLayer(name);
    LayerElement* newLayer = malloc(sizeof(LayerElement));
    newLayer->data = layer;
    newLayer->next = NULL;

    if(layers == NULL) {
        layers = newLayer;
        printf("Layer '%s' added.\n", layer->name);
        return layer;
    }

    LayerElement* current = layers;
    while (current != NULL) {
        if(strcmp(current->data->name, layer->name) == 0) {
            printf("Layer with name '%s' already exists.\n", current->data->name);
            DestroyLayer(layer);
            return NULL;
        }
        if(current->next == NULL) {
            current->next = newLayer;
            break;
        }
        current = current->next;
    }

    printf("Layer '%s' added.\n", layer->name);
    return layer;
}

Layer* GetLayer(char* name){
    LayerElement* current = layers;
    while (current != NULL) {
        if(strcmp(current->data->name, name) == 0) {
            return current->data;
        }
        current = current->next;
    }
    return NULL;
}

void RemoveLayer(char* name){
    LayerElement* current = layers;
    LayerElement* previous = NULL;
    while (current != NULL) {
        if (strcmp(current->data->name, name) == 0) {
            if (previous == NULL) {
                layers = current->next;
            } else {
                previous->next = current->next;
            }

            if(current->data == activeLayer) {
                activeLayer = NULL;
            }

            printf("Layer '%s' removed.\n", name);
            DestroyLayer(current->data);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Layer with name '%s' does not exist.\n", name);
}

void Draw(){
    ClearScreen(screen);
    LayerElement* current = layers;
    while (current != NULL) {
        if(current->data->visible == 1) {
            DrawLayer(screen, current->data);
        }
        current = current->next;
    }
    DisplayScreen(screen);
}

void ListLayers(){
    LayerElement* current = layers;
    while (current != NULL) {
        printf("%s", current->data->name);
        if(current->data == activeLayer) {
            printf(" (active)");
        }
        printf("\n");
        current = current->next;
    }
}

int SetActiveLayer(char* name){
    Layer* layer = GetLayer(name);
    if(layer != NULL){
        activeLayer = layer;
        printf("Layer '%s' is now active.\n", name);
        return 1;
    }
    printf("Layer with name '%s' does not exist.\n", name);
    return 0;
}

void AddShapeToApp(Shape* shape){
    if(activeLayer == NULL) {
        printf("No active layer.\n");
        return;
    }
    AddShape(activeLayer, shape);
    printf("Shape added to layer '%s'.\n", activeLayer->name);
}

void RemoveShapeFromApp(int id){
    LayerElement *current = layers;
    while (current != NULL) {
        if (RemoveShape(current->data, id)) {
            printf("Shape with id '%d' removed from layer '%s'.\n", id, current->data->name);
            return;
        }
        current = current->next;
    }

    printf("Shape with id '%d' does not exist.\n", id);
}

void ListShapes(){
    LayerElement* current = layers;
    while (current != NULL) {
        printf("######################################################################\n");
        printf("Layer '%s':\n", current->data->name);
        ShapeElement* shape = current->data->shapeList;
        while (shape != NULL) {
            PrintShape(shape->data);
            shape = shape->next;
        }
        current = current->next;
    }
}

void SetScreenSize(int width, int height){
    if(width < 1 || height < 1) {
        printf("Invalid screen size.\n");
        return;
    }
    DestroyScreen(screen);
    screen = CreateScreen(width, height, '.', '#');
    printf("Screen size set to %dx%d.\n", width, height);
}

void ShowLayer(char* name){
    GetLayer(name)->visible = 1;
    printf("Layer '%s' is now visible.\n", name);
}

void HideLayer(char* name){
    GetLayer(name)->visible = 0;
    printf("Layer '%s' is now hidden.\n", name);
}