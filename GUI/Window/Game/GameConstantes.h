//
// Created by jpabl on 31/03/2022.
//

#ifndef GUI_GAMECONSTANTES_H
#define GUI_GAMECONSTANTES_H

SDL_Surface* gScreenSurface = NULL;
SDL_Surface* luigi = NULL;
int velocidad = 600;

char *texturasJugadores[] = {
        "../Imagenes/mario.bmp",
        "../Imagenes/luigi.bmp",
        "../Imagenes/peach.bmp",
        "../Imagenes/yoshi.bmp"
};

int velocidades[] = {
    0,600,1200
};


#endif //GUI_GAMECONSTANTES_H
