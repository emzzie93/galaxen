#ifndef _TEXTSETUP_H_
#define _TEXTSETUP_H_

#include <SDL_ttf.h>
#include <SDL.h>
#include <string>
#include <iostream>
#include <sstream>

class TextSetup
{
public:

  TextSetup();
  ~TextSetup()= default;


  TTF_Font *font;
  SDL_Surface *text;
  SDL_Texture *texttest;
  SDL_Rect ScoreRect;

  //void ScoreInit();//(SDL_Renderer* GameRender);
  void TextOnScreen( SDL_Renderer* GameRender, long text);
};

#endif
