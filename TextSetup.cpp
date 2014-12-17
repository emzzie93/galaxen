#include "TextSetup.h"

TextSetup::TextSetup()
{

    ScoreRect.y=17;
    ScoreRect.x=60;
    ScoreRect.w=50;
    ScoreRect.h=30;
}



void TextSetup::TextOnScreen( SDL_Renderer* GameRender, long poang)
{
    // Initialize SDL_ttf library
    if (TTF_Init() != 0)
    {
        std::cerr << "TTF_Init() Failed: " << TTF_GetError() << std::endl;
        SDL_Quit();
        //exit(1);
    }

    font = TTF_OpenFont("LucidaTypewriterBold.ttf",14);
    if (font == NULL)
    {
        std::cerr << "TTF_OpenFont() Failed: " << TTF_GetError() << std::endl;
        TTF_Quit();
        SDL_Quit();
    }

    SDL_Color text_color = {250, 250, 250};

    std::ostringstream ss;

    ss << poang;

    const char* point = ss.str().c_str();

    pointSur = TTF_RenderText_Solid(font, point ,text_color);
    pointTex = SDL_CreateTextureFromSurface(GameRender, pointSur);
    SDL_FreeSurface(pointSur);
    SDL_RenderCopy(GameRender, pointTex, NULL, &ScoreRect);
    SDL_RenderPresent(GameRender);
}

void TextSetup::SetLives(SDL_Renderer* GameRender, long lives)
{
    if (TTF_Init() != 0)
    {
        std::cerr << "TTF_Init() Failed: " << TTF_GetError() << std::endl;
        SDL_Quit();
        //exit(1);
    }

    font = TTF_OpenFont("LucidaTypewriterBold.ttf",14);
    if (font == NULL)
    {
        std::cerr << "TTF_OpenFont() Failed: " << TTF_GetError() << std::endl;
        TTF_Quit();
        SDL_Quit();
        // exit(1);
    }

    SDL_Color text_color = {250, 250, 250};

    std::ostringstream ss;
    // std::ostringstream
    ss << lives;

    const char* live = ss.str().c_str();
    lifeSur = TTF_RenderText_Solid(font, live ,text_color);
    lifeTex = SDL_CreateTextureFromSurface(GameRender, lifeSur);
    SDL_FreeSurface(lifeSur);

    LiveRect.y =17;
    LiveRect.x=550;
    LiveRect.w=30;
    LiveRect.h=30;

    SDL_RenderCopy(GameRender, lifeTex, NULL, &LiveRect);


}
