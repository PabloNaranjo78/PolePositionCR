//
// Created by jpabl on 9/04/2022.
//

#include "Tools.h"
cJSON* toJson(JugadorInfo *jugadorInfo){
    cJSON *json = cJSON_CreateObject();
    cJSON *jsonInfo = cJSON_CreateObject();

    cJSON_AddNumberToObject(jsonInfo, "Jugador", jugadorInfo->Jugador);
    cJSON_AddNumberToObject(jsonInfo, "posX", jugadorInfo->posX);
    cJSON_AddNumberToObject(jsonInfo, "kilometro", jugadorInfo->kilometro);

    cJSON_AddItemToObject(json, "Jugador", jsonInfo);

    return json;
}

JugadorInfo* crearInfoJugador(int jugador, int posX, float kilometro){
    JugadorInfo *jugadorInfo = malloc(sizeof(JugadorInfo));
    jugadorInfo->Jugador = jugador;
    jugadorInfo->posX = posX;
    jugadorInfo->kilometro = kilometro;
    return jugadorInfo;
}

char* toString(cJSON *jugadorInfo){
    char *jsonString = cJSON_Print(jugadorInfo);
    return jsonString;
}

