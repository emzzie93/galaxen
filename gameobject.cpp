#include <random>
#include "gameobject.h"
theStone arrayofStones[20];
theBullet arrayofBullet[20];
SDL_Surface* Stone = NULL;
SDL_Surface* Ship = NULL;
SDL_Surface* Heart = NULL;
SDL_Surface* Star = NULL;
SDL_Surface* Bullet = NULL;

const Uint8* keystate = SDL_GetKeyboardState(NULL);

//---------------------Ship-klassen----------------------//

theShip::theShip()
{
    posShip.x = 180;
    posShip.y = 400;
    posShip.w = 80;
    posShip.h = 90;
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

//---------------------Stone-klassen----------------------//

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
            }
            else
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
    if(rand() % 45 == 5)
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

void theStone::loop(int i)
{
    if(arrayofStones[i].isActive == true)
    {
    posStone.y = arrayofStones[i].y;
    posStone.x = arrayofStones[i].x;
    }

}

//---------------------Heart-klassen----------------------//

theHeart::theHeart()
{
    posHeart.y = 0;
    posHeart.w = 15;
    posHeart.h = 15;
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
    if(rand() % 10 == 5)
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

//---------------------Star-klassen----------------------//

theStar::theStar()
{
    posStar.y = 0;
    posStar.w = 20;
    posStar.h = 20;
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
    if(rand() % 10 == 5)
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

//---------------------Bullet-klassen----------------------//

theBullet::theBullet()
{
    posBullet.w = 13;
    posBullet.h = 13;
}

void theBullet::bullet_movement()
{
    for(int i=0; i<20;i++)
    {
        if(arrayofBullet[i].isActive == true)
        {
            if(arrayofBullet[i].y < 0)
            {
                arrayofBullet[i].isActive = false;
            }else
            {
                arrayofBullet[i].y -= 2;
            }
        }
    }
    //check collision

//    for (int i=0;i<20;i++)
//    {
//        posStone.y = arrayofStones[i].y;
//    }
}


void theBullet::add_bullet(int x,int y)

{
for (int i=0; i<20 ;i++)
        {
            if(arrayofBullet[i].isActive == false)
            {

                arrayofBullet[i].x = x+9;
                arrayofBullet[i].y = y;
                arrayofBullet[i].isActive = true;
                break;
            }
        }
}

void theBullet::init_bullet()
{
    for(int i=0;i<20;i++)
    {
        arrayofBullet[i].isActive = false;
    }
}

void theBullet::loop(int i)
{
    if(arrayofBullet[i].isActive == true)
    {
    posBullet.y = arrayofBullet[i].y;
    posBullet.x = arrayofBullet[i].x;
    }


}

void theBullet::collision(theStone mystone)
{
    for(int i =0;i<20;i++)
    {
        if(mystone.posStone.x<arrayofBullet[i].x && arrayofBullet[i].x<(mystone.posStone.x+25) &&
           mystone.posStone.y<arrayofBullet[i].y && arrayofBullet[i].y<(mystone.posStone.y+25))
        {
            arrayofBullet[i].isActive = false;
                mystone.posStone.y = 0;
            mystone.isActive = false;

            //std::cout << mystone.posStone.x << std::endl;
        }
    }
//        for(int j=0;j<20;i++)
//        {
////            if((arrayofStones[j].x<arrayofBullet[i].x &&
////                arrayofBullet[i].x<(arrayofStones[j].x+20)) &&
////               (arrayofStones[j].y<arrayofBullet[i].y &&
////                arrayofBullet[i].y<arrayofStones[j].y+20))
////            {
////                arrayofStones[j].isActive = false;
////                arrayofBullet[i].isActive = false;
////            }
//        }
//    }
}
