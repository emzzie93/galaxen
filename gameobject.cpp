#include "gameobject.h"




    SDL_Surface* Ship = NULL;

const Uint8* keystate = SDL_GetKeyboardState(NULL);

theShip::theShip()
{
    posShip.x = 180;
    posShip.y = 480;
    posShip.w = 20;
    posShip.h = 30;
}

void theShip :: ship_movement()
{
if(keystate[SDL_SCANCODE_LEFT])
    {
        posShip.x -= 5;
    }
if(keystate[SDL_SCANCODE_RIGHT])
    {
        posShip.x += 5;
    }
if ((posShip.x + 30) > 640)
    {
        posShip.x = (640 - 30);
    }
if((posShip.x - 10) < 0)
{
    posShip.x = 10;
}
if ((posShip.y + 30) > 480)
    {
        posShip.y = (480 - 30);
    }

}

void theShip::show_ship(SDL_Surface* bakgrund,SDL_Surface* ship)
{
    SDL_BlitSurface(ship,NULL,bakgrund,&posShip);
    SDL_SetColorKey(ship,SDL_TRUE,SDL_MapRGB(ship->format,255,255,255));
}


