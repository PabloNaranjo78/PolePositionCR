//
// Created by jpabl on 8/04/2022.
//

#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

void addToList(struct nodeList *Nodo, int jugador, int posX, float kilometro, bool disparo){
    if (Nodo == NULL){
        Nodo = malloc(sizeof (struct nodeList));
        Nodo->jugador = jugador;
        Nodo->posX = posX;
        Nodo->kilometro = kilometro;
        Nodo->disparo = disparo;
    }else{
        struct nodeList *temp = malloc(sizeof (struct nodeList));
        temp->jugador = jugador;
        temp->posX = posX;
        temp->kilometro = kilometro;
        temp->disparo = disparo;
        struct nodeList *aux = Nodo;
        temp->nextNode = aux;
        Nodo = temp;

    }
}
