/*
 * IDA Programvaruproduktion AB (u.p.a.)
 *
 * IDENTIFIERING
 *
 * Filnamn:    gameobject.cpp
 * Enhetsnamn:  gameobject
 * Typ:
 * Revision:
 * Skriven av:
 *
 *
 * BESKRIVNING
 *
 * Denna modul ...
 *
 */

/*
 * REFERERADE BIBLIOTEK OCH MODULER
 */

#include <random>
#include "setup.h"
#include "gameobject.h"
#include "ObjectSetup.h"

theStone arrayofStones[20];
theBullet arrayofBullet[20];


const Uint8* keystate = SDL_GetKeyboardState(NULL);

//---------------------Bullet-klassen----------------------//

theBullet::theBullet()
{
    position.w = 13;
    position.h = 13;
}

void theBullet::movement()
{
    for(int i=0; i<20; i++)
    {
        if(arrayofBullet[i].isActive == true)
        {
            if(arrayofBullet[i].position.y < 10)
            {
                arrayofBullet[i].isActive = false;
            }
            else
            {
                arrayofBullet[i].position.y -= 5;
            }
        }
    }
}

void theBullet::add (int x,int y, int w)
{
    for (int i=0; i<20 ; i++)
    {
        if(arrayofBullet[i].isActive == false)
        {

            arrayofBullet[i].position.x = x+(w/2-6);
            arrayofBullet[i].position.y = y;
            arrayofBullet[i].isActive = true;
            break;
        }
    }
}

void theBullet::init()
{
    for(int i=0; i<20; i++)
    {
        arrayofBullet[i].isActive = false;
    }
}

void theBullet::getBullet(int i)
{
    *this = arrayofBullet[i];
}

//---------------------Stone-klassen----------------------//

theStone::theStone()
{
    position.w = 50;
    position.h = 50;
}

void theStone::movement(long level)
{
    if(level == 1)
   {
        for(int i=0; i<20; i++)
        {

            if(arrayofStones[i].isActive == true)
            {
                if(arrayofStones[i].position.y > 480)
                {
                    arrayofStones[i].isActive = false;
                    arrayofStones[i].position.x = 0;
                    arrayofStones[i].position.y = 0;
                }
                else if (arrayofStones[i].move_type == 1)
                {
                    arrayofStones[i].position.y += 2 ;
                }
                else if (arrayofStones[i].move_type == 2)
                {
                    if(arrayofStones[i].position.x < 0)
                    {
                        arrayofStones[i].position.y += 1  ;
                        arrayofStones[i].position.x += 2  ;
                        arrayofStones[i].move_type = 3;
                    }
                    else
                    {
                        arrayofStones[i].position.y += 1  ;
                        arrayofStones[i].position.x -= 2  ;
                    }
                }
                else if(arrayofStones[i].move_type == 3)
                {
                    if(arrayofStones[i].position.x + arrayofStones[i].position.w > 640)
                    {
                        arrayofStones[i].position.y += 1  ;
                        arrayofStones[i].position.x -= 2  ;
                        arrayofStones[i].move_type = 2;
                    }
                    else
                    {
                        arrayofStones[i].position.y += 1  ;
                        arrayofStones[i].position.x += 2  ;
                    }
                }
            }
        }
    }

    if(level == 2)
    {
        for(int i=0; i<20; i++)
        {

            if(arrayofStones[i].isActive == true)
            {
                if(arrayofStones[i].position.y > 480)
                {
                    arrayofStones[i].isActive = false;
                    arrayofStones[i].position.x = 0;
                    arrayofStones[i].position.y = 0;
                }
                else if (arrayofStones[i].move_type == 1)
                {
                    arrayofStones[i].position.y += 3;
                }
                else if (arrayofStones[i].move_type == 2)
                {
                    if(arrayofStones[i].position.x < 0)
                    {
                        arrayofStones[i].position.y += 2;
                        arrayofStones[i].position.x += 3;
                        arrayofStones[i].move_type = 3;
                    }
                    else
                    {
                        arrayofStones[i].position.y += 2;
                        arrayofStones[i].position.x -= 3;
                    }
                }
                else if(arrayofStones[i].move_type == 3)
                {
                    if(arrayofStones[i].position.x + arrayofStones[i].position.w > 640)
                    {
                        arrayofStones[i].position.y += 2;
                        arrayofStones[i].position.x -= 3;
                        arrayofStones[i].move_type = 2;
                    }
                    else
                    {
                        arrayofStones[i].position.y += 2;
                        arrayofStones[i].position.x += 3;
                    }
                }
            }
        }
    }

    if(level >= 3)
    {
        for(int i=0; i<20; i++)
        {

            if(arrayofStones[i].isActive == true)
            {
                if(arrayofStones[i].position.y > 480)
                {
                    arrayofStones[i].isActive = false;
                    arrayofStones[i].position.x = 0;
                    arrayofStones[i].position.y = 0;
                }
                else if (arrayofStones[i].move_type == 1)
                {
                    arrayofStones[i].position.y += 4;
                }
                else if (arrayofStones[i].move_type == 2)
                {
                    if(arrayofStones[i].position.x < 0)
                    {
                        arrayofStones[i].position.y += 3;
                        arrayofStones[i].position.x += 4;
                        arrayofStones[i].move_type = 3;
                    }
                    else
                    {
                        arrayofStones[i].position.y += 3;
                        arrayofStones[i].position.x -= 4;
                    }
                }
                else if(arrayofStones[i].move_type == 3)
                {
                    if(arrayofStones[i].position.x + arrayofStones[i].position.w > 640)
                    {
                        arrayofStones[i].position.y += 3;
                        arrayofStones[i].position.x -= 4;
                        arrayofStones[i].move_type = 2;
                    }
                    else
                    {
                        arrayofStones[i].position.y += 3;
                        arrayofStones[i].position.x += 4;
                    }
                }
            }
        }
    }
    if(level >= 4)
    {
        for(int i=0; i<20; i++)
        {

            if(arrayofStones[i].isActive == true)
            {
                if(arrayofStones[i].position.y > 480)
                {
                    arrayofStones[i].isActive = false;
                    arrayofStones[i].position.x = 0;
                    arrayofStones[i].position.y = 0;
                }
                else if (arrayofStones[i].move_type == 1)
                {
                    arrayofStones[i].position.y += 5;
                }
                else if (arrayofStones[i].move_type == 2)
                {
                    if(arrayofStones[i].position.x < 0)
                    {
                        arrayofStones[i].position.y += 3;
                        arrayofStones[i].position.x += 5;
                        arrayofStones[i].move_type = 3;
                    }
                    else
                    {
                        arrayofStones[i].position.y += 3;
                        arrayofStones[i].position.x -= 5;
                    }
                }
                else if(arrayofStones[i].move_type == 3)
                {
                    if(arrayofStones[i].position.x + arrayofStones[i].position.w > 640)
                    {
                        arrayofStones[i].position.y += 3;
                        arrayofStones[i].position.x -= 5;
                        arrayofStones[i].move_type = 2;
                    }
                    else
                    {
                        arrayofStones[i].position.y += 3;
                        arrayofStones[i].position.x += 5;
                    }
                }
            }
        }
    }
}


