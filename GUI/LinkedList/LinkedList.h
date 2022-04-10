//
// Created by jpabl on 8/04/2022.
//

#ifndef GUI_LINKEDLIST_H
#define GUI_LINKEDLIST_H
#include <stdbool.h>

typedef struct nodeList{
    int jugador;
    int posX;
    float kilometro;
    bool disparo;
    int vidas;
    int puntos;
    struct nodeList *nextNode;
} JugadoresLista;


JugadoresLista *crearLista(JugadoresLista *lista);
JugadoresLista *addToList(JugadoresLista *Nodo, int jugador, int posX, float kilometro, bool disparo, int vidas, int puntos);
void print_list(JugadoresLista * head);
JugadoresLista *actualizarLista(JugadoresLista *head, int jugador, int posX, float kilometro, bool disparo, int vidas, int puntos);
#endif //GUI_LINKEDLIST_H
