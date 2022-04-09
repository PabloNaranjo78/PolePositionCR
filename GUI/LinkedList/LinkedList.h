//
// Created by jpabl on 8/04/2022.
//

#ifndef GUI_LINKEDLIST_H
#define GUI_LINKEDLIST_H
#include <stdbool.h>

struct nodeList{
    int jugador;
    int posX;
    float kilometro;
    bool disparo;
    struct nodeList *nextNode;
};

void addToList(struct nodeList *Nodo, int jugador, int posX, float kilometro, bool disparo);
#endif //GUI_LINKEDLIST_H
