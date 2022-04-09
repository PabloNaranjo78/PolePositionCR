#include <stdio.h>

#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <stdbool.h>
#include "cJSON/cJSON.h"
#include "Clientes/Cliente.h"
#include "Window/MainWindow/MainWindow.h"
#include "LinkedList/LinkedList.h"

//char prueba[] = "{nombre: 'juan', edad: '30', hobby: 'usar do while', partido: 'Chaves'}";
//makeRequest(true, prueba);

int main(int argc, char *args[]) {

   // makeRequest(true,"{nombre: 'juan', edad: '20', trabajo: 'ninguno'}");
  //  mainWindow();
    //gameInit();

    JugadoresLista *lista = crearLista(lista);

    lista = addToList(lista, 1,22,3.3f,true);
    lista = addToList(lista, 2,22,3.3f,true);
    lista = addToList(lista, 3,22,3.3f,true);

   // JugadoresLista *aux = lista;

    print_list(lista);

    //printList(lista);

  //  printf("holamudno");

    return 0;
}