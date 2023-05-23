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
        screen->buffer[i] = (char*) malloc(sizeof(char) * width);
        for (int j = 0; j < width; ++j) {
            screen->buffer[i][j] = background;
        }
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

int IsOnScreen(Screen* screen, int x, int y){
    if(x < 0 || x >= screen->width || y < 0 || y >= screen->height){
        return 0;
    }
    return 1;
}

void Set(Screen* screen, int x, int y){
    if(!IsOnScreen(screen, x, y)) return;
    screen->buffer[y][x] = screen->foreground;
}

void ClearScreen(Screen* screen){
    for (int i = 0; i < screen->height; ++i) {
        for (int j = 0; j < screen->width; ++j) {
            screen->buffer[i][j] = screen->background;
        }
    }
}

void DisplayScreen(Screen* screen){
    //Concatenate all chars into a single string with spaces between chars and newlines between rows
    char* buffer = (char*) malloc(sizeof(char) * (2 * screen->width * screen->height + screen->height + 1));
    int index = 0;
    for (int i = 0; i < screen->height; ++i) {
        for (int j = 0; j < screen->width; ++j) {
            buffer[index++] = screen->buffer[i][j];
            buffer[index++] = ' ';
        }
        buffer[index++] = '\n';
    }
    buffer[index] = '\0';
    printf("%s", buffer);
}