//
// Created by jpabl on 8/04/2022.
//

#ifndef GUI_LINKEDLIST_H
#define GUI_LINKEDLIST_H
#include <stdbool.h>

/***
 * Struct que se utiliza en la lista enlazada para guardar los datos de los jugadores
 */
typedef struct nodeList{
    int jugador;
    int posX;
    float kilometro;
    bool disparo;
    int vidas;
    int puntos;
    struct nodeList *nextNode;
} JugadoresLista;

/***
 * Funcion que crea un nodo de la lista enlazada
 * @param lista  lista enlazada
 * @return lista enlazada actualizada
 */
JugadoresLista *crearLista(JugadoresLista *lista);

/***
 * Funcion que inserta un nodo en la lista enlazada
 * @param Nodo nodo cabeza de la lista
 * @param jugador nombre del jugador
 * @param posX posición en x del jugador
 * @param kilometro kilomentro en el que se encuentra el jugador
 * @param disparo estado del disparo del jugador
 * @param vidas vidas del jugador
 * @param puntos puntos que tiene el jugador
 * @return
 */
JugadoresLista *addToList(JugadoresLista *Nodo, int jugador, int posX, float kilometro, bool disparo, int vidas, int puntos);
void print_list(JugadoresLista * head);

/***
 * Acutualiza una una lista enlazada
 * @param head cabeza de la lista enlazada
 * @param jugador numero de jugador
 * @param posX posición en X
 * @param kilometro kilometro recorrido
 * @param disparo estado de disparo
 * @param vidas vidas
 * @param puntos puntos
 * @return
 */
JugadoresLista *actualizarLista(JugadoresLista *head, int jugador, int posX, float kilometro, bool disparo, int vidas, int puntos);
#endif //GUI_LINKEDLIST_H
