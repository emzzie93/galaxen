#include "setup.h"

void GameSetup::setup()
{
//initializing SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "SDL_Init error: " << SDL_GetError() << std::endl;
    }
    //create a window and make sure it is correctly started
    //SDL_Window *
    GameWindow = SDL_CreateWindow("Astroids!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (GameWindow == nullptr)
    {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }

    // Create a render to draw the window on, and make sure that it works.
    //SDL_Renderer *
    GameSetup::GameRender = SDL_CreateRenderer(GameWindow, -1, SDL_RENDERER_ACCELERATED);//| SDL_RENDERER_PRESENTVSYNC);
    if (GameRender == nullptr)
    {
        SDL_DestroyWindow(GameWindow);
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }
}

//load the background.
void GameSetup::LoadMedia()
{

    //SDL_Surface *
    background = SDL_LoadBMP("background_converted.bmp");
    if (background== nullptr)
    {
        SDL_DestroyRenderer(GameRender);
        SDL_DestroyWindow(GameWindow);
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
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
    }
}

void GameSetup::PlaySound()
{
    int flags = MIX_INIT_OGG;
    int inited = Mix_Init(flags);



    if(inited & flags != flags)
    {
        std::cerr << "Audio didn't initialize!\n";
    }

    Mix_Chunk* effect1 = NULL;
    Mix_Music* menymusik = NULL;

    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT, 2, 2048);

    effect1 = Mix_LoadWAV("Laser.wav");
    menymusik = Mix_LoadMUS("Menue.ogg");

    if (playmeny)
    {
        Mix_PlayMusic(menymusik,2);
    }

    if (playeffect)
    {
        Mix_PlayChannel(-1,effect1,0);
    }
}

void GameSetup::close()
{
    SDL_DestroyTexture(GameSetup::tex);
    SDL_DestroyRenderer(GameSetup::GameRender);
    SDL_DestroyWindow(GameSetup::GameWindow);
    SDL_Quit();
}

void GameSetup::render()
{
    SDL_RenderCopy(GameSetup::GameRender, GameSetup::tex, NULL, NULL);
}

void GameSetup::SetInstruction(SDL_Renderer* GameRender, SDL_Texture* tex)
{

    //SDL_Surface *
    instructions = SDL_LoadBMP("instructions.bmp");
    if (instructions == nullptr)
    {
        SDL_DestroyRenderer(GameRender);
        SDL_DestroyWindow(GameWindow);
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }

    Instructions = SDL_CreateTextureFromSurface(GameRender, instructions);
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

void GameSetup::GameOver()
{
    //SDL_Surface *
    gameover = SDL_LoadBMP("Game-Over.bmp");
    if (gameover == nullptr)
    {
        SDL_DestroyRenderer(GameRender);
        SDL_DestroyWindow(GameWindow);
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }

    Gameover = SDL_CreateTextureFromSurface(GameRender, gameover);
    //create a texture from the surface
    //SDL_Texture *
    tex = SDL_CreateTextureFromSurface(GameRender, gameover);
    SDL_FreeSurface(gameover);
    if (tex == nullptr)
    {
        SDL_DestroyRenderer(GameRender);
        SDL_DestroyWindow(GameWindow);
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }
    int counter = 0;
    while (counter != 100)
    {
        SDL_RenderClear(GameRender);
        SDL_RenderCopy(GameRender, tex, NULL, NULL );
        SDL_RenderPresent(GameRender);
        SDL_Delay(20);
        counter++;
    }
}



