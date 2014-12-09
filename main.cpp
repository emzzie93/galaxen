#include <SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <SDL_image.h>
#include "gameobject.h"


bool init()
{
    bool success = true;

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
		gWindow = SDL_CreateWindow( "Space Shooter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
        {
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }
    return success;
}

//Load Media
bool loadMedia()
{
    bool success = true;

    Background = SDL_LoadBMP("background.bmp");

    if(Background == NULL)
    {
        printf("Failed to load Background!\n");
        success = false;
    }

    Ship = SDL_LoadBMP("smallship.bmp");
	if (Ship == NULL)
	{
		printf("Error in loading player.");
		success = false;
	}
	return success;
}

//Free media and shuts down SDL
void close()
{
    SDL_FreeSurface(Background);
	Background = NULL;
	SDL_FreeSurface(Ship);
	Ship = NULL;

    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    SDL_Quit();
}

int main(int argc, char* args[])
{

    bool quit = false;
    theShip myShip;

   if(!init())
   {
       printf( "Failed to initialize!\n" );
   }
   else
    {
        if(!loadMedia())
        {
             printf( "Failed to load media!\n" );
        }
    }

    while(!quit)
    {
    SDL_BlitSurface(Background, NULL, gScreenSurface, NULL);
    myShip.show_ship();
            while(SDL_PollEvent(&Event) != 0)
            {
                if (Event.type == SDL_QUIT)
                {
                quit = true;
                break;
                }



            }
            SDL_UpdateWindowSurface( gWindow );
    }
    close();

    return 0;
}

