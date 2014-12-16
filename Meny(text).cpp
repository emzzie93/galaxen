#include "Meny(text).h"

SDL_Surface* Menyheader = NULL;
SDL_Surface* Newgame = NULL;
SDL_Surface* Instructions = NULL;
SDL_Surface* Quitgame = NULL;

theMeny::theMeny(int xpos, int ypos, int width, int height)
{
    posMeny.x = xpos;
    posMeny.y = ypos;
    posMeny.w = width;
    posMeny.h = height;
}



