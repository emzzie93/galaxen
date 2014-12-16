#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

#include <SDL_mixer.h>
#include "gameobject.h"
#include "setup.h"
#include "Menysetup.h"
#include "asteroids.h"

using namespace std;
GameSetup World;

SDL_Texture* texttest = nullptr;


int main(int argc, char *argv[])
{

    GameSetup World;
    Asteroids Gameloop;
    World.setup();
    World.LoadMedia();
    World.PlaySound();

    Menysetup astroids(200,30,230,100);
    Menysetup Newgame(240,160,150,50);
    Menysetup About(240,240,150,50);
    Menysetup Quitgame(240,320,150,50);

    astroids.CreateMeny(World);

    // Initialize SDL_ttf library
    if (TTF_Init() != 0)
    {
        cerr << "TTF_Init() Failed: " << TTF_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    // Load a font
    TTF_Font *font;
    font = TTF_OpenFont("LucidaTypewriterBold.ttf",14);
    if (font == NULL)
    {
        cerr << "TTF_OpenFont() Failed: " << TTF_GetError() << endl;
        TTF_Quit();
        SDL_Quit();
        exit(1);
    }

    // Write text to surface
    SDL_Surface *text;
    SDL_Color text_color = {250, 250, 250};
    text = TTF_RenderText_Solid(font,"SCORE:",text_color);

    if (text == NULL)
    {
        cerr << "TTF_RenderText_Solid() Failed: " << TTF_GetError() << endl;
        TTF_Quit();
        SDL_Quit();
        exit(1);
    }
    texttest = SDL_CreateTextureFromSurface(World.GameRender, text);
    SDL_Rect srcrect;

    srcrect.x = 0;
    srcrect.y = 0;
    srcrect.w = 60;
    srcrect.h = 30;


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

//        if (SDL_BlitSurface(text, NULL, World.background, NULL) != 0)
//
//         cerr << "SDL_BlitSurface() Failed: " << SDL_GetError() << endl;
//         break;
//      }
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
                    //Mix_PlayChannel(-1,effect1,0);
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
                        //Mix_PlayChannel(-1,effect1,0);

                        SDL_SetTextureColorMod(astroids.about, 250, 0, 0 );

                        if (Event.type == SDL_MOUSEBUTTONDOWN)  //this calls an event, I assume that you already know how to make an event right?
                        {
                            //bool inst = false;
                            World.SetInstruction(World.GameRender, World.tex);
//                            SDL_DestroyTexture(astroids.about);
//                            SDL_DestroyTexture(astroids.newgame);
//                            SDL_DestroyTexture(astroids.quitgame);
//                            SDL_DestroyTexture(astroids.headermeny);
//
//                            //if it is pressed then play1 becomes true which you could use to initiate the newgame
////                                while (!inst)
//
//                                //inst = true;
//                            SDL_RenderClear(World.GameRender);
//                            SDL_RenderCopy(World.GameRender, World.tex, NULL, NULL );
//                            SDL_Delay(100);
                        }


                    }


                    else
                    {

                        SDL_SetTextureColorMod(astroids.about, 250, 250, 250);
                        if(Mx >= Newgame.posMeny.x && Mx <= Newgame.posMeny.x + Newgame.posMeny.w && My >= Newgame.posMeny.y && My <= Newgame.posMeny.y + Newgame.posMeny.h)
                        {
                            //Mix_PlayChannel(-1,effect1,0);

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



            // SDL_Delay(0);
            //SDL_UpdateWindowSurface(World.GameWindow);

        }

    }

    World.close();

    return 0;

}

