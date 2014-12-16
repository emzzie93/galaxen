#include "setup.h"

void GameSetup::setup(){
 //initializing SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "SDL_Init error: " << SDL_GetError() << std::endl;
       // return 1;
    }
    //create a window and make sure it is correctly started
    //SDL_Window *
    GameWindow = SDL_CreateWindow("Astroids!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (GameWindow == nullptr)
    {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
       // return 1;
    }

    // Create a render to draw the window on, and make sure that it works.
    //SDL_Renderer *
    GameSetup::GameRender = SDL_CreateRenderer(GameWindow, -1, SDL_RENDERER_ACCELERATED);//| SDL_RENDERER_PRESENTVSYNC);
    if (GameRender == nullptr)
    {
        SDL_DestroyWindow(GameWindow);
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
      //  return 1;
    }
}

//load the background.
void GameSetup::LoadMedia(){

    //SDL_Surface *
    background = SDL_LoadBMP("background_converted.bmp");
    if (background== nullptr)
    {
        SDL_DestroyRenderer(GameRender);
        SDL_DestroyWindow(GameWindow);
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
       // return 1;
    }

    //create a texture from the surface
    //SDL_Texture *
    tex = SDL_CreateTextureFromSurface(GameRender, background);
    SDL_FreeSurface(background);
    if (tex == nullptr)
    {
        SDL_DestroyRenderer(GameRender);
        SDL_DestroyWindow(GameWindow);
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
       // return 1;
    }
}

    void GameSetup::PlaySound()
    {
    effect1 = Mix_LoadMUS("./galaxen/Laser.ogg");
    if (effect1 == nullptr)
        {
        std::cout << "ERROR: No wav file loaded!" << std::endl;
        }
    menymusik = Mix_LoadMUS("Menue.ogg");

    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_PlayMusic(menymusik,2);
    }


void GameSetup::close(){
    SDL_DestroyTexture(GameSetup::tex);
    SDL_DestroyRenderer(GameSetup::GameRender);
    SDL_DestroyWindow(GameSetup::GameWindow);
    SDL_Quit();
}

void GameSetup::render() {

    //SDL_RenderClear(GameSetup::GameRender);
    SDL_RenderCopy(GameSetup::GameRender, GameSetup::tex, NULL, NULL);
    //SDL_RenderPresent(GameSetup::GameRender);
    }

void GameSetup::SetInstruction(SDL_Renderer* GameRender)
{
    instructions = SDL_LoadBMP("instructions.bmp");
    Instructions = SDL_CreateTextureFromSurface(GameRender, instructions);
    //SDL_Surface *

    if (Instructions == nullptr)
    {
        SDL_DestroyRenderer(GameRender);
        SDL_DestroyWindow(GameWindow);
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
       // return 1;
    }

    //create a texture from the surface
    //SDL_Texture *
    tex = SDL_CreateTextureFromSurface(GameRender, instructions);
    SDL_FreeSurface(instructions);
    if (tex == nullptr)
    {
        SDL_DestroyRenderer(GameRender);
        SDL_DestroyWindow(GameWindow);
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
       // return 1;
    }


}
