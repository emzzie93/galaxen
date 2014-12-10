#include <iostream>
#include <string>
#include <SDL.h>
#include "gameobject.h"

using namespace std;
SDL_Texture* ship1 = nullptr;
SDL_Texture* stone1 = nullptr;

int main(int, char **)
{

GameSetup World;
World.setup();
World.LoadMedia();
theShip myShip;
theStone myStone;

Stone = SDL_LoadBMP("stone.bmp");
 if(Stone == NULL)
    {
        std::cout << "Error in loading Stone." << SDL_GetError() << std::endl;
		SDL_Quit();
	}
 stone1 = SDL_CreateTextureFromSurface(World.GameRender, Stone);
 Ship = SDL_LoadBMP("smallship.bmp");
	if (Ship == NULL)
	{
        std::cout << "Error in loading player." << SDL_GetError() << std::endl;
		SDL_Quit();
	}

ship1 = SDL_CreateTextureFromSurface(World.GameRender, Ship);

void render1(SDL_Surface* texture,SDL_Rect* dest)
{
    SDL_RenderCopy(World.GameRender, texture, NULL, dest);
    SDL_RenderPresent(World.GameRender);
}


SDL_SetTextureAlphaMod(ship1, 125);
SDL_SetTextureBlendMode(ship1, SDL_BLENDMODE_ADD);
//Our event structure
    bool quit = false;
    SDL_Event Event;
    while (!quit)
    {
    //render the background
    World.render();
    render(ship1, &myShip.posShip);
    for (int i=0;i<20;i++)
    {
        if(arrayofStones[i].isActive == true)
        {
            render(stone1,&arrayofStones[i].posStone);
        }
    }
        myShip.ship_movement();
        myStone.stone_movement();
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
