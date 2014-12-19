/*
 * IDA Programvaruproduktion AB (u.p.a.)
 *
 * IDENTIFIERING
 *
 * Filnamn:    asteroids.h
 * Enhetsnamn: asteroids
 * Typ:        Klassdeklaration
 * Skriven av: Emma S�derstr�m
 *
 *
 * BESKRIVNING
 *
 * Denna klass utg�r sj�lva spelet.
 *
 */

#ifndef _ASTEROIDS_H_
#define _ASTEROIDS_H_

#include <iostream>
#include <string>

#include <SDL.h>
#include <SDL_image.h>

#include "gameobject.h"

using namespace std;


class Asteroids
{
public:
    SDL_Texture* texttest = nullptr;
    void Play(int argc, char *argv[]);
    void render1(SDL_Renderer* GameRender,SDL_Texture* texture,SDL_Rect* type);
};


/*
 * SLUT P� FILEN asteroids.h
 */
#endif
