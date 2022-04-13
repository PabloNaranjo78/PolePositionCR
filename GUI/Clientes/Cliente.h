//
// Created by XPC on 2/4/2022.
//

#ifndef GUI_CLIENTE_H
#define GUI_CLIENTE_H

#include <stdbool.h>
#include <stdbool.h>
#include<winsock2.h>
//#pragma comment(lib,"ws2_32.lib") //Winsock Library
#include "winsock2.h"
#include <pthread.h>
#include <stdio.h>
/***
 * @brief Estructura de un cliente
 * @param printState determina si se desea que se impriman los estados de la conexión
 * @param message mensaje que se desea enviar
 * @return retorna la respuesta del cliente
 */
char* makeRequest(bool printState, char* message);
#endif //GUI_CLIENTE_H
