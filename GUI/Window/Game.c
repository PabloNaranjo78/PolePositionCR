#include "Game.h"
#include "GameConstantes.h"
#define SDL_MAIN_HANDLED

bool gameInit() {

    window = SDL_CreateWindow(
        "Game",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN
    );

    renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED
    );

    gScreenSurface = SDL_GetWindowSurface(window);

    gBackground = SDL_LoadBMP("../Imagenes/Pepe.bmp");

    SDL_BlitSurface(gBackground, NULL, gScreenSurface, NULL);



    int gameOver = 0;
    while (!gameOver) {

        SDL_UpdateWindowSurface(window);

        SDL_PollEvent(&event);

        switch (event.type) {

            case SDL_QUIT:
                gameOver = 1;
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        gameOver = 1;
                        break;

                }
                break;
        }

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();


    return true;
}

bool loadMedia()
{


    return true;
}
