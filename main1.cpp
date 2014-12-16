#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

#include <SDL_mixer.h>
#include "gameobject.h"
#include "Meny(text).h"
#include "asteroids.h"

using namespace std;

SDL_Texture* headermeny = nullptr;
SDL_Texture* newgame = nullptr;
SDL_Texture* aboutpic = nullptr;
SDL_Texture* quitgame = nullptr;
SDL_Texture* texttest = nullptr;
//SDL_Texture* instruction = nullptr;


int main(int argc, char *argv[])
{

    GameSetup World;
    Asteroids Gameloop;
    World.setup();
    World.LoadMedia();
    World.PlaySound();

    theMeny myMeny(200,30,230,100);
    theMeny myNewgame(240,160,150,50);
    theMeny myAbout(240,240,150,50);
    theMeny myQuitgame(240,320,150,50);


    Menyheader = SDL_LoadBMP("Asteroids.bmp");
    Newgame = SDL_LoadBMP("play.bmp");
    About = SDL_LoadBMP("about.bmp");
    Quitgame = SDL_LoadBMP("exit.bmp");


    headermeny = SDL_CreateTextureFromSurface(World.GameRender, Menyheader);
    newgame = SDL_CreateTextureFromSurface(World.GameRender, Newgame);
    aboutpic = SDL_CreateTextureFromSurface(World.GameRender, About);
    quitgame = SDL_CreateTextureFromSurface(World.GameRender, Quitgame);



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
    bool quit = false;
    SDL_Event Event;
    while (!quit)
    {
        SDL_RenderClear(World.GameRender);
        //render the background
        World.render();
        SDL_RenderCopy(World.GameRender, headermeny, NULL, &myMeny.posMeny);
        SDL_RenderCopy(World.GameRender, newgame, NULL, &myNewgame.posMeny);
        SDL_RenderCopy(World.GameRender, aboutpic, NULL, &myAbout.posMeny);
        SDL_RenderCopy(World.GameRender, quitgame, NULL, &myQuitgame.posMeny);
        SDL_RenderCopy(World.GameRender, texttest, NULL, &srcrect);


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
                quit = true;
            }
            else
            {
                if(Mx >= myQuitgame.posMeny.x && Mx <= myQuitgame.posMeny.x + myQuitgame.posMeny.w && My >= myQuitgame.posMeny.y && My <= myQuitgame.posMeny.y + myQuitgame.posMeny.h)
                {
                    //Mix_PlayChannel(-1,World.effect1,0);
                    SDL_SetTextureColorMod(quitgame, 250, 0, 0 );
                    if (Event.type == SDL_MOUSEBUTTONDOWN)  //this calls an event, I assume that you already know how to make an event right?
                    {
                        if (Event.button.button == SDL_BUTTON_LEFT)
                        {
                            //if it is pressed then play1 becomes true which you could use to initiate the newgame
                            quit = true;
                        }
                    }
                }
                else
                {
                    SDL_SetTextureColorMod(quitgame, 250, 250, 250);
                    if(Mx >= myAbout.posMeny.x && Mx <= myAbout.posMeny.x + myAbout.posMeny.w && My >= myAbout.posMeny.y && My <= myAbout.posMeny.y + myAbout.posMeny.h)
                    {
                         //Mix_PlayChannel(-1,effect1,0);
                        SDL_SetTextureColorMod(aboutpic, 250, 0, 0 );
                        if (Event.type == SDL_MOUSEBUTTONDOWN)  //this calls an event, I assume that you already know how to make an event right?
                        {
                            if (Event.button.button == SDL_BUTTON_LEFT)
                            {

                                bool inst = false;
                                //if it is pressed then play1 becomes true which you could use to initiate the newgame
                                while (!inst){

                                    SDL_RenderClear(World.GameRender);
                                    cout <<  "Instruktioner" << endl;
                                    World.SetInstruction(World.GameRender);
                                    SDL_DestroyTexture(aboutpic);
                                    SDL_DestroyTexture(newgame);
                                    SDL_DestroyTexture(quitgame);
                                    SDL_DestroyTexture(headermeny);

                                    SDL_RenderCopy(World.GameRender, World.tex, NULL, NULL );
                                    if (Event.button.button == SDL_BUTTON_LEFT)
                                        {
                                           inst = true;
                                        }
                                }
                            }



                            }

                    }
                    else
                    {

                        SDL_SetTextureColorMod(aboutpic, 250, 250, 250);
                        if(Mx >= myNewgame.posMeny.x && Mx <= myNewgame.posMeny.x + myNewgame.posMeny.w && My >= myNewgame.posMeny.y && My <= myNewgame.posMeny.y + myNewgame.posMeny.h)
                        {
                             //Mix_PlayChannel(-1,effect1,0);
                            SDL_SetTextureColorMod(newgame, 250, 0, 0 );
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
                            SDL_SetTextureColorMod(newgame, 250, 250, 250);
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

