#include <stdio.h>
#include <stdlib.h>
#include "layer.h"

static int running = 1;
static Layer* layer = NULL;

void AppAddShape() {
    AddShape(layer, ReadShape());
}

void AppRemoveShape() {
    printf("Enter shape id: ");
    int id;
    scanf("%d", &id);
    RemoveShape(layer, id);
}

void AppPrintShapes() {
    ShapeElement* current = layer->shapeList;
    while (current != NULL) {
        PrintShape(current->data);
        current = current->next;
    }
}

void App() {
    layer = CreateLayer("test");

    while(running){
        printf("What do you want to do?\n");
        printf("1. Add a shape\n");
        printf("2. Remove a shape\n");
        printf("3. Print all shapes\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                AppAddShape();
                break;
            case 2:
                AppRemoveShape();
                break;
            case 3:
                AppPrintShapes();
                break;
            case 4:
                running = 0;
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    DestroyLayer(layer);
}

int main() {
    printf("Hello, World!\n");
    App();
    return 0;
}