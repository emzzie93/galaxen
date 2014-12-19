/*
 * IDA Programvaruproduktion AB (u.p.a.)
 *
 * IDENTIFIERING
 *
 * Filnamn:    setup.h
 * Enhetsnamn:  setup
 * Typ:        klassdekleration
 * Skriven av: Emma Södertröm
 *             Matilda Wreth
 *
 * BESKRIVNING
 *
 * Deklarerar klassen GameSetup och dess parametrar och funktioner.
 */


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
    SDL_Surface *gameover = nullptr;
    SDL_Surface *instructions = nullptr;

    SDL_Texture *Instructions = nullptr;
    SDL_Texture *tex = nullptr;
    SDL_Texture *Gameover = nullptr;

    Mix_Music *effect1 = nullptr;
    Mix_Music *menymusik = nullptr;
    Mix_Music *gamemusik = nullptr;
    Mix_Music *effect2 = nullptr;

    long counter = 0;

    GameSetup() = default;
    ~GameSetup()=default;

    bool quit = false;
    bool playeffect;
    bool playmeny;
    bool playgame;
    bool playeffect2;

//functions
    void setup();
    void close();
    void render();
    void LoadMedia();
    void PlaySound();
    void SetInstruction(SDL_Renderer* GameRenderer, SDL_Texture* tex);
    void GameOver();
};

/*
 * SLUT PÅ FILEN setup.h
 */

#endif
