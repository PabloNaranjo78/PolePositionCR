#include <iso646.h>
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
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    gScreenSurface = SDL_GetWindowSurface(window);


    gBackground = SDL_LoadBMP("../Imagenes/mapa.bmp");
    SDL_Texture *gBackgroundTexture = SDL_CreateTextureFromSurface(renderer, gBackground);
    SDL_FreeSurface(gBackground);

    luigi = SDL_LoadBMP("../Imagenes/luigi.bmp");
    SDL_Texture *luigiTexture = SDL_CreateTextureFromSurface(renderer, luigi);
    SDL_FreeSurface(luigi);

    SDL_Rect luigiRect;
    luigiRect.x = 0;
    luigiRect.y = 500;
    luigiRect.w = 28*2;
    luigiRect.h = 30*2;

    SDL_Rect srcRect;
    SDL_Rect luiRectP;

    luiRectP.x = 29;
    luiRectP.y = 0;
    luiRectP.w = 28;
    luiRectP.h = 30;

    srcRect.x = 0;
    srcRect.y = 1200;
    srcRect.w = SCREEN_WIDTH;
    srcRect.h = SCREEN_HEIGHT;

//    SDL_BlitSurface(gBackground, &srcRect, gScreenSurface, NULL);

    SDL_SetRenderDrawColor( renderer, 0x2F, 0x2F, 0x2F, 0xFF );

    int gameOver = 0;
    while (!gameOver) {

        SDL_SetRenderDrawColor(renderer,0,0,0,SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        srcRect.y -= 5;

        if (srcRect.y < 0) {
            srcRect.y = 1200;
        }
        printf("%d\n", luigiRect.x);
//        SDL_BlitSurface(gBackground, &srcRect, gScreenSurface, NULL);
//        SDL_BlitSurface(luigi, &luiRect, gScreenSurface, NULL);

        SDL_RenderCopy(renderer, gBackgroundTexture, &srcRect, NULL);
        SDL_RenderCopy(renderer, luigiTexture, &luiRectP, &luigiRect);
        SDL_RenderPresent(renderer);
        SDL_PollEvent(&event);



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
                    case SDLK_LEFT:
                        luiRectP.x =0;
                        luigiRect.x -= 15;
                        break;
                    case SDLK_RIGHT:
                        luiRectP.x = 58;
                        luigiRect.x += 15;
                        break;

                    default:
                        luiRectP.x = 29;
                        break;
                }
            default:
                break;

        }

    SDL_Delay(10);
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
