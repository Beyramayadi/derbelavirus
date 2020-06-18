#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED
#include <stdio.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include <stdlib.h>
#include "SDL/SDL_ttf.h"
#include <time.h>
typedef struct{
  SDL_Surface * fond;
  FILE * f;
}enigme;
typedef struct{
  SDL_Surface * fond;
  
}enig;
typedef struct{
  SDL_Surface * image;
  
}eni;
typedef struct {
  char question [400];
  char c1[50];
 char c2[50];
 char c3[50];
 char j [50];
}infoenigme;
enigme initEnigme();
void enigmealeatoire(SDL_Surface *screen ,enig w );
int enigmestatique(eni q, SDL_Surface *screen, SDL_Event event);
void affichageenigme(infoenigme rep, SDL_Surface *screen, enigme e);
int alea();
int aleatoire();
infoenigme extraireEnigme(enigme e);
int reponseenigme(infoenigme rep, SDL_Event event);
#endif
