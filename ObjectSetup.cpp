/*
 * IDA Programvaruproduktion AB (u.p.a.)
 *
 * IDENTIFIERING
 *
 * Filnamn:    ObjectSetup.cpp
 * Enhetsnamn: ObjectSetup
 * Typ:        Klassdefinition
 * Skriven av: Emma Söderström
 *
 *
 * BESKRIVNING
 *
 * Laddar in bilder på alla rörliga objekt som finns på spelplanen.
 */

#include "ObjectSetup.h"

void ObjectSetup::CreateObjects(GameSetup World)
{
    Star = IMG_Load("star.png");
    if (Star == NULL)
    {
        std::cerr << "Error in loading Star." << SDL_GetError() << std::endl;
        SDL_Quit();
    }
    star1 = SDL_CreateTextureFromSurface(World.GameRender, Star);
    SDL_FreeSurface(Star);

    Heart = IMG_Load("heart.png");
    if (Heart == NULL)
    {
        std::cerr << "Error in loading player." << SDL_GetError() << std::endl;
        SDL_Quit();
    }
    heart1 = SDL_CreateTextureFromSurface(World.GameRender, Heart);
    SDL_FreeSurface(Heart);

    Ship = IMG_Load("fighter-01.png");
    if (Ship == NULL)
    {
        std::cerr << "Error in loading player." << SDL_GetError() << std::endl;
        SDL_Quit();
    }
    ship1 = SDL_CreateTextureFromSurface(World.GameRender, Ship);
    SDL_FreeSurface(Ship);

    Stone = IMG_Load("stone.png");
    if (Ship == NULL)
    {
        std::cerr << "Error in loading player." << SDL_GetError() << std::endl;
        SDL_Quit();
    }
    stone1 = SDL_CreateTextureFromSurface(World.GameRender, Stone);
    SDL_FreeSurface(Stone);

    Stone = IMG_Load("stone2.png");
    if (Ship == NULL)
    {
        std::cerr << "Error in loading player." << SDL_GetError() << std::endl;
        SDL_Quit();
    }
    stone2 = SDL_CreateTextureFromSurface(World.GameRender, Stone);
    SDL_FreeSurface(Stone);

    Stone = IMG_Load("stone3.png");
    if (Ship == NULL)
    {
        std::cerr << "Error in loading player." << SDL_GetError() << std::endl;
        SDL_Quit();
    }
    stone3 = SDL_CreateTextureFromSurface(World.GameRender, Stone);
    SDL_FreeSurface(Stone);

    Bullet = IMG_Load("bullet.png");
    if (Bullet == NULL)
    {
        std::cerr << "Error in loading player." << SDL_GetError() << std::endl;
        SDL_Quit();
    }
    bullet1 = SDL_CreateTextureFromSurface(World.GameRender, Bullet);
    SDL_FreeSurface(Bullet);

}

/*
 * SLUT PÅ FILEN ObjectSetup.cpp
 */
