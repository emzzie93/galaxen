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

class GameObject
{
public:
virtual ~GameObject() = default;
   SDL_Rect position;


};

class Obstacle : public GameObject
{
public:
   bool isActive;
   virtual void movement() = 0;
//   virtual void add() {};
   virtual void init() = 0;
};


class theBullet : public Obstacle
{
public:

    theBullet();
//    SDL_Rect posBullet;
    virtual void movement() override;
    void add(int x,int y, int w);
    virtual void init() override;
    void getBullet(int i);
    bool isActive;

};

class theStone : public Obstacle
{
public:
    theStone();
 //   SDL_Rect posStone;
    void getStone(int i);
   virtual  void movement() override;
    void add();
    virtual void init() override;
    void collision();
    bool isActive;

    int type;
    int move_type;

};

class theHeart : public Obstacle
{
public:
    theHeart();
//    SDL_Rect posHeart;
    virtual void movement() override;
    void add() ;
    virtual void init() override;
    bool isActive;

};

class theStar : public Obstacle
{
public:

    theStar();
//    SDL_Rect posStar;
    virtual void movement() override;
    void add() ;
    virtual void init() override;
    bool isActive;

};
class theShip : public GameObject
{
public:
//    SDL_Rect posShip;
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
