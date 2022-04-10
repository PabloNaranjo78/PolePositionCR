//
// Created by jpabl on 8/04/2022.
//

#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

JugadoresLista* addToList(JugadoresLista *Nodo, int jugador, int posX, float kilometro, bool disparo,int vidas, int puntos) {
    JugadoresLista *nuevoNodo,*temp;
    nuevoNodo = (JugadoresLista*)malloc(sizeof(JugadoresLista));
    nuevoNodo->jugador = jugador;
    nuevoNodo->posX = posX;
    nuevoNodo->kilometro = kilometro;
    nuevoNodo->disparo = disparo;
    nuevoNodo->vidas = vidas;
    nuevoNodo->puntos = puntos;

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
        printf("Jugador: %d \n PosX %d \n KM %.2f \n disp %d \n vidas %d \n puntos %d \n ",
               current->jugador, current->posX, current->kilometro, current->disparo, current->vidas, current->puntos);
        current = current->nextNode;
    }
}

JugadoresLista *crearLista(JugadoresLista *lista) {
    lista = NULL;
    return lista;
}

JugadoresLista *
actualizarLista(JugadoresLista *head, int jugador, int posX, float kilometro, bool disparo, int vidas, int puntos) {
    JugadoresLista *current = head;
    bool encontrado = false;
    while (current != NULL) {
        if (current->jugador == jugador) {
            current->posX = posX;
            current->kilometro = kilometro;
            current->disparo = disparo;
            current->vidas = vidas;
            current->puntos = puntos;
            encontrado = true;
        }
        current = current->nextNode;
    }
    if (!encontrado) {
        head = addToList(head, jugador, posX, kilometro, disparo, vidas, puntos);
    }
    return head;
}
