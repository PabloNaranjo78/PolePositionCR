#include <iso646.h>
#include "Game.h"
#include "GameConstantes.h"
#include "../../Clientes/Cliente.h"
#include "../../cJSON/cJSON.h"

#define SDL_MAIN_HANDLED


bool gameInit(SDL_Window *window, SDL_Renderer *renderer, int jugador) {

    SDL_Event event;
    SDL_Surface *gBackground = SDL_LoadBMP("../Imagenes/Pruebafondo.bmp");
    SDL_Texture *gBackgroundTexture = SDL_CreateTextureFromSurface(renderer, gBackground);
    SDL_FreeSurface(gBackground);

  //  SDL_Surface *puntosVidaDisparo = NULL;
  //  puntosVidaDisparo = SDL_LoadBMP("../Imagenes/PuntosVidaDisparo.bmp");
    //SDL_Texture *puntosVidaDisparoTexture = SDL_CreateTextureFromSurface(renderer, puntosVidaDisparo);

    thisplayer = SDL_LoadBMP(texturasJugadores[jugador]);
    SDL_Texture *luigiTexture = SDL_CreateTextureFromSurface(renderer, thisplayer);
    SDL_FreeSurface(thisplayer);

    SDL_Rect playerPos;
    playerPos.x = 305;
    playerPos.y = 500;
    playerPos.w = 28 * 2;
    playerPos.h = 30 * 2;

    SDL_Rect playerSprite;
    playerSprite.x = 29;
    playerSprite.y = 0;
    playerSprite.w = 28;
    playerSprite.h = 30;

    SDL_Rect backgroundPos;
    backgroundPos.x = 0;
    backgroundPos.y = 0;
    backgroundPos.w = 600;
    backgroundPos.h = 400;

    SDL_SetRenderDrawColor(renderer, 0x2F, 0x2F, 0x2F, 0xFF);

    bool derecha = false;
    bool izquierda = false;

    SDL_Surface *tempJugador = SDL_LoadBMP(texturasJugadores[1]);
    SDL_Texture *jugadorTexture = SDL_CreateTextureFromSurface(renderer, tempJugador);
    SDL_FreeSurface(tempJugador);
    SDL_Rect jugadorPostemp;

    SDL_Rect jugadorSpritetemp;
    jugadorSpritetemp.x = 29;
    jugadorSpritetemp.y = 0;
    jugadorSpritetemp.w = 28;
    jugadorSpritetemp.h = 30;

    int gameOver = 0;
    while (!gameOver) {

        cJSON *json = NULL;
        json = cJSON_CreateObject();
        cJSON *jugadorJSON = NULL;
        jugadorJSON = cJSON_CreateObject();

        cJSON_AddNumberToObject(jugadorJSON, "posX", playerPos.x);
        cJSON_AddNumberToObject(jugadorJSON, "Km", kilometro);
        cJSON_AddBoolToObject(jugadorJSON,"Disparo",true);
        cJSON_AddNumberToObject(jugadorJSON, "vidas", vidas);
        cJSON_AddNumberToObject(jugadorJSON, "puntos", puntos);

    //    printf("%s\n", cJSON_Print(jugadorJSON));

        cJSON_AddItemToObject(json,jugadoresNombre[jugador], jugadorJSON);

        char *str = cJSON_Print(json);
   //     printf("%s\n", str);
        char *respuesta = makeRequest(false, str);
        printf("%s-> %s\n",jugadoresNombre[jugador], respuesta);

        cJSON *jsonRespuesta = cJSON_Parse(respuesta);


     //   printf("->>>>>%s\n", cJSON_Print(jsonRespuesta));

//        cJSON *Hueco;
//        Hueco = cJSON_GetObjectItem(jsonRespuesta, "Hueco");
//
//        printf("%s\n", cJSON_Print(Hueco));
//
//        cJSON *posYHueco;
//        posYHueco = cJSON_GetObjectItem(Hueco, "kilometro");
//
//        char *stRRR = cJSON_Print(Hueco);
//        printf("hueco->%.2f\n", posYHueco->valuedouble);


        cJSON *jugadorRespuesta;
        cJSON *jugadoresLista = cJSON_GetObjectItem(jsonRespuesta,"listaJugadores");
        cJSON *head;
        listaEnalzadaJugadores = crearLista(listaEnalzadaJugadores);
        head = cJSON_GetObjectItem(jugadoresLista, "head");


     //   print_list(listaEnalzadaJugadores);

     //   printf("%s\n", cJSON_Print(jugadoresLista));

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);


        backgroundPos.y += velocidad;
        if (backgroundPos.y > 6000) {
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

        JugadoresLista *aux = listaEnalzadaJugadores->nextNode;


        if (aux->jugador!=jugador){
                printf("pintando jugador %d\n", aux->jugador);

                jugadorPostemp.x = aux->posX;
                jugadorPostemp.y = 500;
                jugadorPostemp.w = 28 * 2;
                jugadorPostemp.h = 30 * 2;

                SDL_RenderCopy(renderer, jugadorTexture, &jugadorSpritetemp, &jugadorPostemp);
            }


        SDL_RenderCopy(renderer, gBackgroundTexture, &backgroundPos, NULL);
        SDL_RenderCopy(renderer, luigiTexture, &playerSprite, &playerPos);
        //SDL_RenderCopy(renderer, puntosVidaDisparoTexture, NULL,NULL);
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


        if (derecha and velocidad!=0) {
            playerPos.x += 10;
        }
        if (izquierda and velocidad!=0) {
            playerPos.x -= 10;
        }

        if (velocidad == velocidades[1]) {
            kilometro+= 0.0005f;
        }
        if (velocidad == velocidades[2]) {
            kilometro+= 0.001f;
        }

        if (puntosCounter < 0) {
            puntosCounter = 333;
            puntos++;
        }
        puntosCounter--;
       // printf("%d\n",puntosCounter);
     //   printf("%f\n", kilometro);


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
