#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_
#include <SDL.h>
#include "setup.h"

extern SDL_Surface* Ship;


class theShip
{
public:
    SDL_Rect posShip;
    theShip();
    void ship_movement();
    void show_ship(SDL_Surface* bakgrund,SDL_Surface* ship);

private:
    int x;
    int y;

};



#endif // _GAMEOBJECT_H_
