#include "gameobject.h"
#include <random>

theStone arrayofStones[20];

SDL_Surface* Stone = NULL;

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

theStone::theStone()
{
    posStone.x;
    posStone.y;
    posStone.w = 30;
    posStone.h = 30;
}

void theStone::stone_movement()
{
    for(int i=0; i<20;i++)
    {
        if(arrayofStones[i].isActive == true)
        {
            if(arrayofStones[i].y > 480)
            {
                arrayofStones[i].isActive = false;
            }else
            {
                arrayofStones[i].y += 2;
            }
        }
    }
    //check collision

    for (int i=0;i<20;i++)
    {
        posStone.y = arrayofStones[i].y;
    }
}

void theStone::add_stone()
{
    if((rand % 100) == 55)
    {
        for (int i=0; i<20;i++)
        {
            if(arrayofStones[i].isActive == false)
            {
                arrayofStones[i].x = rand() % 640;
                arrayofStones[i].y = 0;
                arrayofStones[i].isActive = true;
                break;
            }
        }
    }
}

void theStone::init_stone()
{
    for(int i=0;i<20;i++)
    {
        arrayofStones[i].isActive == false;
    }
}


