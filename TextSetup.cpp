//
// void Score(SDL_Renderer* GameRender)
// {
//
//     Initialize SDL_ttf library
//    if (TTF_Init() != 0)
//    {
//        cerr << "TTF_Init() Failed: " << TTF_GetError() << endl;
//        SDL_Quit();
//        exit(1);
//    }
//
//     Load a font
//
//    font = TTF_OpenFont("LucidaTypewriterBold.ttf",14);
//    if (font == NULL)
//    {
//        cerr << "TTF_OpenFont() Failed: " << TTF_GetError() << endl;
//        TTF_Quit();
//        SDL_Quit();
//        exit(1);
//    }
//
//     Write text to surface
//
//    if (text == NULL)
//    {
//        cerr << "TTF_RenderText_Solid() Failed: " << TTF_GetError() << endl;
//        TTF_Quit();
//        SDL_Quit();
//        exit(1);
//    }
// }
//
// void TextOnScreen(SDL_Rect position, SDL_Renderer* GameRender, const char text); {
//    SDL_Color text_color = {250, 250, 250};
//    text = TTF_RenderText_Solid(font, text ,text_color);
//    texttest = SDL_CreateTextureFromSurface(GameRender, text);
// }
//
//
