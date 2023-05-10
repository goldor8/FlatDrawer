//
// Created by Dimitri on 24/03/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include "screen.h"

Screen* CreateScreen(int width, int height, char background, char foreground){
    Screen* screen = (Screen*) malloc(sizeof(Screen));
    screen->width = width;
    screen->height = height;
    screen->background = background;
    screen->foreground = foreground;
    screen->buffer = (char**) malloc(sizeof(char*) * height);
    for (int i = 0; i < height; ++i) {
        screen->buffer[i] = (char*) malloc(sizeof(char) * width+1);
        for (int j = 0; j < width; ++j) {
            screen->buffer[i][j] = background;
        }
        screen->buffer[i][width] = '\0';
    }
    return screen;
}

void DestroyScreen(Screen* screen){
    for (int i = 0; i < screen->height; ++i) {
        free(screen->buffer[i]);
    }
    free(screen->buffer);
    free(screen);
}

void Set(Screen* screen, int x, int y){
    screen->buffer[y][x] = screen->foreground;
}

void Clear(Screen* screen){
    for (int i = 0; i < screen->height; ++i) {
        for (int j = 0; j < screen->width; ++j) {
            screen->buffer[i][j] = screen->background;
        }
    }
}

void Display(Screen* screen){
    for (int i = 0; i < screen->height; ++i) {
        printf("%s\n", screen->buffer[i]);
    }
}