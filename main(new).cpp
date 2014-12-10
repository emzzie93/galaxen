#include <iostream>
#include <string>
#include <SDL.h>
#include "setup.h"

using namespace std;

int main(int argc, char **argv)
{

GameSetup Astroids;
Astroids.setup();
Astroids.LoadMedia();

//Our event structure
    SDL_Event e;
    bool quit = false;
    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
            if (e.type == SDL_KEYDOWN)
            {
                quit = true;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                quit = true;
            }
        }
    //render the background
   Astroids.render();
    }
Astroids.close();

    return 0;
}
