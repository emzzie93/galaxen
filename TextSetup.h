/*
 * IDA Programvaruproduktion AB (u.p.a.)
 *
 * IDENTIFIERING
 *
 * Filnamn:    TextSetup.h
 * Enhetsnamn: TextSetup
 * Typ:        Klassdeklaration
 * Skriven av: Emma Söderström
 *             Matilda Wreth
 *             Jessica Fritzen
 *
 *
 * BESKRIVNING
 *
 * Deklarerar text, font etc.
 */

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
  SDL_Surface *lifeSur;
  SDL_Surface *levelSur;
  SDL_Surface *stringSur;

  SDL_Texture *lifeTex;
  SDL_Texture *pointTex;
  SDL_Texture *levelTex;
  SDL_Texture *stringTex;

  SDL_Rect ScoreRect;
  SDL_Rect LiveRect;
  SDL_Rect LevelRect;
  SDL_Rect stringRect;

  SDL_Color text_color;


  void TextOnScreen();
  void SetPoints(SDL_Renderer* GameRender, long points, TTF_Font* font);
  void SetLives(SDL_Renderer* GameRender, long lives, TTF_Font* font);
  void SetLevel(SDL_Renderer* GameRender, long level, TTF_Font* font);


};

/*
 * SLUT PÅ FILEN TextSetup.h
 */

#endif
