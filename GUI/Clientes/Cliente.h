//
// Created by XPC on 2/4/2022.
//

#ifndef GUI_CLIENTE_H
#define GUI_CLIENTE_H

#include <stdbool.h>
#include <stdbool.h>
#include<winsock2.h>
#pragma comment(lib,"ws2_32.lib") //Winsock Library
#include <pthread.h>
#include <stdio.h>

char* makeRequest(bool printState, char* message);
#endif //GUI_CLIENTE_H
