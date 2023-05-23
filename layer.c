//
// Created by Dimitri on 24/03/2023.
//

#include "layer.h"
#include <stdlib.h>
#include <string.h>

Layer* CreateLayer(char* name) {
    Layer* layer = malloc(sizeof(Layer));
    layer->name = strcpy(malloc(strlen(name) + 1), name);
    layer->shapeList = NULL;
    return layer;
}

void DestroyLayer(Layer* layer) {
    ShapeElement* current = layer->shapeList;
    while (current != NULL) {
        ShapeElement* next = current->next;
        DestroyShape(current->data);
        free(current);
        current = next;
    }
    free(layer->name);
    free(layer);
}

void AddShape(Layer* layer, Shape* shape) {
    ShapeElement* current = layer->shapeList;
    if (current == NULL) { // empty list
        layer->shapeList = malloc(sizeof(ShapeElement));
        layer->shapeList->data = shape;
        layer->shapeList->next = NULL;
        return;
    }

    while (current->next != NULL) { // find last element
        current = current->next;
    }
    current->next = malloc(sizeof(ShapeElement));
    current->next->data = shape;
    current->next->next = NULL;
}

int RemoveShape(Layer* layer, int id) {
    ShapeElement* current = layer->shapeList;
    ShapeElement* previous = NULL;
    while (current != NULL) {
        if (current->data->id == id) {
            if (previous == NULL) {
                layer->shapeList = current->next;
            } else {
                previous->next = current->next;
            }
            DestroyShape(current->data);
            free(current);
            return 1;
        }
        previous = current;
        current = current->next;
    }
    return 0;
}

void DrawLayer(Screen* screen, Layer* layer) {
    ShapeElement* current = layer->shapeList;
    while (current != NULL) {
        DrawShape(screen, current->data);
        current = current->next;
    }
}