#ifndef GUI_GAME_H
#define GUI_GAME_H
#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>


#define SDL_MAIN_HANDLED
/***
 * @brief Inicia el juego y todo lo necesario para que funcione
 * @param window estancia de ventana de SDL
 * @param renderer renderizador de ventana SDL
 * @param jugador numero de jugador seleccionado por el usuario
 * @return true si el juego se inicio correctamente, false en caso contrario
 */
bool gameInit(SDL_Window *window, SDL_Renderer *renderer,int jugador);

#endif //GUI_GAME_H
