#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_
#include <SDL.h>
#include "setup.h"
#include "ObjectSetup.h"

//extern SDL_Surface* Ship;
//extern SDL_Surface* Stone;
//extern SDL_Surface* Heart;
//extern SDL_Surface* Star;
//extern SDL_Surface* Bullet;



class theBullet
{
public:

    theBullet();
    SDL_Rect posBullet;
    void bullet_movement();
    void add_bullet(int x,int y, int w);
    void init_bullet();
    void getBullet(int i);
    bool isActive;

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
    void collision();
    bool isActive;

    int type;
    int move_type;

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
class theShip
{
public:
    SDL_Rect posShip;
    theShip();
    void collision(theHeart* heart,theStar* star);
    void collisionWstone();
    void add_life();
    void add_point(int i);
    void delete_life();
    void ship_movement();

    int life;
    int point;
};


#endif // _GAMEOBJECT_H_
