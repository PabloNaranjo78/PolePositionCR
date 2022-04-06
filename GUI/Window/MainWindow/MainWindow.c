//
// Created by jpabl on 5/04/2022.
//
#include "MainWindow.h"
#include "MainWindowConstantes.h"
#include "../SelectionMenu/SelectionMenu.h"


void mainWindow(){

    window = SDL_CreateWindow(
            "PolePosition",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN
    );

    renderer = SDL_CreateRenderer(
            window,
            -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    SDL_Surface *backgroundImg = SDL_LoadBMP( "../Imagenes/MenuFondo.bmp" );
    SDL_Texture *background = SDL_CreateTextureFromSurface( renderer, backgroundImg );
    SDL_FreeSurface(backgroundImg);
    SDL_Rect *backgroundRect;
    backgroundRect->x = 0;
    backgroundRect->y = 0;
    backgroundRect->w = SCREEN_WIDTH;
    backgroundRect->h = SCREEN_HEIGHT;


    int quit = 0;
    int gameOver = 0;
    while (!gameOver) {

        SDL_SetRenderDrawColor(renderer,0,0,0,SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);


        SDL_RenderCopy(renderer, background, backgroundRect, NULL);
        SDL_RenderPresent(renderer);
        SDL_PollEvent(&event);

        if (backgroundRect->x>898) {
            backgroundRect->x = 0;
        }else{
            backgroundRect->x += 1;
        }



        switch (event.type) {

            case SDL_QUIT:
                gameOver = 1;
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        gameOver = 1;
                        break;
                    case SDLK_RETURN:
                        selectionMenu(window,renderer);
                        break;
                    default:
                        break;
                }
            default:
                break;

        }

        SDL_Delay(30);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

