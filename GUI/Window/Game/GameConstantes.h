//
// Created by jpabl on 31/03/2022.
//

#ifndef GUI_GAMECONSTANTES_H
#define GUI_GAMECONSTANTES_H

#include "../../LinkedList/LinkedList.h"

SDL_Surface* thisplayer = NULL;
int velocidad = 400;
float kilometro = 0.0f;
int vidas = 3;
int puntos = 0;
int puntosCounter = 333;
JugadoresLista* listaEnalzadaJugadores = NULL;

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


#endif //GUI_GAMECONSTANTES_H
