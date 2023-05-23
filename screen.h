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
void Set(Screen* screen, int x, int y);
void ClearScreen(Screen* screen);
void DisplayScreen(Screen* screen);


#endif //FLATDRAWER_SCREEN_H
