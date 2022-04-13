//
// Created by jpabl on 31/03/2022.
//

#ifndef GUI_GAMECONSTANTES_H
#define GUI_GAMECONSTANTES_H

#include "../../LinkedList/LinkedList.h"

/***
 * Strucut utilizado para guardar los datos de un jugador
 */
typedef struct {
    SDL_Surface *image;
    SDL_Texture *texture;
    SDL_Rect position;
    SDL_Rect playerSprite;
    int nombre;
    int posX;
    int posY;
    float kilometro;
    int velocidad;
    int vidas;
    int puntos;

}JugadorPlantilla;

SDL_Surface* thisplayer = NULL;

int puntosCounter = 333;
JugadoresLista* listaEnalzadaJugadores = NULL;

int jugadorTemp = 0;
int posXTemp = 0;
float kilometroTemp = 0.0f;
int vidasTemp = 0;
int puntosTemp = 0;
int puntosCounterTemp = 0;



/***
 * Nombre para los jugadores
 */
char* jugadoresNombre[]={"0","1","2","3"};

/***
 * Texturas de los jugadores
 */
char *texturasJugadores[] = {
        "../Imagenes/luigi.bmp",
        "../Imagenes/mario.bmp",
        "../Imagenes/yoshi.bmp",
        "../Imagenes/peach.bmp",
};

/***
 * Velocidades a las que puede estar el jugador
 */
int velocidades[] = {
    0,400,800
};

int posicionesXiniciales[]={
        305,355,410,465
};


#endif //GUI_GAMECONSTANTES_H
