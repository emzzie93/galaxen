#ifndef _ASTEROIDS_H_
#define _ASTEROIDS_H_

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

#include "gameobject.h"

using namespace std;


class Asteroids
{
public:
    void Play(int argc, char *argv[]);
    void render1(SDL_Renderer* GameRender,SDL_Texture* texture,SDL_Rect* type);
};

#endif