void theStone::add()
{
    if(rand() % 35 == 5)
    {
        int t = rand() % 100;
        int m = rand() % 3 + 1;
        if(t<=60)
        {

            for (int i=0; i<20; i++)
            {
                if(arrayofStones[i].isActive == false)
                {
                    arrayofStones[i].position.x = rand() % 620;
                    arrayofStones[i].position.y = 0;
                    arrayofStones[i].isActive = true;
                    arrayofStones[i].type = 1;
                    arrayofStones[i].move_type = m;
                    break;
                }
            }
        }
        else if(t<=90)
        {
            for (int i=0; i<20; i++)
            {
                if(arrayofStones[i].isActive == false)
                {
                    arrayofStones[i].position.x = rand() % 620;
                    arrayofStones[i].position.y = 0;
                    arrayofStones[i].isActive = true;
                    arrayofStones[i].type = 2;
                    arrayofStones[i].move_type = m;
                    break;
                }
            }
        }
        else
        {
            for (int i=0; i<20; i++)
            {
                if(arrayofStones[i].isActive == false)
                {
                    arrayofStones[i].position.x = rand() % 620;
                    arrayofStones[i].position.y = 0;
                    arrayofStones[i].isActive = true;
                    arrayofStones[i].type = 3;
                    arrayofStones[i].move_type = m;
                    break;
                }
            }
        }
    }
}


void theStone::init()
{
    for(int i=0; i<20; i++)
    {
        arrayofStones[i].isActive = false;
    }
}

void theStone::getStone(int i)
{
    *this = arrayofStones[i];
}

