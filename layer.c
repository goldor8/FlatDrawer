//
// Created by Dimitri on 24/03/2023.
//

#include "layer.h"
#include <stdlib.h>

void addShape(Layer* layer, Shape* shape) {
    int i = 0;
    while (layer->shapes[i] != NULL) {
        i++;
    }
    layer->shapes[i] = shape;
}
