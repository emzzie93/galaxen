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

    private:
    int x;
    int y;

};

class theStone
{
public:
    theStone();
    SDL_Rect posStone;
    void loop(int i);
    void stone_movement();
    void add_stone();
    void init_stone();
    bool isActive;

    int x;
    int y;
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

    private:
    int x;
    int y;

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

    private:
    int x;
    int y;

};

class theBullet
{
public:

    theBullet();
    SDL_Rect posBullet;
    void bullet_movement();
    void add_bullet(int x,int y);
    void init_bullet();
    void loop(int i);
    bool isActive;
    void collision(theStone* mystone);

    private:
    int x;
    int y;

};

#endif // _GAMEOBJECT_H_
