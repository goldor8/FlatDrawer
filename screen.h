//
// Created by Dimitri on 24/03/2023.
//

#ifndef FLATDRAWER_SCREEN_H
#define FLATDRAWER_SCREEN_H

struct {
    char** buffer;
    int width;
    int height;
    char background;
    char foreground;
} typedef Screen;

Screen* CreateScreen(int width, int height, char background, char foreground);
void DestroyScreen(Screen* screen);
//Set the pixel at the given coordinates to the foreground character
void Set(Screen* screen, int x, int y);
//Reset the screen to the background character
void ClearScreen(Screen* screen);
//Display the screen on the console
void DisplayScreen(Screen* screen);


#endif //FLATDRAWER_SCREEN_H