void theStone::collision(GameSetup* soundsoptions)
{

    for(int i=0; i<20; i++)
    {
        if(arrayofStones[i].isActive == true)
        {
            for(int j=0; j<20; j++)
            {
                if(arrayofBullet[j].isActive == true)
                {
                    if(arrayofStones[i].position.x<=arrayofBullet[j].position.x &&
                            arrayofBullet[j].position.x<=(arrayofStones[i].position.x + arrayofStones[i].position.w) &&
                            arrayofStones[i].position.y<=arrayofBullet[j].position.y &&
                            arrayofBullet[j].position.y<= (arrayofStones[i].position.y+arrayofStones[i].position.h))
                    {
                        if(arrayofStones[i].type == 1)
                        {
                            arrayofStones[i].isActive = false;
                            arrayofStones[i].position.x = 0;
                            arrayofStones[i].position.y = 0;
                        }
                        else if (arrayofStones[i].type == 2)
                        {
                            arrayofStones[i].type = 1;
                        }
                        else if (arrayofStones[i].type == 3)
                        {

                            arrayofStones[i].type = 2;
                        }

                        soundsoptions->playeffect2 = true;
                        soundsoptions->PlaySound();
                        arrayofBullet[j].isActive = false;
                        arrayofBullet[j].position.x = 0;
                        arrayofBullet[j].position.y = 0;
                    }
                }
            }
        }
    }
}

//---------------------Heart-klassen----------------------//

theHeart::theHeart()
{
    position.y = 0;
    position.w = 15;
    position.h = 15;
}

void theHeart::movement()
{
    if(this->isActive == true)
    {
        position.y += 2;
    }
    if(this->position.y > 450)
    {
        this->isActive = false;
        this->position.x = 0;
        this->position.y = 0;
    }
}

void theHeart::add()
{
    if(rand() % 10000 == 5)
    {
        if(this->isActive == false)
        {
            position.x = rand() % 450;
            position.y = 0;
            this->isActive = true;
        }
    }
}

void theHeart::init()
{
    this->isActive = false;
}

//---------------------Star-klassen----------------------//

theStar::theStar()
{
    position.y = 0;
    position.w = 20;
    position.h = 20;
}

void theStar::movement()
{

    if(this->isActive == true)
    {
        position.y += 2;
    }
    if(this->position.y > 450)
    {
        this->isActive = false;
        this->position.x = 0;
        this->position.y = 0;
    }
}

void theStar::add()
{
    if(rand() % 150 == 5)
    {
        if(this->isActive == false)
        {
            position.x = rand() % 630;
            position.y = 0;
            this->isActive = true;
        }
    }
}

void theStar::init()
{
    this->isActive = false;
}


//---------------------Ship-klassen----------------------//

theShip::theShip()
{
    position.x = 180;
    position.y = 400;
    position.w = 50;
    position.h = 60;
    life = 3;
    point = 0;
}

void theShip :: add_life()
{
    this->life++;
}

void theShip :: delete_life()
{
    this->life--;
    lostLife = true;
}

void theShip :: add_point(int i)
{
    this->point = this->point + i;
}

void theShip :: ship_movement()
{
    if(keystate[SDL_SCANCODE_LEFT])
    {
        position.x -= 5;
    }
    if(keystate[SDL_SCANCODE_RIGHT])
    {
        position.x += 5;
    }
    if (keystate[SDL_SCANCODE_UP])
    {
        position.y -= 5;
    }
    if (keystate[SDL_SCANCODE_DOWN])
    {
        position.y += 5;
    }

    if ((position.x + position.w) > 640)
    {
        position.x = (640 - position.w);
    }
    if(position.x < 0)
    {
        position.x = 3;
    }
    if ((position.y + position.h) > 480)
    {
        position.y = (480 - position.h);
    }
    if (position.y <0)
    {
        position.y=0;
    }
}

void theShip :: collision(theHeart* heart, theStar* star)
{
    if((this->position.x<=(heart->position.x+heart->position.w) &&
            (this->position.x +this->position.w) >= heart->position.x) &&
            (this->position.y<=(heart->position.y+heart->position.h) &&
             (this->position.y +this->position.h) >= heart->position.y))
    {
        heart->isActive = false;
        heart->position.x = 0;
        heart->position.y = 0;
        this->add_life();
    }
    if((this->position.x<=(star->position.x+star->position.w) &&
            (this->position.x + this->position.w) >= star->position.x) &&
            this->position.y<=(star->position.y+star->position.h) &&
            (this->position.y + this->position.h) >= star->position.y)
    {
        star->isActive = false;
        star->position.x = 0;
        star->position.y = 0;
        this->add_point(100);
    }
}

void theShip :: collisionWstone()
{
    for(int i=0; i<20; i++)
    {
        if((this->position.x<=(arrayofStones[i].position.x+arrayofStones[i].position.w) &&
                (this->position.x + this->position.w) >= arrayofStones[i].position.x) &&
                (this->position.y<=(arrayofStones[i].position.y+arrayofStones[i].position.h) &&
                 (this->position.y + this->position.h) >= arrayofStones[i].position.y))
        {
            arrayofStones[i].isActive = false;
            arrayofStones[i].position.x = 0;
            arrayofStones[i].position.y = 0;

            this->delete_life();
        }
    }
}

void theShip::level_up()
{
    level++;
}


/*
 * SLUT PÅ FILEN gameobject.cpp
 */

