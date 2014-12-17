#include "ObjectSetup.h"
#include "gameobject.h"
#include "asteroids.h"

void Asteroids::Play(int argc, char *argv[])
{

int time_point = 0;
int time_level = 0;

GameSetup World;
ObjectSetup Objects;
//TextSetup Text;

//Initierar World och laddar upp bakgrund
    World.setup();
    World.LoadMedia();
    World.PlaySound();

//Create  stuff
    theShip myShip;
    theStone myStone;
    theHeart myHeart;
    theStar myStar;
    theBullet myBullet;

//Initierar stuff
    myStone.init();
    myHeart.init();
    myStar.init();
    myBullet.init();

//Text
 //Text.ScoreInit
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
        SDL_RenderCopy(World.GameRender, Objects.ship1, NULL, &myShip.position);

        //lägger till hjärta, flyttar hjärta, målar upp hjärta
        myHeart.add();
        myHeart.movement();
        if(myHeart.isActive==true)
        {
            SDL_RenderCopy(World.GameRender, Objects.heart1, NULL, &myHeart.position);
        }

        //lägger till stjärna, flyttar stjärna, målar upp stjärna
        myStar.add();
        myStar.movement();
        if(myStar.isActive==true)
        {
           SDL_RenderCopy(World.GameRender, Objects.star1, NULL, &myStar.position);
        }

        //lägger till sten, flyttar sten, målar upp sten, kollision skepp/sten
        myStone.add();
        myStone.movement();
        for (int i = 0; i<20; i++)
        {
            myStone.getStone(i);
            myShip.collisionWstone();
            if(myStone.isActive == true)
            {
                if(myStone.type == 1)
                {
                    SDL_RenderCopy(World.GameRender, Objects.stone1, NULL, &myStone.position);
                }
                else if(myStone.type == 2)
                {
                    SDL_RenderCopy(World.GameRender, Objects.stone2, NULL, &myStone.position);
                }
                else if(myStone.type == 3)
                {
                   SDL_RenderCopy(World.GameRender, Objects.stone3, NULL, &myStone.position);
                }
            }

        }

        //flyttar skott, målar upp skott,kollision skott/sten
        myBullet.movement();
        for (int i = 0; i<20; i++) //ritar ut bullet
        {
            myBullet.getBullet(i);
            myStone.collision();
            if(myBullet.isActive == true)
            {
               SDL_RenderCopy(World.GameRender, Objects.bullet1, NULL, &myBullet.position);
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
                    myBullet.add(myShip.position.x,myShip.position.y,myShip.position.w);
                    break;

                case SDLK_q:
                    quit = true;
                    break;
                }
            }
        }


        SDL_RenderPresent(World.GameRender);
        SDL_Delay(20);

        if(myShip.lostLife)
        {
            SDL_Delay(1500);
            myShip.lostLife = false;
        }

        if(myShip.life <= 0)
        {
            quit = true;
        }

        time_level++;
        if(time_level == 5000 || time_level == 10000)
        {
            myShip.level_up();
        }

        time_point++;
        if(time_point == 100)
        {
            myShip.add_point(1);
            time_point = 0;
        }

    }
    World.GameOver();
    SDL_DestroyWindow(World.GameWindow);

}



