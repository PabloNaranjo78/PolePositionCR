#ifndef GUI_GAME_H
#define GUI_GAME_H
#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#define SDL_MAIN_HANDLED
bool gameInit();

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();


#endif //GUI_GAME_H
