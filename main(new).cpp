#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

#include "gameobject.h"

using namespace std;


GameSetup World;
ObjectSetup Objects;

void render1(SDL_Texture* texture,SDL_Rect* type)
{
    SDL_RenderCopy(World.GameRender, texture, NULL, type);
    SDL_RenderPresent(World.GameRender);
}

int main(int, char **)
{
World.setup();
World.LoadMedia();

theShip myShip;
theStone myStone;
theHeart myHeart;
theStar myStar;
theBullet myBullet;

myStone.init_stone();
myHeart.init_heart();
myStar.init_star();
myBullet.init_bullet();

Objects.CreateObjects(World);

    //Our event structure
    bool quit = false;
    SDL_Event Event;
    while (!quit)
    {
    //render the background
    World.render();//ritar ut bakgrund
    myShip.collision(&myHeart,&myStar);

    myHeart.add_heart();
    myHeart.heart_movement();
    if(myHeart.isActive==true)
    {
    render1(Objects.heart1,&myHeart.posHeart);
    }

    myStar.add_star();
    myStar.star_movement();
    if(myStar.isActive==true)
    {
    render1(Objects.star1,&myStar.posStar);
    }


    myStone.add_stone();//lägger till stenar
    myStone.stone_movement();
    for (int i = 0;i<20;i++)
    {
        myStone.getStone(i);
        myShip.collisionWstone(&myStone);
        render1(Objects.stone1,&myStone.posStone);
    }

     for (int i = 0;i<20;i++)
    {
        myStone.getStone(i);
        myShip.collisionWstone(&myStone);
    }


    myBullet.bullet_movement();
    for (int i = 0;i<20;i++)//ritar ut bullet
    {
        myBullet.getBullet(i);
        myStone.collision(myBullet);
        render1(Objects.bullet1,&myBullet.posBullet);
    }

    myShip.ship_movement();//flyttar ship

    render1(Objects.ship1,&myShip.posShip);//Ritar ut ship

    while (SDL_PollEvent(&Event))
        {
            switch( Event.type )
            {
            /* Look for a keypress */
        case SDL_QUIT:
            quit = true;
            break;

        case SDL_KEYDOWN:
                /* Check the SDLKey values and move change the coords */
            switch( Event.key.keysym.sym ){
                    case SDLK_SPACE:

                        myBullet.add_bullet(myShip.posShip.x,myShip.posShip.y);

                        break;
            }
            }
        }
    SDL_Delay(20);

    }

World.close();

return 0;
}


