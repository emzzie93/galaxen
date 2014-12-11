#include <iostream>
#include <string>
#include <SDL.h>


#include "gameobject.h"

using namespace std;
SDL_Texture* ship1 = nullptr;
SDL_Texture* stone1 = nullptr;
GameSetup World;

void render1(SDL_Texture* texture,SDL_Rect* type)
{
    SDL_RenderCopy(World.GameRender, texture, NULL, type);
    SDL_RenderPresent(World.GameRender);
}


int main(int, char **)
{


World.setup();
World.LoadMedia();
theShip myShip;
theStone myStone;
myStone.init_stone();
 Ship = SDL_LoadBMP("smallship.bmp");
	if (Ship == NULL)
	{
        std::cout << "Error in loading player." << SDL_GetError() << std::endl;
		SDL_Quit();
	}
ship1 = SDL_CreateTextureFromSurface(World.GameRender, Ship);

Stone = SDL_LoadBMP("stone.bmp");
	if (Ship == NULL)
	{
        std::cout << "Error in loading player." << SDL_GetError() << std::endl;
		SDL_Quit();
	}
stone1 = SDL_CreateTextureFromSurface(World.GameRender, Stone);




SDL_SetTextureAlphaMod(ship1, 125);
SDL_SetTextureBlendMode(ship1, SDL_BLENDMODE_ADD);
//Our event structure
    bool quit = false;
    SDL_Event Event;
    while (!quit)
    {
    //render the background
    World.render();//ritar ut bakgrund
    myStone.add_stone();//lägger till stenar
    myShip.ship_movement();//flyttar ship
    render1(ship1,&myShip.posShip);//Ritar ut ship
    myStone.stone_movement();//flyttar stone
    for (int i = 0;i<20;i++)//ritar ut stone
    {
        myStone.loop(i);
        render1(stone1,&myStone.posStone);
    }

    while (SDL_PollEvent(&Event))
        {
            if (Event.type == SDL_QUIT)
            {
                quit = true;
            }

        }
    SDL_Delay(20);

    }

World.close();

    return 0;
}


