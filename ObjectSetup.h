/*
 * IDA Programvaruproduktion AB (u.p.a.)
 *
 * IDENTIFIERING
 *
 * Filnamn:    ObjectSetup.h
 * Enhetsnamn:  ObjectSetup
 * Typ:        Klassdeklaration
 * Skriven av: Emma Söderström
 *             Hugo Johansson
 *             Matilda Wreth
 *
 *
 * BESKRIVNING
 *
 * Deklarerar textures och surfaces för att kunna ladda upp bilderna.
 */

#ifndef _OBJECTSETUP_H_
#define _OBJECTSETUP_H_
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "setup.h"

class ObjectSetup
{
public:
SDL_Texture* ship1 = nullptr;
SDL_Texture* stone1 = nullptr;
SDL_Texture* stone2 = nullptr;
SDL_Texture* stone3 = nullptr;
SDL_Texture* heart1 = nullptr;
SDL_Texture* star1 = nullptr;
SDL_Texture* bullet1 = nullptr;

SDL_Surface* Ship = nullptr;
SDL_Surface* Stone = nullptr;
SDL_Surface* Heart = nullptr;
SDL_Surface* Star = nullptr;
SDL_Surface* Bullet = nullptr;

ObjectSetup()=default;
~ObjectSetup()=default;

void CreateObjects(GameSetup World);
};

/*
 * SLUT PÅ FILEN ObjectSetup.h
 */

#endif
