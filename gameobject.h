#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_
#include <SDL.h>

extern SDL_Window* gWindow;

extern SDL_Surface* gScreenSurface;

extern SDL_Surface* Background;

extern SDL_Surface* Ship;

extern SDL_Event Event;



//Screen dimension
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SPRITE_WIDTH = 60;
const int SPRITE_HEIGHT = 80;

class theShip
{
public:

    theShip();

    void ship_movement();
    void show_ship();

private:
    int x;
    int y;

};



#endif // _GAMEOBJECT_H_
