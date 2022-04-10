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

    SDL_Rect textoSeleccionRect;
    textoSeleccionRect.x = 335;
    textoSeleccionRect.y = 85;
    textoSeleccionRect.w = 840;
    textoSeleccionRect.h = 40;

    SDL_Surface *personajesIMG = SDL_LoadBMP( "../Imagenes/Personajes.bmp" );
    SDL_Texture *personajes = SDL_CreateTextureFromSurface(renderer, personajesIMG);
    SDL_FreeSurface(personajesIMG);

    SDL_Rect luigiPos, marioPos, peachPos, yoshiPos;

    luigiPos.x = 239;
    luigiPos.y = 290;
    luigiPos.w = 27*3;
    luigiPos.h = 29*3;

    marioPos.x = 355;
    marioPos.y = 290;
    marioPos.w = 27*3;
    marioPos.h = 29*3;

    peachPos.x = 471;
    peachPos.y = 290;
    peachPos.w = 27*3;
    peachPos.h = 29*3;

    yoshiPos.x = 587;
    yoshiPos.y = 290;
    yoshiPos.w = 27*3;
    yoshiPos.h = 29*3;


    SDL_Rect luigiAnimation, marioAnimation, peachAnimation, yoshiAnimation;
    luigiAnimation.x = 0;
    luigiAnimation.y = 0;
    luigiAnimation.w = 27;
    luigiAnimation.h = 29;

    marioAnimation.x = 0;
    marioAnimation.y = 29;
    marioAnimation.w = 27;
    marioAnimation.h = 29;

    peachAnimation.x = 0;
    peachAnimation.y = 58;
    peachAnimation.w = 27;
    peachAnimation.h = 29;

    yoshiAnimation.x = 0;
    yoshiAnimation.y = 87;
    yoshiAnimation.w = 27;
    yoshiAnimation.h = 29;

    SDL_Surface *flechaImg = SDL_LoadBMP( "../Imagenes/flecha.bmp" );
    SDL_Texture *flecha = SDL_CreateTextureFromSurface(renderer, flechaImg);
    SDL_FreeSurface(flechaImg);

    SDL_Rect flechaPos;
    flechaPos.x = posSelection[seleccion];
    flechaPos.y = 261;
    flechaPos.w = 39;
    flechaPos.h = 20;


    bool quit = false;
    while (!quit){
        SDL_SetRenderDrawColor(renderer,0,0,0,SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        textoSeleccionRect.x--;
        if (textoSeleccionRect.x < -140){
            textoSeleccionRect.x = 335+230;
        }

        if (frameAnimation >3){
            if (seleccion ==0){
                luigiAnimation.x += 27;
                if (luigiAnimation.x > 351-27){
                    luigiAnimation.x = 0;
                }
                marioAnimation.x = 0;
                peachAnimation.x = 0;
                yoshiAnimation.x = 0;
            }
            if (seleccion ==1){
                marioAnimation.x += 27;
                if (marioAnimation.x > 351-27){
                    marioAnimation.x = 0;
                }
                luigiAnimation.x = 0;
                peachAnimation.x = 0;
                yoshiAnimation.x = 0;
            }
            if (seleccion ==2){
                peachAnimation.x += 27;
                if (peachAnimation.x > 351-27){
                    peachAnimation.x = 0;
                }
                luigiAnimation.x = 0;
                marioAnimation.x = 0;
                yoshiAnimation.x = 0;
            }
            if (seleccion ==3){
                yoshiAnimation.x += 27;
                if (yoshiAnimation.x > 351-27){
                    yoshiAnimation.x = 0;
                }
                luigiAnimation.x = 0;
                marioAnimation.x = 0;
                peachAnimation.x = 0;
            }
            frameAnimation = 0;
        }

        frameAnimation++;


        if (seleccion<0){
            seleccion = 3;
        }
        if (seleccion>3){
            seleccion = 0;
        }

        flechaPos.x = posSelection[seleccion];

        SDL_RenderCopy(renderer,flecha,NULL,&flechaPos);
        SDL_RenderCopy(renderer,textoSeleccion,NULL,&textoSeleccionRect);
        SDL_RenderCopy(renderer,backgroundS,NULL,NULL);


        SDL_RenderCopy(renderer,personajes,&luigiAnimation,&luigiPos);
        SDL_RenderCopy(renderer,personajes,&marioAnimation,&marioPos);
        SDL_RenderCopy(renderer,personajes,&peachAnimation,&peachPos);
        SDL_RenderCopy(renderer,personajes,&yoshiAnimation,&yoshiPos);
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
                        gameInit(window,renderer,seleccion);
                        break;
                    case SDLK_LEFT:
                        seleccion--;
                        break;
                    case SDLK_RIGHT:
                        seleccion++;
                        break;
                    default:
                        break;
                }
        }
 //       printf("%d\n",seleccion);



        SDL_Delay(30);
    }

    exit(0);

}

