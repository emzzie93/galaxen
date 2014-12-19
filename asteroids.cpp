/*
 * IDA Programvaruproduktion AB (u.p.a.)
 *
 * IDENTIFIERING
 *
 * Filnamn:    asteroids.cpp
 * Enhetsnamn: asteroids
 * Typ:        Klassdefinitioner
 * Skriven av: Emma Söderström
               Hugo Johansson
               Matilda Wreth
 *
 *
 * BESKRIVNING
 *
 * Spelet initieras och körs.
 *
 *
 */

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

//Initilizes "World" and loads media and sound.
    World.setup();
    World.LoadMedia();
    World.playmeny = false;
    World.PlaySound();

    Mix_Music* gamemusik = NULL;
    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT, 2, 2048);
    gamemusik = Mix_LoadMUS("Game.ogg");
    Mix_PlayMusic(gamemusik,-1);

//Create  stuff
    theShip myShip;
    theStone myStone;
    theHeart myHeart;
    theStar myStar;
    theBullet myBullet;

//Initilize stuff
    myStone.init();
    myHeart.init();
    myStar.init();
    myBullet.init();

    Objects.CreateObjects(World);

//creates a bool and event structure
    bool quit = false;
    SDL_Event Event;

//loop that tests if the player wants to quit.
    while (!quit)
    {
        //renders background
        World.render();

        //Moves ship and checks for collision with heart or star.
        myShip.ship_movement();
        myShip.collision(&myHeart,&myStar);
        SDL_RenderCopy(World.GameRender, Objects.ship1, NULL, &myShip.position);

        //Add heart, move heart, render heart.
        myHeart.add();
        myHeart.movement();
        if(myHeart.isActive==true)
        {
            SDL_RenderCopy(World.GameRender, Objects.heart1, NULL, &myHeart.position);
        }
        //Add star, move star, render star.
        myStar.add();
        myStar.movement();
        if(myStar.isActive==true)
        {
            SDL_RenderCopy(World.GameRender, Objects.star1, NULL, &myStar.position);
        }

        //Add stone, move stone, render stone, check for collision ship/stone
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

        //Add bullet, move bullet, render bullet, collision bullet/stone.
        myBullet.movement();
        for (int i = 0; i<20; i++) //renders bullet
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
                    //creates a bullet when space it hit.
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

/*
 * SLUT PÅ FILEN asteroids.cpp
 */

