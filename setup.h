#ifndef SETUP_H
#define SETUP_H
#include <iostream>
#include <string>
#include <SDL.h>

class GameSetup
{

public:

    SDL_Window *GameWindow = nullptr;
    SDL_Renderer *GameRender  = nullptr;
    SDL_Surface *background = nullptr;
    SDL_Texture *tex = nullptr;
    bool fullscreen;
    GameSetup() = default;
    ~GameSetup()=default;
    void setup();
    void close();
    void render();
    void LoadMedia();
};

#endif
