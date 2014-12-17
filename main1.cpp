#include <iostream>
#include <string>
#include <sstream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "gameobject.h"
#include "setup.h"
#include "Menysetup.h"
#include "asteroids.h"

using namespace std;
GameSetup World;

//    int score = 124;
//    string text = to_string(score);
//    cout << text << endl




int main(int argc, char *argv[])
{


    GameSetup World;
    Asteroids Gameloop;
    World.setup();
    World.LoadMedia();
    World.playmeny = true;
    World.PlaySound();

    Menysetup astroids(200,30,230,100);
    Menysetup Newgame(240,160,150,50);
    Menysetup About(240,240,150,50);
    Menysetup Quitgame(240,320,150,50);

    astroids.CreateMeny(World);

//Our event structure

    SDL_Event Event;
    while (!World.quit)
    {

        SDL_RenderClear(World.GameRender);
        //render the background
        World.render();
        SDL_RenderCopy(World.GameRender, astroids.headermeny, NULL, &astroids.posMeny);
        SDL_RenderCopy(World.GameRender, astroids.newgame, NULL, &Newgame.posMeny);
        SDL_RenderCopy(World.GameRender, astroids.about, NULL, &About.posMeny);
        SDL_RenderCopy(World.GameRender, astroids.quitgame, NULL, &Quitgame.posMeny);
        SDL_RenderPresent(World.GameRender);

        int Mx = 0;
        int My = 0;
        SDL_GetMouseState(&Mx, &My);

        while (SDL_PollEvent(&Event))
        {
            if (Event.type == SDL_QUIT)
            {
                World.quit = true;
            }
            else
            {
                if(Mx >= Quitgame.posMeny.x && Mx <= Quitgame.posMeny.x + Quitgame.posMeny.w && My >= Quitgame.posMeny.y && My <= Quitgame.posMeny.y + Quitgame.posMeny.h)
                {
                    World.playeffect = true;
                    World.PlaySound();
                    SDL_SetTextureColorMod(astroids.quitgame, 250, 0, 0 );
                    if (Event.type == SDL_MOUSEBUTTONDOWN)  //this calls an event, I assume that you already know how to make an event right?
                    {
                        if (Event.button.button == SDL_BUTTON_LEFT)
                        {
                            //if it is pressed then play1 becomes true which you could use to initiate the newgame
                            World.quit = true;
                        }
                    }
                }
                else
                {
                    SDL_SetTextureColorMod(astroids.quitgame, 250, 250, 250);
                    if(Mx >= About.posMeny.x && Mx <= About.posMeny.x + About.posMeny.w && My >= About.posMeny.y && My <= About.posMeny.y + About.posMeny.h)
                    {
                        World.playeffect = true;
                        World.PlaySound();

                        SDL_SetTextureColorMod(astroids.about, 250, 0, 0 );

                        if (Event.type == SDL_MOUSEBUTTONDOWN)  //this calls an event, I assume that you already know how to make an event right?
                        {
                            World.SetInstruction(World.GameRender, World.tex);
                        }
                    }
                    else
                    {

                        SDL_SetTextureColorMod(astroids.about, 250, 250, 250);
                        if(Mx >= Newgame.posMeny.x && Mx <= Newgame.posMeny.x + Newgame.posMeny.w && My >= Newgame.posMeny.y && My <= Newgame.posMeny.y + Newgame.posMeny.h)
                        {
                            World.playeffect = true;
                            World.PlaySound();

                            SDL_SetTextureColorMod(astroids.newgame, 250, 0, 0 );

                            if (Event.type == SDL_MOUSEBUTTONDOWN)  //this calls an event, I assume that you already know how to make an event right?
                            {
                                if (Event.button.button == SDL_BUTTON_LEFT)
                                {
                                    //if it is pressed then play1 becomes true which you could use to initiate the newgame
                                    cout <<  "Starta spelet" << endl;


                                    Gameloop.Play(argc,argv);


                                }
                            }
                        }
                        else
                        {
                            SDL_SetTextureColorMod(astroids.newgame, 250, 250, 250);
                        }
                    }
                }
            }
        }

    }

    World.close();

    return 0;

}

