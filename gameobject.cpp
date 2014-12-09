#include "gameobject.h"
#include <SDL.h>

//Window rendering to
SDL_Window* gWindow = NULL;

SDL_Surface* gScreenSurface = NULL;

SDL_Surface* Background = NULL;

SDL_Surface* Ship = NULL;

SDL_Event Event;

////Surface contained by window

SDL_Rect posShip;

const Uint8* keystate = SDL_GetKeyboardState(NULL);

theShip::theShip()
{
    posShip.x = 170;
    posShip.y = SCREEN_HEIGHT;
    posShip.w = 20;
    posShip.h = 30;
}

void theShip :: ship_movement()
{
if(keystate[SDL_SCANCODE_LEFT])
    {
        posShip.x -= 2;
    }
if(keystate[SDL_SCANCODE_RIGHT])
    {
        posShip.x += 2;
    }
if(keystate[SDL_SCANCODE_UP])
    {
        posShip.y -= 2;
    }
if(keystate[SDL_SCANCODE_DOWN])
    {
        posShip.y += 2;
    }
if ((posShip.x + SPRITE_WIDTH) > SCREEN_WIDTH)
    {
        posShip.x = (SCREEN_WIDTH - SPRITE_WIDTH);
    }
if ((posShip.y + SPRITE_HEIGHT) > SCREEN_HEIGHT)
    {
        posShip.y = (SCREEN_HEIGHT - SPRITE_HEIGHT);
    }

}

void theShip::show_ship()
{
    SDL_BlitSurface(Ship,NULL,gScreenSurface,&posShip);
    SDL_SetColorKey(Ship,SDL_TRUE,SDL_MapRGB(Ship->format,255,255,255));
}


