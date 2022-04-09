//
// Created by jpabl on 5/04/2022.
//

#include "SelectionMenu.h"
#include "SelectionMenuConstates.h"
#include "../Game/Game.h"

void selectionMenu(SDL_Window *window,SDL_Renderer *renderer){
    SDL_Surface *backgroundImgS = SDL_LoadBMP( "../Imagenes/MenuSeleccion.bmp" );
    SDL_Texture *backgroundS = SDL_CreateTextureFromSurface(renderer, backgroundImgS);
    SDL_FreeSurface(backgroundImgS);

    SDL_Surface *textoSeleccionImg = SDL_LoadBMP( "../Imagenes/Seleccion.bmp" );
    SDL_Texture *textoSeleccion = SDL_CreateTextureFromSurface(renderer, textoSeleccionImg);
    SDL_FreeSurface(textoSeleccionImg);


    bool quit = false;
    while (!quit){
        SDL_SetRenderDrawColor(renderer,0,0,0,SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer,backgroundS,NULL,NULL);
        SDL_RenderPresent(renderer);

        SDL_PollEvent(&event);

        switch (event.type) {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        quit = true;
                        break;
                    case SDLK_RETURN:
                        gameInit(window,renderer,2);
                        break;
                    default:
                        break;
                }
        }



        SDL_Delay(30);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    exit(0);
}

