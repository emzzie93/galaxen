#include <random>
#include "gameobject.h"
#include "ObjectSetup.h"

theStone arrayofStones[20];
theBullet arrayofBullet[20];
//SDL_Surface* Stone = NULL;
//SDL_Surface* Ship = NULL;
//SDL_Surface* Heart = NULL;
//SDL_Surface* Star = NULL;
//SDL_Surface* Bullet = NULL;

const Uint8* keystate = SDL_GetKeyboardState(NULL);

//---------------------Ship-klassen----------------------//

theShip::theShip()
{
    posShip.x = 180;
    posShip.y = 400;
    posShip.w = 80;
    posShip.h = 90;
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
}

void theShip :: add_point(int i)
{
    this->point = this->point + i;
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
if ((posShip.x + 10) > 640)
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

void theShip :: collision(theHeart* heart, theStar* star)
{
    if((this->posShip.x<=(heart->posHeart.x+40) && (this->posShip.x + 40) >= heart->posHeart.x) && heart->posHeart.y>=this->posShip.y)
        {
            heart->isActive = false;
            heart->posHeart.x = 0;
            heart->posHeart.y = 0;
            this->add_life();
            std ::cout<<"liv: "<<this->life<< std::endl;
        }
    if((this->posShip.x<=(star->posStar.x+40) && (this->posShip.x + 40) >= star->posStar.x) && star->posStar.y>=this->posShip.y)
        {
            star->isActive = false;
            star->posStar.x = 0;
            star->posStar.y = 0;
            this->add_point(100);
            std::cout<<"Points: "<<this->point<< std::endl;
        }
}
void theShip :: collisionWstone(theStone* stone)
{
    if((this->posShip.x<=(stone->posStone.x+40) && (this->posShip.x + 40) >= stone->posStone.x) && stone->posStone.y>=this->posShip.y)
        {
            stone->isActive = false;
            stone->posStone.x = 0;
            stone->posStone.y = 0;
            this->delete_life();
            std ::cout<<"liv: "<<this->life<< std::endl;
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
            if(arrayofStones[i].posStone.y > 480)
            {
                arrayofStones[i].isActive = false;
            }
            else
            {
                arrayofStones[i].posStone.y += 2;
            }
        }
    }
}

void theStone::add_stone()
{
    if(rand() % 45 == 5)
    {
        for (int i=0; i<20;i++)
        {
            if(arrayofStones[i].isActive == false)
            {
                arrayofStones[i].posStone.x = rand() % 630;
                arrayofStones[i].posStone.y = 0;
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

void theStone::getStone(int i)
{
    if(arrayofStones[i].isActive == true)
    {
        *this = arrayofStones[i];
    }
}

void theStone::collision(theBullet name)
{
    for(int i =0;i<20;i++)
    {
        if(arrayofStones[i].posStone.x<=name.posBullet.x && name.posBullet.x<=(arrayofStones[i].posStone.x + 30) &&
           arrayofStones[i].posStone.y<=name.posBullet.y && name.posBullet.y<= (arrayofStones[i].posStone.y+30))
        {
            arrayofStones[i].isActive = false;
            arrayofStones[i].posStone.x = 0;
            arrayofStones[i].posStone.y = 0;

            name.isActive = false;

        }
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
    if(this->posHeart.y = 470)
    {
        this->isActive = false;
    }
}

void theHeart::add_heart()
{
    if(rand() % 100 == 5)
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
    if((this->posStar.y) = 470)
    {
        this->isActive = false;
    }
}

void theStar::add_star()
{
    if(rand() % 100 == 5)
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
            if(arrayofBullet[i].posBullet.y < 10)
            {
                arrayofBullet[i].isActive = false;
            }else
            {
                arrayofBullet[i].posBullet.y -= 2;
            }
        }
    }
}


void theBullet::add_bullet(int x,int y)

{
for (int i=0; i<20 ;i++)
        {
            if(arrayofBullet[i].isActive == false)
            {

                arrayofBullet[i].posBullet.x = x+33;
                arrayofBullet[i].posBullet.y = y+30;
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

void theBullet::getBullet(int i)
{
    if(arrayofBullet[i].isActive == true)
    {
       *this = arrayofBullet[i];
    }
}

