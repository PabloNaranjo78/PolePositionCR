#include <stdio.h>

#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <stdbool.h>
#include "Window/Game.h"
#include "cJSON/cJSON.h"
#include "Clientes/Cliente.h"

//char prueba[] = "{nombre: 'juan', edad: '30', hobby: 'usar do while', partido: 'Chaves'}";
//makeRequest(true, prueba);

int main(int argc, char *args[]) {

    makeRequest(true,"{nombre: 'juan', edad: '20', trabajo: 'ninguno'}");
    //gameInit();

}