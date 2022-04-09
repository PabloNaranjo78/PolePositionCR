//
// Created by jpabl on 8/04/2022.
//

#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

JugadoresLista* addToList(JugadoresLista *Nodo, int jugador, int posX, float kilometro, bool disparo){
    JugadoresLista *nuevoNodo,*temp;
    nuevoNodo = (JugadoresLista*)malloc(sizeof(JugadoresLista));
    nuevoNodo->jugador = jugador;
    nuevoNodo->posX = posX;
    nuevoNodo->kilometro = kilometro;
    nuevoNodo->disparo = disparo;
    nuevoNodo->nextNode = NULL;

    if(Nodo == NULL){
        Nodo = nuevoNodo;
    }
    else{
        temp = Nodo;
        while(temp->nextNode != NULL){
            temp = temp->nextNode;
        }
        temp->nextNode = nuevoNodo;
    }

    return Nodo;
}

void print_list(JugadoresLista * head) {
    JugadoresLista * current = head;

    while (current != NULL) {
        printf("%d\n", current->jugador);
        current = current->nextNode;
    }
}

JugadoresLista *crearLista(JugadoresLista *lista) {
    lista = NULL;
    return lista;
}
