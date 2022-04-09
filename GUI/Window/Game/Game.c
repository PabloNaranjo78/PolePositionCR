#include <iso646.h>
#include "Game.h"
#include "GameConstantes.h"

#define SDL_MAIN_HANDLED


bool gameInit(SDL_Window *window, SDL_Renderer *renderer, int jugador) {

    SDL_Event event;
    SDL_Surface *gBackground = SDL_LoadBMP("../Imagenes/Pruebafondo.bmp");
    SDL_Texture *gBackgroundTexture = SDL_CreateTextureFromSurface(renderer, gBackground);
    SDL_FreeSurface(gBackground);

    luigi = SDL_LoadBMP(texturasJugadores[jugador]);
    SDL_Texture *luigiTexture = SDL_CreateTextureFromSurface(renderer, luigi);
    SDL_FreeSurface(luigi);

    SDL_Rect playerPos;
    playerPos.x = 305;
    playerPos.y = 500;
    playerPos.w = 28 * 2;
    playerPos.h = 30 * 2;

    SDL_Rect backgroundPos;
    SDL_Rect playerSprite;

    playerSprite.x = 29;
    playerSprite.y = 0;
    playerSprite.w = 28;
    playerSprite.h = 30;

    backgroundPos.x = 0;
    backgroundPos.y = 0;
    backgroundPos.w = 900;
    backgroundPos.h = 600;

    SDL_SetRenderDrawColor(renderer, 0x2F, 0x2F, 0x2F, 0xFF);

    bool derecha = false;
    bool izquierda = false;

    int gameOver = 0;
    while (!gameOver) {

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);


        backgroundPos.y += 600;
        if (backgroundPos.y > 2400) {
           backgroundPos.y = 0;
        }

        if (playerPos.x > 750) {
            playerPos.x = 750;
            derecha = false;
            playerSprite.x = 29;
        } else if (playerPos.x < 310) {
            playerPos.x = 310;
            izquierda = false;
            playerSprite.x = 29;
        }


        SDL_RenderCopy(renderer, gBackgroundTexture, &backgroundPos, NULL);
        SDL_RenderCopy(renderer, luigiTexture, &playerSprite, &playerPos);
        SDL_RenderPresent(renderer);
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
                    case SDLK_LEFT:
                        playerSprite.x = 0;
                        izquierda = true;
                        derecha = false;
                        break;
                    case SDLK_RIGHT:
                        playerSprite.x = 58;
                        izquierda = false;
                        derecha = true;
                        velocidad = velocidades[1];
                        break;
                    case SDLK_UP:
                        playerSprite.x = 29;
                        derecha = false;
                        izquierda = false;
                        velocidad = velocidades[2];
                        break;
                    case SDLK_DOWN:
                        playerSprite.x = 29;
                        derecha = false;
                        izquierda = false;
                        velocidad = velocidades[0];
                        break;

                    default:
                        playerSprite.x = 29;
                        break;
                }
            default:
                break;

        }

        if (derecha) {
            playerPos.x += 10;
        }
        if (izquierda) {
            playerPos.x -= 10;
        }

        SDL_Delay(30);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    exit(0);
}

bool loadMedia() {


    return true;
}
