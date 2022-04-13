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

   JugadorPlantilla *thisPlayer = NULL;
   thisPlayer = (JugadorPlantilla *)malloc(sizeof(JugadorPlantilla));
   thisPlayer->nombre = jugador;
   thisPlayer->posX = 0;
   thisPlayer->posY = 0;
   thisPlayer->kilometro = 0.0f;
   thisPlayer->velocidad = velocidades[1];
   thisPlayer->vidas = 3;
   thisPlayer->puntos = 0;


   thisPlayer->image = SDL_LoadBMP(texturasJugadores[jugador]);
   thisPlayer->texture = SDL_CreateTextureFromSurface(renderer, thisPlayer->image);
   SDL_FreeSurface(thisPlayer->image);

    thisPlayer->position.x = posicionesXiniciales[jugador];
    thisPlayer->position.y = 500;
    thisPlayer->position.w = 28 * 2;
    thisPlayer->position.h = 30 * 2;

    thisPlayer->playerSprite.x = 29;
    thisPlayer->playerSprite.y = 0;
    thisPlayer->playerSprite.w = 28;
    thisPlayer->playerSprite.h = 30;


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

        cJSON_AddNumberToObject(jugadorJSON, "posX", thisPlayer->position.x);
        cJSON_AddNumberToObject(jugadorJSON, "Km", thisPlayer->kilometro);
        cJSON_AddBoolToObject(jugadorJSON,"Disparo",true);
        cJSON_AddNumberToObject(jugadorJSON, "vidas", thisPlayer->vidas);
        cJSON_AddNumberToObject(jugadorJSON, "puntos", thisPlayer->puntos);


        cJSON_AddItemToObject(json,jugadoresNombre[jugador], jugadorJSON);

        char *str = cJSON_Print(json);
        char *respuesta = makeRequest(false, str);
        printf("%s-> %s\n",jugadoresNombre[jugador], respuesta);

        cJSON *jsonRespuesta = cJSON_Parse(respuesta);

        printf("->>>>>%s\n", cJSON_Print(jsonRespuesta));


        cJSON *jugadoresLista = cJSON_GetObjectItem(jsonRespuesta,"listaJugadores");
        cJSON *head;
        listaEnalzadaJugadores = crearLista(listaEnalzadaJugadores);
        head = cJSON_GetObjectItem(jugadoresLista, "head");

        while(head!=NULL){
            jugadorTemp = cJSON_GetObjectItem(head, "nombre")->valueint;
            posXTemp = cJSON_GetObjectItem(head, "posX")->valueint;
            kilometroTemp = cJSON_GetObjectItem(head, "Km")->valuedouble;
            vidasTemp = cJSON_GetObjectItem(head, "vidas")->valueint;
            puntosTemp = cJSON_GetObjectItem(head, "puntos")->valueint;
            listaEnalzadaJugadores = actualizarLista(listaEnalzadaJugadores, jugadorTemp,
                                                     posXTemp, kilometroTemp,false,
                                                     vidasTemp, puntosTemp);
            head = cJSON_GetObjectItem(head, "nextJugador");
        }
        print_list(listaEnalzadaJugadores);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        backgroundPos.y += thisPlayer->velocidad;
        if (backgroundPos.y > 6000) {
           backgroundPos.y = 0;
        }

        if (thisPlayer->position.x > 750) {
            thisPlayer->position.x = 750;
            derecha = false;
            thisPlayer->playerSprite.x = 29;
        } else if (thisPlayer->position.x < 310) {
            thisPlayer->position.x = 310;
            izquierda = false;
            thisPlayer->playerSprite.x = 29;
        }
        JugadoresLista *aux = listaEnalzadaJugadores;

        SDL_RenderCopy(renderer, gBackgroundTexture, &backgroundPos, NULL);

        while (aux != NULL){
            if (aux->jugador != jugador) {
                printf("pintando jugador %d en %d\n", aux->jugador,aux->posX);
                JugadorPlantilla *jugadorPlantillaTemp;
                jugadorPlantillaTemp = (JugadorPlantilla *) malloc(sizeof(JugadorPlantilla));
                jugadorPlantillaTemp->nombre = aux->jugador;
                jugadorPlantillaTemp->posX = aux->posX;
                jugadorPlantillaTemp->posY = 500;
                jugadorPlantillaTemp->kilometro = aux->kilometro;
                jugadorPlantillaTemp->velocidad = 0;
                jugadorPlantillaTemp->vidas = aux->vidas;
                jugadorPlantillaTemp->puntos = aux->puntos;

                jugadorPlantillaTemp->playerSprite.x = 29;
                jugadorPlantillaTemp->playerSprite.y = 0;
                jugadorPlantillaTemp->playerSprite.w = 28;
                jugadorPlantillaTemp->playerSprite.h = 30;

                jugadorPlantillaTemp->position.x = aux->posX;
                jugadorPlantillaTemp->position.y = 500;
                jugadorPlantillaTemp->position.w = 28*2;
                jugadorPlantillaTemp->position.h = 30*2;

                jugadorPlantillaTemp->image = SDL_LoadBMP(texturasJugadores[aux->jugador]);
                jugadorPlantillaTemp->texture = SDL_CreateTextureFromSurface(renderer,
                                                                             jugadorPlantillaTemp->image);
                SDL_FreeSurface(jugadorPlantillaTemp->image);

                SDL_RenderCopy(renderer, jugadorPlantillaTemp->texture,
                               &jugadorPlantillaTemp->playerSprite, &jugadorPlantillaTemp->position);

                free(jugadorPlantillaTemp);


            }
            aux = aux->nextNode;
        }



        SDL_RenderCopy(renderer, thisPlayer->texture, &thisPlayer->playerSprite, &thisPlayer->position);
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
                        thisPlayer->playerSprite.x = 0;
                        izquierda = true;
                        derecha = false;
                        break;
                    case SDLK_RIGHT:
                        thisPlayer->playerSprite.x = 58;
                        izquierda = false;
                        derecha = true;
                        break;
                    case SDLK_UP:
                        thisPlayer->playerSprite.x = 29;
                        derecha = false;
                        izquierda = false;
                        thisPlayer->velocidad = velocidades[1];
                        break;
                    case SDLK_DOWN:
                        thisPlayer->playerSprite.x = 29;
                        derecha = false;
                        izquierda = false;
                        thisPlayer->velocidad = velocidades[0];
                        break;
                    case SDLK_SPACE:
                        thisPlayer->velocidad = velocidades[2];
                        break;


                    default:
                        thisPlayer->playerSprite.x = 29;
                        break;
                }
            default:
                break;

        }


        if (derecha and thisPlayer->velocidad!=0) {
            thisPlayer->position.x += 10;
        }
        if (izquierda and thisPlayer->velocidad!=0) {
            thisPlayer->position.x -= 10;
        }

        if (thisPlayer->velocidad == velocidades[1]) {
            thisPlayer->kilometro += 0.0005f;
        }
        if (thisPlayer->velocidad == velocidades[2]) {
            thisPlayer->kilometro+= 0.001f;
        }

        if (puntosCounter < 0) {
            puntosCounter = 333;
            thisPlayer->puntos++;
        }
        puntosCounter--;

        SDL_Delay(30);

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    exit(0);
}
