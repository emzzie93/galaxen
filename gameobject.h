/*
 * IDA Programvaruproduktion AB (u.p.a.)
 *
 * IDENTIFIERING
 *
 * Filnamn:    gameobject.h
 * Enhetsnamn:  gameobject
 * Typ:        Klassdeklarationer
 * Skriven av: Hugo Johansson
 *
 *
 * BESKRIVNING
 * deklarerar de klasser som �rver av GameObject, alla saker som r�r sig p� sk�rmen
 * har en egen klass som deklareras h�r.
 */

#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_
#include <SDL.h>
#include "setup.h"
#include "ObjectSetup.h"

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
   virtual void init() = 0;
};

class theBullet : public Obstacle
{
public:

    theBullet();
    virtual void movement() override;
    void add(int x,int y, int w);
    virtual void init() override;
    void getBullet(int i);
    bool isActive;

};

class theStone
{
public:
    theStone();

    SDL_Rect position;
    void getStone(int i);
    void movement(long level);
    void add();
    void init();
    void collision(GameSetup* soundsoptions);
    bool isActive;

    int type;
    int move_type;

};

class theHeart : public Obstacle
{
public:
    theHeart();
    virtual void movement() override;
    void add() ;
    virtual void init() override;
    bool isActive;

};

class theStar : public Obstacle
{
public:

    theStar();
    virtual void movement() override;
    void add() ;
    virtual void init() override;
    bool isActive;

};

class theShip : public GameObject
{
public:

    theShip();
    void collision(theHeart* heart,theStar* star);
    void collisionWstone();
    void add_life();
    void add_point(int i);
    void delete_life();
    void ship_movement();
    void level_up();

    long levelcount;
    long level = 1;
    long life;
    long point;
    bool lostLife = false;
};

/*
 * SLUT P� FILEN gameobject.h
 */

#endif // _GAMEOBJECT_H_
