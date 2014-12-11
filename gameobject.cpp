#include <random>
#include "gameobject.h"
theStone arrayofStones[20];
SDL_Surface* Stone = NULL;
SDL_Surface* Ship = NULL;
SDL_Surface* Heart = NULL;
SDL_Surface* Star = NULL;

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

//    for (int i=0;i<20;i++)
//    {
//        posStone.y = arrayofStones[i].y;
//    }
}

void theStone::add_stone()
{
    if(rand() % 50 == 5)
    {
        for (int i=0; i<20;i++)
        {
            if(arrayofStones[i].isActive == false)
            {
                arrayofStones[i].x = rand() % 630;
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
        arrayofStones[i].isActive = false;
    }
}

SDL_Rect theStone::loop(int i)
{
    if(arrayofStones[i].isActive == true)
    {
    posStone.y = arrayofStones[i].y;
    posStone.x = arrayofStones[i].x;
    }
    return posStone;

}

theHeart::theHeart()
{
    posHeart.y = 0;
    posHeart.w = 30;
    posHeart.h = 30;
}

void theHeart::heart_movement()
{

    if(this->isActive == true)
    {
        posHeart.y += 2;
    }
}


void theHeart::add_heart()
{
    if(rand() % 1000 == 5)
    {
        if(this->isActive == false)
        {
        posHeart.x = rand() % 630;
        posHeart.y = 0;
        this->isActive = true;
        }
    }
}

void theHeart::init_heart()
{
    this->isActive = false;
}

theStar::theStar()
{
    posStar.y = 0;
    posStar.w = 30;
    posStar.h = 30;
}

void theStar::star_movement()
{

    if(this->isActive == true)
    {
        posStar.y += 2;
    }
}


void theStar::add_star()
{
    if(rand() % 1000 == 5)
    {
        if(this->isActive == false)
        {
        posStar.x = rand() % 630;
        posStar.y = 0;
        this->isActive = true;
        }
    }
}

void theStar::init_star()
{
    this->isActive = false;
}

