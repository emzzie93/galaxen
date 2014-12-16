#include "Menysetup.h"



Menysetup::Menysetup(int xpos, int ypos, int width, int height)
{
    posMeny.x = xpos;
    posMeny.y = ypos;
    posMeny.w = width;
    posMeny.h = height;
}


void Menysetup::CreateMeny(GameSetup World)
 {

Menyheader = SDL_LoadBMP("Asteroids.bmp");
	if (Menyheader == NULL)
	{
        std::cout << "Error in loading Menyheader." << SDL_GetError() << std::endl;
		SDL_Quit();
	}
headermeny = SDL_CreateTextureFromSurface(World.GameRender, Menyheader);

SDL_FreeSurface(Menyheader);

Newgame = SDL_LoadBMP("play.bmp");
	if (Newgame == NULL)
	{
        std::cout << "Error in loading newgame." << SDL_GetError() << std::endl;
		SDL_Quit();
	}
newgame = SDL_CreateTextureFromSurface(World.GameRender, Newgame);
SDL_FreeSurface(Newgame);

 About = SDL_LoadBMP("about.bmp");
	if (About == NULL)
	{
        std::cout << "Error in loading Instructions." << SDL_GetError() << std::endl;
		SDL_Quit();
	}
about = SDL_CreateTextureFromSurface(World.GameRender, About);
SDL_FreeSurface(About);

Quitgame = SDL_LoadBMP("exit.bmp");
	if (Quitgame == NULL)
	{
        std::cout << "Error in loading Quitgame." << SDL_GetError() << std::endl;
		SDL_Quit();
	}
quitgame = SDL_CreateTextureFromSurface(World.GameRender, Quitgame);
SDL_FreeSurface(Quitgame);


}


