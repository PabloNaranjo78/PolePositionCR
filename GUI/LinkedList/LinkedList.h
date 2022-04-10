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
    struct nodeList *nextNode;
} JugadoresLista;


JugadoresLista *crearLista(JugadoresLista *lista);
JugadoresLista *addToList(JugadoresLista *Nodo, int jugador, int posX, float kilometro, bool disparo);
void print_list(JugadoresLista * head);
#endif //GUI_LINKEDLIST_H
