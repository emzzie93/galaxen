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
  SDL_Surface *pointSur;
  SDL_Texture *pointTex;
  SDL_Surface *lifeSur;
  SDL_Texture *lifeTex;
  SDL_Rect ScoreRect;
  SDL_Rect LiveRect;



  //void ScoreInit();//(SDL_Renderer* GameRender);
  void TextOnScreen( SDL_Renderer* GameRender, long poang);
  void SetLives(SDL_Renderer* GameRender, long lives);

};

#endif
