#ifndef _SETUP_H_
#define _SETUP_H_
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>


class GameSetup
{

public:

    SDL_Window *GameWindow = nullptr;
    SDL_Renderer *GameRender  = nullptr;
    SDL_Surface *background = nullptr;
    SDL_Texture* Instructions = nullptr;
    SDL_Texture *tex = nullptr;

    SDL_Texture *Gameover = nullptr;
    SDL_Surface *gameover = nullptr;

    Mix_Music* effect1 = nullptr;
    Mix_Music* menymusik = nullptr;
    Mix_Music* gamemusik = nullptr;
    SDL_Surface* instructions = nullptr;

    GameSetup() = default;
    ~GameSetup()=default;

    bool quit = false;
    bool playeffect;
    bool playmeny;
    bool fullscreen;

    void setup();
    void close();
    void render();
    void LoadMedia();
    void PlaySound();
    void SetInstruction(SDL_Renderer* GameRenderer, SDL_Texture* tex);
    void GameOver();
};

#endif
