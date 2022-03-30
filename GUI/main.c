#include <stdio.h>
#define SDL_MAIN_HANDLED
#include <SDL.h>

int main( int argc, char* args[] ) {

        SDL_Window *window = SDL_CreateWindow("SDL2 Window",
                                              SDL_WINDOWPOS_CENTERED,
                                              SDL_WINDOWPOS_CENTERED,
                                              680, 480,
                                              0);

        if(!window)
        {

            return -1;
        }

        SDL_Surface *window_surface = SDL_GetWindowSurface(window);

        if(!window_surface)
        {

            return -1;
        }

        SDL_UpdateWindowSurface(window);

        SDL_Delay(500000);

}