//
// Created by jpabl on 9/04/2022.
//

#ifndef GUI_TOOLS_H
#define GUI_TOOLS_H
#include <stdio.h>
#include <malloc.h>
#include "../../cJSON/cJSON.h"

/***
 * Struct que guarda la informacion del juador
 */
typedef struct {
    int Jugador;
    int posX;
    float kilometro;
} JugadorInfo;

/***
 * Crea un struct con los datos del jugador
 * @param jugador numero del jugador
 * @param posX posición en x
 * @param kilometro kilomentro en el que se encuentra el jugador
 * @return
 */
JugadorInfo* crearInfoJugador(int jugador, int posX, float kilometro);

/***
 * Convierte el jugador en un json
 * @param jugadorInfo Struct con datos del jugador
 * @return retorna un json con los datos del jugador
 */
cJSON* toJson(JugadorInfo *jugadorInfo);

/***
 * Retorna una cadena de caracteres con el json
 * @param jugadorInfo json con los datos del jugador
 * @return cadena de char con el json en forma de texto
 */
char* toString(cJSON *jugadorInfo);


#endif //GUI_TOOLS_H
