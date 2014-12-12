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
//Initierar World och laddar upp bakgrund
    World.setup();
    World.LoadMedia();


//Create  stuff
    theShip myShip;
    theStone myStone;
    theHeart myHeart;
    theStar myStar;
    theBullet myBullet;

//Initierar stuff
    myStone.init_stone();
    myHeart.init_heart();
    myStar.init_star();
    myBullet.init_bullet();

    Objects.CreateObjects(World);

//Skapar en bool och en Event struktur
    bool quit = false;
    SDL_Event Event;

//loop som testar om användaren vill avsluta
    while (!quit)
    {
        //ritar ut bakgrund
        World.render();

        //Flyttar skepp och kollar kollision med hjärta eller stjärna
        myShip.ship_movement();
        myShip.collision(&myHeart,&myStar);
        render1(Objects.ship1,&myShip.posShip);


        //lägger till hjärta, flyttar hjärta, målar upp hjärta
        myHeart.add_heart();
        myHeart.heart_movement();
        if(myHeart.isActive==true)
        {
            render1(Objects.heart1,&myHeart.posHeart);
        }

        //lägger till stjärna, flyttar stjärna, målar upp stjärna
        myStar.add_star();
        myStar.star_movement();
        if(myStar.isActive==true)
        {
            render1(Objects.star1,&myStar.posStar);
        }

        //lägger till sten, flyttar sten, målar upp sten, kollision skepp/sten
        myStone.add_stone();
        myStone.stone_movement();
        for (int i = 0; i<20; i++)
        {
            myStone.getStone(i);
            myShip.collisionWstone();
            if(myStone.isActive == true)
            {
                if(myStone.type == 1)
                {
                    render1(Objects.stone1,&myStone.posStone);
                }
                else if(myStone.type == 2)
                {
                    render1(Objects.stone2,&myStone.posStone);
                }
                else if(myStone.type == 3)
                {
                    render1(Objects.stone3,&myStone.posStone);
                }
            }

        }

        //flyttar skott, målar upp skott,kollision skott/sten
        myBullet.bullet_movement();
        for (int i = 0; i<20; i++) //ritar ut bullet
        {
            myBullet.getBullet(i);
            myStone.collision();
            if(myBullet.isActive == true)
            {
                render1(Objects.bullet1,&myBullet.posBullet);
            }
        }



        while (SDL_PollEvent(&Event))
        {
            switch( Event.type )
            {
            /* Look for a keypress */
            case SDL_QUIT:
                quit = true;
                break;

            case SDL_KEYDOWN:
                switch( Event.key.keysym.sym )
                {
                case SDLK_SPACE:
                    //Skapar skott vid mellanslag
                    myBullet.add_bullet(myShip.posShip.x,myShip.posShip.y);

                    break;
                }
            }
        }
        SDL_Delay(20);
        if(myShip.life <= 0)
        {
            quit = true;
        }

    }

    World.close();

    return 0;
}


