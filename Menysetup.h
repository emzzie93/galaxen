#ifndef _MENYSETUP_H_
#define _MENYSETUP_H_
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "setup.h"
class Menysetup
{
public:
    SDL_Texture* headermeny = nullptr;
    SDL_Texture* newgame = nullptr;
    SDL_Texture* instructions = nullptr;
    SDL_Texture* quitgame = nullptr;
   SDL_Texture* texttest = nullptr;

    SDL_Surface* Menyheader = nullptr;
    SDL_Surface* Newgame = nullptr;
    SDL_Surface* Instructions = nullptr;
    SDL_Surface* Quitgame = nullptr;

    SDL_Rect posMeny;

    Menysetup(int xpos, int ypos, int width, int height);

    void CreateMeny(GameSetup World);

};

#endif
