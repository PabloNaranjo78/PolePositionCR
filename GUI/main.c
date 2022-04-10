#include <stdio.h>

#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <stdbool.h>
#include "cJSON/cJSON.h"
#include "Clientes/Cliente.h"
#include "Window/MainWindow/MainWindow.h"
#include "LinkedList/LinkedList.h"
#include "Window/Tools/Tools.h"

/***
 * Función principal que llama a la ventana principal
 * @param argc
 * @param args
 * @return 0
 */
int main(int argc, char *args[]) {

    mainWindow();

    return 0;
}