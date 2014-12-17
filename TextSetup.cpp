#include "TextSetup.h"


// void TextSetup::ScoreInit()
// {
//
//
//     //Load a font
//
//
//
//     //Write text to surface
//
////    if (text == NULL)
////    {
////        std::cerr << "TTF_RenderText_Solid() Failed: " << TTF_GetError() << std::endl;
////        TTF_Quit();
////        SDL_Quit();
//////        exit(1);
////    }
// }
TextSetup::TextSetup(){

ScoreRect.y=0;
ScoreRect.x=0;
ScoreRect.w=60;
ScoreRect.h=30;
}


 void TextSetup::TextOnScreen( SDL_Renderer* GameRender, long skrivdetta) {
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
       // exit(1);
    }

    SDL_Color text_color = {250, 250, 250};
    //int score = 124;
//    std::string text = to_string(score);
   // std::cout<< text << std::endl
    std::ostringstream ss;
    //long num = 123456;
    ss << skrivdetta;

    const char* string1 = ss.str().c_str();
    std::cout << string1 << std::endl;


    text = TTF_RenderText_Solid(font, string1 ,text_color);
    texttest = SDL_CreateTextureFromSurface(GameRender, text);

    SDL_RenderCopy(GameRender,texttest, NULL, &ScoreRect);
    SDL_RenderPresent(GameRender);
 }


