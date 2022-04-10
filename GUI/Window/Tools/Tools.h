//
// Created by jpabl on 9/04/2022.
//

#ifndef GUI_TOOLS_H
#define GUI_TOOLS_H
#include <stdio.h>
#include <malloc.h>
#include "../../cJSON/cJSON.h"


typedef struct {
    int Jugador;
    int posX;
    float kilometro;
} JugadorInfo;

JugadorInfo* crearInfoJugador(int jugador, int posX, float kilometro);
cJSON* toJson(JugadorInfo *jugadorInfo);
char* toString(cJSON *jugadorInfo);


#endif //GUI_TOOLS_H
