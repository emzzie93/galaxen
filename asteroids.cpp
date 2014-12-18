#include "ObjectSetup.h"
#include "gameobject.h"
#include "asteroids.h"
#include "TextSetup.h"



void Asteroids::Play(int argc, char *argv[])
{

    int time_point = 0;
    int time_level = 0;
    long currlevel = 1;

    GameSetup World;
    ObjectSetup Objects;
    TextSetup Texten;

//Initierar World och laddar upp bakgrund
    World.setup();
    World.LoadMedia();
    World.playgame = true;
    World.playmeny = false;
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

//Text.ScoreInit
    Objects.CreateObjects(World);

//Skapar en bool och en Event struktur
    bool quit = false;
    SDL_Event Event;

//loop som testar om anv�ndaren vill avsluta
    while (!quit)
    {
        //ritar ut bakgrund
        World.render();

        //Flyttar skepp och kollar kollision med hj�rta eller stj�rna
        myShip.ship_movement();
        myShip.collision(&myHeart,&myStar);
        SDL_RenderCopy(World.GameRender, Objects.ship1, NULL, &myShip.position);

        //l�gger till hj�rta, flyttar hj�rta, m�lar upp hj�rta
        myHeart.add();
        myHeart.movement();
        if(myHeart.isActive==true)
        {
            SDL_RenderCopy(World.GameRender, Objects.heart1, NULL, &myHeart.position);
        }

        //l�gger till stj�rna, flyttar stj�rna, m�lar upp stj�rna
        myStar.add();
        myStar.movement();
        if(myStar.isActive==true)
        {
            SDL_RenderCopy(World.GameRender, Objects.star1, NULL, &myStar.position);
        }

        //l�gger till sten, flyttar sten, m�lar upp sten, kollision skepp/sten
        myStone.add();
        myStone.movement(myShip.level);
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

        //flyttar skott, m�lar upp skott,kollision skott/sten
        myBullet.movement();
        for (int i = 0; i<20; i++) //ritar ut bullet
        {
            myBullet.getBullet(i);
            myStone.collision(&World);

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
                    World.playeffect = true;
                    World.PlaySound();
                    break;

                case SDLK_q:
                    quit = true;
                    break;
                }
            }
        }

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
        if(time_level == 1500 || time_level == 3000 || time_level == 4500)
        {
            myShip.level_up();
            currlevel +=1;
        }

        time_point++;
        if(time_point == 100)
        {
            myShip.add_point(1);
            time_point = 0;
        }

        Texten.TextOnScreen();
        Texten.SetPoints(World.GameRender, myShip.point, Texten.font);
        Texten.SetLives(World.GameRender, myShip.life, Texten.font);
        Texten.SetLevel(World.GameRender,currlevel, Texten.font);
        SDL_RenderPresent(World.GameRender);
        SDL_Delay(20);


    }

    World.GameOver();
    SDL_DestroyWindow(World.GameWindow);
    World.playgame = false;
    World.playmeny = true;
    World.PlaySound();
}



