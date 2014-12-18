/*
 * IDA Programvaruproduktion AB (u.p.a.)
 *
 * IDENTIFIERING
 *
 * Filnamn:    Meny(text).h
 * Enhetsnamn:  Meny(text)
 * Typ:        Moduldeklaration
 * Revision:
 * Skriven av:
 *
 *
 * BESKRIVNING
 *
 * Denna modul ...
 */

/*
 * REFERERADE BIBLIOTEK OCH MODULER
 */

#ifndef _MENY(TEXT)_H_
#define _MENY(TEXT)_H_
#include <SDL.h>
#include "setup.h"

extern SDL_Surface* Menyheader;
extern SDL_Surface* Newgame;
extern SDL_Surface* Instructions;
extern SDL_Surface* Quitgame;
extern SDL_Surface* About;


class theMeny
{
public:
    SDL_Rect posMeny;
    theMeny(int xpos, int ypos, int width, int height);


private:
    int x;
    int y;
};

/*
 * SLUT PÅ FILEN Meny(text).h
 */

#endif // _MENY(TEXT)_H_
