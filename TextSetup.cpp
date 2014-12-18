/*
 * IDA Programvaruproduktion AB (u.p.a.)
 *
 * IDENTIFIERING
 *
 * Filnamn:    TextSetup.cpp
 * Enhetsnamn:  TextSetup
 * Typ:        Moduldeklaration
 * Revision:
 * Skriven av:
 *
 *
 * BESKRIVNING
 *
 * Denna modul ...
 */

/*
 * REFERERADE BIBLIOTEK OCH MODULER
 */

#include "TextSetup.h"

TextSetup::TextSetup()
{

    ScoreRect.y=17;
    ScoreRect.x=60;
    ScoreRect.w=50;
    ScoreRect.h=30;
}



void TextSetup::TextOnScreen()
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

   // SDL_Color text_color = {250, 250, 250};
}

void TextSetup::SetPoints(SDL_Renderer* GameRender, long poang, TTF_Font* font)
{
    SDL_Color text_color = {250, 250, 250};
    std::ostringstream ss;

    ss << poang;

    const char* point = ss.str().c_str();

    pointSur = TTF_RenderText_Solid(font, point ,text_color);
    pointTex = SDL_CreateTextureFromSurface(GameRender, pointSur);
    SDL_FreeSurface(pointSur);
   // TTF_CloseFont(font);

    SDL_RenderCopy(GameRender, pointTex, NULL, &ScoreRect);
    SDL_RenderPresent(GameRender);

}

void TextSetup::SetLives(SDL_Renderer* GameRender, long lives,TTF_Font* font)
{
//    if (TTF_Init() != 0)
//    {
//        std::cerr << "TTF_Init() Failed: " << TTF_GetError() << std::endl;
//        SDL_Quit();
//        //exit(1);
//    }
//
//    font = TTF_OpenFont("LucidaTypewriterBold.ttf",14);
//    if (font == NULL)
//    {
//        std::cerr << "TTF_OpenFont() Failed: " << TTF_GetError() << std::endl;
//        TTF_Quit();
//        SDL_Quit();
//        // exit(1);
//    }

   SDL_Color text_color = {250, 250, 250};

    std::ostringstream ss;
    // std::ostringstream
    ss << lives;

    const char* live = ss.str().c_str();
    lifeSur = TTF_RenderText_Solid(font, live ,text_color);
    lifeTex = SDL_CreateTextureFromSurface(GameRender, lifeSur);
    SDL_FreeSurface(lifeSur);
   // TTF_CloseFont( font );


    LiveRect.y =17;
    LiveRect.x=550;
    LiveRect.w=30;
    LiveRect.h=30;

    SDL_RenderCopy(GameRender, lifeTex, NULL, &LiveRect);
    SDL_RenderPresent(GameRender);

}

void TextSetup::SetLevel(SDL_Renderer* GameRender, long level, TTF_Font* font)
{


    SDL_Color text_color = {250, 250, 250};

    std::ostringstream ss;
    // std::ostringstream
    ss << level;

    const char* levelStr = ss.str().c_str();

    levelSur = TTF_RenderText_Solid(font, levelStr ,text_color);
    stringSur = TTF_RenderText_Solid(font, "LEVEL: " ,text_color);

    levelTex = SDL_CreateTextureFromSurface(GameRender, levelSur);
    stringTex = SDL_CreateTextureFromSurface(GameRender, stringSur);

    SDL_FreeSurface(levelSur);
    SDL_FreeSurface(stringSur);
   // TTF_CloseFont( font );

    LevelRect.y =10;
    LevelRect.x=340;
    LevelRect.w=40;
    LevelRect.h=60;

    stringRect.y=10;
    stringRect.x=250;
    stringRect.w=100;
    stringRect.h=60;

    SDL_RenderCopy(GameRender, levelTex, NULL, &LevelRect);
    SDL_RenderCopy(GameRender, stringTex, NULL, &stringRect);

    SDL_RenderPresent(GameRender);
}


/*
 * SLUT PÅ FILEN TextSetup.cpp
 */
