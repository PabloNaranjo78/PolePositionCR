#include <stdio.h>

#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <stdbool.h>
#include "cJSON/cJSON.h"
#include "Clientes/Cliente.h"
#include "Window/MainWindow/MainWindow.h"
#include "LinkedList/LinkedList.h"
#include "Window/Tools/Tools.h"

//char prueba[] = "{nombre: 'juan', edad: '30', hobby: 'usar do while', partido: 'Chaves'}";
//makeRequest(true, prueba);

int main(int argc, char *args[]) {


   // makeRequest(true,"{nombre: 'juan', edad: '20', trabajo: 'ninguno'}");
    mainWindow();


//    JugadoresLista *lista = crearLista(lista);
//
//    lista = addToList(lista, 1,22,3.3f,true);
//    lista = addToList(lista, 2,22,3.3f,true);
//    lista = addToList(lista, 3,22,3.3f,true);
//
//  //  JugadoresLista *aux = lista;

  //  print_list(lista);

    //printList(lista);

  //  printf("holamudno");

//    JugadorInfo *jugador = crearInfoJugador(1,22,3.3f);
//
//    JugadoresLista *lista = NULL;
//    lista = crearLista(lista);
//    lista =addToList(lista, 1,22,3.3f,true);
//    lista = addToList(lista, 8,22,3.3f,true);
//    lista = addToList(lista, 3,22,3.3f,true);
//
//    print_list(lista);

 //   printf(jsonString);
//
//    char *message =
//            "{                              \
//    \"name\":\"mculover666\",   \
//    \"age\": 22,                \
//    \"weight\": 55.5,           \
//    \"address\":                \
//        {                       \
//            \"country\": \"China\",\
//            \"zip-code\": 111111\
//        },                      \
//    \"skill\": [\"c\", \"Java\", \"Python\"],\
//    \"student\": false          \
//}";

//    cJSON* cjson_test = NULL;
//    cJSON* cjson_name = NULL;
//    cJSON* cjson_age = NULL;
//    cJSON* cjson_weight = NULL;
//    cJSON* cjson_address = NULL;
//    cJSON* cjson_address_country = NULL;
//    cJSON* cjson_address_zipcode = NULL;
//    cJSON* cjson_skill = NULL;
//    cJSON* cjson_student = NULL;
//    int    skill_array_size = 0, i = 0;
//    cJSON* cjson_skill_item = NULL;
//
//
//    cjson_test = cJSON_Parse(message);
//    if(cjson_test == NULL)
//    {
//        printf("parse fail.\n");
//        return -1;
//    }
//
//    printf("%s\n", cJSON_Print(cjson_test));

    return 0;
}