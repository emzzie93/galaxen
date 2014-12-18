/*
 * IDA Programvaruproduktion AB (u.p.a.)
 *
 * IDENTIFIERING
 *
 * Filnamn:    Meny(text).cpp
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

#include "Meny(text).h"

SDL_Surface* Menyheader = nullptr;
SDL_Surface* Newgame = nullptr;
SDL_Surface* About = nullptr;
SDL_Surface* Quitgame = nullptr;
SDL_Surface* Instructions = nullptr;

theMeny::theMeny(int xpos, int ypos, int width, int height)
{
    posMeny.x = xpos;
    posMeny.y = ypos;
    posMeny.w = width;
    posMeny.h = height;
}



/*
 * SLUT PÅ FILEN Meny(text).cpp
 */
