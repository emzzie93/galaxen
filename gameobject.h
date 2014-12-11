#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_
#include <SDL.h>
#include "setup.h"

extern SDL_Surface* Ship;
extern SDL_Surface* Stone;
extern SDL_Surface* Heart;
extern SDL_Surface* Star;
extern SDL_Surface* Bullet;

class theShip
{
public:
    SDL_Rect posShip;
    theShip();

    void ship_movement();
};

class theStone
{
public:
    theStone();
    SDL_Rect posStone;
    void getStone(int i);
    void stone_movement();
    void add_stone();
    void init_stone();
    void collision(int x, int y);
    bool isActive;

};

class theHeart
{
public:
    theHeart();
    SDL_Rect posHeart;
    void heart_movement();
    void add_heart();
    void init_heart();
    bool isActive;

};

class theStar
{
public:

    theStar();
    SDL_Rect posStar;
    void star_movement();
    void add_star();
    void init_star();
    bool isActive;

};

class theBullet
{
public:

    theBullet();
    SDL_Rect posBullet;
    void bullet_movement();
    void add_bullet(int x,int y);
    void init_bullet();
    void getBullet(int i);
    bool isActive;
    void collision(theStone mystone);

};

#endif // _GAMEOBJECT_H_
