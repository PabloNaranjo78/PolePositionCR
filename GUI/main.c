#include <stdio.h>

#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <stdbool.h>
#include "cJSON/cJSON.h"
#include "Clientes/Cliente.h"
#include "Window/MainWindow/MainWindow.h"

//char prueba[] = "{nombre: 'juan', edad: '30', hobby: 'usar do while', partido: 'Chaves'}";
//makeRequest(true, prueba);

int main(int argc, char *args[]) {

<<<<<<< Updated upstream
   // makeRequest(true,"{nombre: 'juan', edad: '20', trabajo: 'ninguno'}");
    mainWindow();
=======

    //gameInit();
    cJSON *cjson_test = NULL;
    cJSON *cjson_jugador1 = NULL;
    cJSON *cjson_jugador2 = NULL;
    cJSON *cjson_jugador3 = NULL;
    cJSON *cjson_jugador4 = NULL;
    char *str = NULL;

    cjson_test = cJSON_CreateObject();

//    cJSON_AddStringToObject(cjson_test, "name", "jose");
//
//
//    cJSON_AddNumberToObject(cjson_test, "age", 22);
//
//
//    cJSON_AddNumberToObject(cjson_test, "weight", 55.5);


    cjson_jugador1 = cJSON_CreateObject();
    cJSON_AddNumberToObject(cjson_jugador1, "cordenadaX", 10);
    cJSON_AddNumberToObject(cjson_jugador1, "cordenadaY", 10);
    cJSON_AddItemToObject(cjson_test, "Jugador1", cjson_jugador1);

    cjson_jugador2 = cJSON_CreateObject();
    cJSON_AddNumberToObject(cjson_jugador2, "cordenadaX", 20);
    cJSON_AddNumberToObject(cjson_jugador2, "cordenadaY", 20);
    cJSON_AddItemToObject(cjson_test, "Jugador2", cjson_jugador2);

    cjson_jugador3 = cJSON_CreateObject();
    cJSON_AddNumberToObject(cjson_jugador3, "cordenadaX", 30);
    cJSON_AddNumberToObject(cjson_jugador3, "cordenadaY", 30);
    cJSON_AddItemToObject(cjson_test, "Jugador3", cjson_jugador3);

    cjson_jugador4 = cJSON_CreateObject();
    cJSON_AddNumberToObject(cjson_jugador4, "cordenadaX", 40);
    cJSON_AddNumberToObject(cjson_jugador4, "cordenadaY", 40);
    cJSON_AddItemToObject(cjson_test, "Jugador4", cjson_jugador4);

    str = cJSON_Print(cjson_test);
    printf("%s\n", str);

    makeRequest(true,str);
    //"{nombre: 'juan', edad: '20', trabajo: 'ninguno'}"

    return 0;
>>>>>>> Stashed changes

}