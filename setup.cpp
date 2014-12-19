/*
 * IDA Programvaruproduktion AB (u.p.a.)
 *
 * IDENTIFIERING
 *
 * Filnamn:    setup.cpp
 * Enhetsnamn:  setup
 * Typ:        klassdekleration
 * Skriven av: Emma Söderström
 *             Matilda Wreth
 *
 *
 * BESKRIVNING
 *  deklarerar flera setup funtioner där bland annat fönster, bakgrund, ljud osv kan skapas.
 *  Även close funktion där vi förstör och avslutar.
 */

#include "setup.h"


//initialize SDL ,create window, create a render.
void GameSetup::setup()
{
//initializing SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "SDL_Init error: " << SDL_GetError() << std::endl;
    }

//create a window and make sure it is correctly started
    GameWindow = SDL_CreateWindow("Astroids!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (GameWindow == nullptr)
    {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }

// Create a render to draw the window on, and make sure that it works.
    GameSetup::GameRender = SDL_CreateRenderer(GameWindow, -1, SDL_RENDERER_ACCELERATED);
    if (GameRender == nullptr)
    {
        SDL_DestroyWindow(GameWindow);
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }
}

//load the background.
void GameSetup::LoadMedia()
{

    background = SDL_LoadBMP("background_converted2_converted.bmp");
    if (background== nullptr)
    {
        SDL_DestroyRenderer(GameRender);
        SDL_DestroyWindow(GameWindow);
        std::cerr << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }

    //create a texture from the surface
    tex = SDL_CreateTextureFromSurface(GameRender, background);
    SDL_FreeSurface(background);
    if (tex == nullptr)
    {
        SDL_DestroyRenderer(GameRender);
        SDL_DestroyWindow(GameWindow);
        std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }
}

//Play sound
void GameSetup::PlaySound()
{
    int flags = MIX_INIT_OGG;
    int inited = Mix_Init(flags);

    if((inited & flags) != flags)
    {
        std::cerr << "Audio didn't initialize!\n";
    }

    Mix_Chunk* effect1 = nullptr;
    Mix_Chunk* effect2 = nullptr;
    Mix_Music* menymusik = nullptr;


    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT, 2, 2048);

    effect1 = Mix_LoadWAV("Laser.wav");
    effect2 = Mix_LoadWAV("BigExplosion.wav");
    menymusik = Mix_LoadMUS("Menue.ogg");

    if (playmeny)
    {
        Mix_PlayMusic(menymusik,-1);
    }

    if (playeffect)
    {
        Mix_PlayChannel(-1,effect1,0);
        playeffect = false;
    }
    if (playeffect2)
    {
        Mix_PlayChannel(-1, effect2, 0);
        playeffect2 = false;

    }
}

//Destroy open window and renders.
void GameSetup::close()
{
    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(GameRender);
    SDL_DestroyWindow(GameWindow);
    SDL_Quit();
}

void GameSetup::render()
{
    SDL_RenderCopy(GameRender, tex, NULL, NULL);
}

// Load the instruction picture, make it possible to return from function when q is pressed
void GameSetup::SetInstruction(SDL_Renderer* GameRender, SDL_Texture* tex)
{

    instructions = SDL_LoadBMP("instructions.bmp");
    if (instructions == nullptr)
    {
        SDL_DestroyRenderer(GameRender);
        SDL_DestroyWindow(GameWindow);
        std::cerr << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }

    Instructions = SDL_CreateTextureFromSurface(GameRender, instructions);

    //create a texture from the surface
    tex = SDL_CreateTextureFromSurface(GameRender, instructions);
    SDL_FreeSurface(instructions);
    if (tex == nullptr)
    {
        SDL_DestroyRenderer(GameRender);
        SDL_DestroyWindow(GameWindow);
        std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }

    SDL_Event Event;
    bool instruct=true;


    while (instruct)
    {
        SDL_RenderClear(GameRender);
        SDL_RenderCopy(GameRender, tex, NULL, NULL );
        SDL_RenderPresent(GameRender);

        while (SDL_PollEvent(&Event))
        {
            switch (Event.type)
            {
            case SDL_QUIT:
                quit = true;
                break;

            case SDL_KEYDOWN:
                switch ( Event.key.keysym.sym )
                {
                case SDLK_q:
                    instruct = false;
                    break;
                }
            }
        }
    }
}

//loads a Game Over picture.
void GameSetup::GameOver()
{
    gameover = SDL_LoadBMP("Game-Over.bmp");
    if (gameover == nullptr)
    {
        SDL_DestroyRenderer(GameRender);
        SDL_DestroyWindow(GameWindow);
        std::cerr << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }

    Gameover = SDL_CreateTextureFromSurface(GameRender, gameover);

    //create a texture from the surface
    tex = SDL_CreateTextureFromSurface(GameRender, gameover);
    SDL_FreeSurface(gameover);
    if (tex == nullptr)
    {
        SDL_DestroyRenderer(GameRender);
        SDL_DestroyWindow(GameWindow);
        std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }

    //show for a while before exiting
    while (counter != 100)
    {
        SDL_RenderClear(GameRender);
        SDL_RenderCopy(GameRender, tex, NULL, NULL );
        SDL_RenderPresent(GameRender);
        SDL_Delay(20);
        counter++;
    }
}


/*
 * SLUT PÅ FILEN setup.cpp
 */
