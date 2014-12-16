#ifndef _MENY(TEXT)_H_
#define _MENY(TEXT)_H_
#include <SDL.h>
#include "setup.h"

extern SDL_Surface* Menyheader;
extern SDL_Surface* Newgame;
extern SDL_Surface* Instructions;
extern SDL_Surface* Quitgame;


class theMeny
{
public:
    SDL_Rect posMeny;
    theMeny(int xpos, int ypos, int width, int height);


private:
    int x;
    int y;
};

#endif // _MENY(TEXT)_H_
