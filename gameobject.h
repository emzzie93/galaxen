#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_
#include <SDL.h>
#include "setup.h"

extern SDL_Surface* Ship;
extern SDL_Surface* Stone;




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

class theStone
{
    public:
    theStone();
    SDL_Rect posStone;
    void stone_movement();
    void add_stone();
    void init_stone();
    bool isActive;
    SDL_Rect loop(int i);

    private:
    int x;
    int y;

};


//theStone arrayofStones[20];

#endif // _GAMEOBJECT_H_
