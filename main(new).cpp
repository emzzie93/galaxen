#include <iostream>
#include <string>
#include <SDL.h>
#include "gameobject.h"

using namespace std;
SDL_Texture* ship1 = nullptr;

int main(int, char **)
{

GameSetup World;
World.setup();
World.LoadMedia();
theShip myShip;
 Ship = SDL_LoadBMP("smallship.bmp");
	if (Ship == NULL)
	{
        std::cout << "Error in loading player." << SDL_GetError() << std::endl;
		SDL_Quit();
	}

ship1 = SDL_CreateTextureFromSurface(World.GameRender, Ship);
SDL_SetTextureAlphaMod(ship1, 125);
SDL_SetTextureBlendMode(ship1, SDL_BLENDMODE_ADD);
//Our event structure
    bool quit = false;
    SDL_Event Event;
    while (!quit)
    {
    //render the background
    World.render();
    SDL_RenderCopy(World.GameRender, ship1, NULL, &myShip.posShip);
    SDL_RenderPresent(World.GameRender);
    //myShip.show_ship(World.background,Ship);
    myShip.ship_movement();
        while (SDL_PollEvent(&Event))
        {
            if (Event.type == SDL_QUIT)
            {
                quit = true;
            }

        }
        SDL_Delay(20);
    //SDL_UpdateWindowSurface(World.GameWindow);

    }
World.close();

    return 0;
}
