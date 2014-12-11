#include <iostream>
#include <string>
#include <SDL.h>


#include "gameobject.h"

using namespace std;
SDL_Texture* ship1 = nullptr;
SDL_Texture* stone1 = nullptr;
SDL_Texture* heart1 = nullptr;
SDL_Texture* star1 = nullptr;
SDL_Texture* bullet1 = nullptr;


GameSetup World;

void render1(SDL_Texture* texture,SDL_Rect* type)
{
    SDL_RenderCopy(World.GameRender, texture, NULL, type);
    SDL_RenderPresent(World.GameRender);
}
//SDL_Texture* createTexture(char name,const char nameOnFile)
//{
//SDL_Surface* Sf;
//Sf = SDL_LoadBMP("nameOnFile");
//	if (Sf == NULL)
//	{
//        std::cout << "Error in loading player." << SDL_GetError() << std::endl;
//		SDL_Quit();
//	}
//SDL_Texture* name;
//name = SDL_CreateTextureFromSurface(World.GameRender, Sf);
//SDL_FreeSurface(Sf);
//return name;
//}

int main(int, char **)
{


World.setup();
World.LoadMedia();

theShip myShip;
theStone myStone;
theHeart myHeart;
theStar myStar;
theBullet myBullet;

myStone.init_stone();
myHeart.init_heart();
myStar.init_star();

Star = SDL_LoadBMP("star.bmp");
	if (Star == NULL)
	{
        std::cout << "Error in loading Star." << SDL_GetError() << std::endl;
		SDL_Quit();
	}
star1 = SDL_CreateTextureFromSurface(World.GameRender, Star);
SDL_FreeSurface(Star);

 Heart = SDL_LoadBMP("heart.bmp");
	if (Heart == NULL)
	{
        std::cout << "Error in loading player." << SDL_GetError() << std::endl;
		SDL_Quit();
	}
heart1 = SDL_CreateTextureFromSurface(World.GameRender, Heart);
SDL_FreeSurface(Heart);

 Ship = SDL_LoadBMP("smallship.bmp");
	if (Ship == NULL)
	{
        std::cout << "Error in loading player." << SDL_GetError() << std::endl;
		SDL_Quit();
	}
ship1 = SDL_CreateTextureFromSurface(World.GameRender, Ship);
SDL_FreeSurface(Ship);

Stone = SDL_LoadBMP("stone.bmp");
	if (Ship == NULL)
	{
        std::cout << "Error in loading player." << SDL_GetError() << std::endl;
		SDL_Quit();
	}
stone1 = SDL_CreateTextureFromSurface(World.GameRender, Stone);
SDL_FreeSurface(Stone);

Bullet = SDL_LoadBMP("bullet.bmp");
	if (Bullet == NULL)
	{
        std::cout << "Error in loading player." << SDL_GetError() << std::endl;
		SDL_Quit();
	}
bullet1 = SDL_CreateTextureFromSurface(World.GameRender, Bullet);
SDL_FreeSurface(Bullet);



//SDL_SetTextureAlphaMod(ship1, 125);
//SDL_SetTextureBlendMode(ship1, SDL_BLENDMODE_ADD);
//Our event structure
    bool quit = false;
    SDL_Event Event;
    while (!quit)
    {
    //render the background
    World.render();//ritar ut bakgrund
    myHeart.add_heart();
    myStone.add_stone();//lägger till stenar
    myStar.add_star();
    myStar.star_movement();
    render1(star1,&myStar.posStar);
    myShip.ship_movement();//flyttar ship
    render1(ship1,&myShip.posShip);//Ritar ut ship
    myHeart.heart_movement();
     if(myHeart.isActive==true)
    {
    render1(heart1,&myHeart.posHeart);
    }

    myBullet.bullet_movement();
     for (int i = 0;i<20;i++)//ritar ut stone
    {
        myBullet.loop(i);
        render1(bullet1,&myBullet.posBullet);
    }

    myStone.stone_movement();//flyttar stone
    for (int i = 0;i<20;i++)//ritar ut stone
    {
        myStone.loop(i);
        render1(stone1,&myStone.posStone);
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
                /* Check the SDLKey values and move change the coords */
            switch( Event.key.keysym.sym ){
                    case SDLK_SPACE:
                        myBullet.add_bullet();
                        break;
            }
            }
//            if (Event.type == SDL_QUIT)
//            {
//                quit = true;
//            }
//            if(SDLK_SPACE)
//            {
//                myBullet.add_bullet();
//            }

        }
    SDL_Delay(20);

    }

World.close();

    return 0;
}


