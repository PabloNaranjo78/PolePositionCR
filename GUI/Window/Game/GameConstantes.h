//
// Created by jpabl on 31/03/2022.
//

#ifndef GUI_GAMECONSTANTES_H
#define GUI_GAMECONSTANTES_H

SDL_Surface* luigi = NULL;
int velocidad = 400;
float kilometro = 0.0f;
int vidas = 3;

char* jugadoresNombre[]={"0","1","2","3"};

char *texturasJugadores[] = {
        "../Imagenes/luigi.bmp",
        "../Imagenes/mario.bmp",
        "../Imagenes/yoshi.bmp",
        "../Imagenes/peach.bmp",
};

int velocidades[] = {
    0,400,800
};


#endif //GUI_GAMECONSTANTES_H
