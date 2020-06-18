/**
* @file enigme.c
* @author Beyram Ayadi
* @version 1.0
* @date 17,6,2020
*
*/
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "enigme.h"
#include <time.h>
enigme initEnigme (){
  enigme e;
  e.f = fopen("listeenigmes.txt", "r");
 e.fond = IMG_Load("cadre.jpg");
 return e;
}
enig initalea (){
  enig w;
  
 w.fond = IMG_Load("cadre.jpg");
 return w;
}
eni inistatique(){
 eni q;
 q.image = IMG_Load("enigme.jpg");
 return q;
}
int alea(){
int pos;
 srand(time(NULL));
pos=rand()%(7-0+1)+0;
return pos;
}
int aleatoire(){
int pos;
 srand(time(NULL));
pos=rand()%(2-1+1)+0;
return pos;
}







infoenigme extraireEnigme(enigme e){
  infoenigme rep [10];
  infoenigme res;
  int i;
  int pos = alea();
  for (i = 0; i < 8; i++) {
    fgets(rep[i].question, 400, e.f);
    fscanf(e.f,"1)%s 2)%s 3)%s -%s\n",rep[i].c1, rep[i].c2, rep[i].c3, rep[i].j);
  }
  strcpy(res.question,rep[pos].question);
  strcpy (res.c1 ,rep[pos].c1);
      strcpy(res.c2 ,rep[pos].c2);
        strcpy(res.c3 ,rep[pos].c3);
          strcpy(res.j ,rep[pos].j);
  return res;
}






int enigmestatique(eni q, SDL_Surface *screen, SDL_Event event){
SDL_Rect image;
image.x = 100;
image.y = 0;
image.h = 300;
image.w = 300;
SDL_BlitSurface(q.image, NULL, screen, &image);
switch(event.type){
         case SDL_KEYDOWN:
            if(event.key.keysym.sym == SDLK_1){
             return 0;
            }else{
              if(event.key.keysym.sym == SDLK_2){
                return 1;
             }else{
               if(event.key.keysym.sym == SDLK_3){
                 return 0;
               }
             }
            }
}
return 0;
}

void enigmealeatoire(SDL_Surface *screen ,enig w ){

SDL_Color jaune = {169,157,52};
SDL_Color jaunefonce = {87,75,15};
SDL_Rect rquesti;
SDL_Rect rquesti2;
SDL_Rect rrep;
SDL_Rect rc1;
SDL_Rect rc2;
SDL_Rect fond;
SDL_Rect rrayon;
SDL_Surface *questsurf;
SDL_Surface *quest2surf;
SDL_Surface *c1surf;
SDL_Surface *c2surf;
SDL_Surface *repsurf;
SDL_Surface *rayonsurf
TTF_Font * police;
char cquesti[] ="Calculer le perimetre du cercle de rayon :";
char cquesti2[] ="Calculer la superficie du cercle de rayon :";
char cc1[10];
char cc2[10];
char crep[10];
char crayon[10];
 int ale = aleatoire();
 int r = alea();
 float rep,c1,c2;
r=r+1;
rquesti.x=240;
rquesti.y=130;
rquesti2.x=240;
rquesti2.y=130;
rc1.x=400;
rc1.y=200;
rc2.x=550;
rc2.y=200;
rrep.x=700;
rrep.y=200;
rrayon.x=240;
rrayon.y=150;
if (ale==1){
rep=2*3.14*r;
   c1=rep-1;
   c2=rep+1;}
else if(ale==2){
rep=3.14*r*r;
   c1=rep-1;
   c2=rep+1;}
gcvt(c1,4,cc1);
gcvt(c2,4,cc2);
gcvt(rep,4,crep);
gcvt(r,2,crayon);


fond.x=200;
fond.y=100;
fond.h = quest2surf->h;
fond.w = quest2surf->w;
if (TTF_Init() < 0) {
  printf("error\n");
}else{
police = TTF_OpenFont("Bebas-Regular.ttf", 24);
questsurf = TTF_RenderText_Solid(police, cquesti, jaune);
quest2surf = TTF_RenderText_Solid(police, cquesti2, jaune);
  c1surf = TTF_RenderText_Solid(police, cc1, jaunefonce);
  c2surf = TTF_RenderText_Solid(police, cc2, jaunefonce);
  repsurf = TTF_RenderText_Solid(police, crep, jaunefonce);
 rayonsurf = TTF_RenderText_Solid(police,crayon, jaune);
if (police == NULL) {
  printf("erreur de chargement du font\n");
}else{ if(ale==1){
   SDL_BlitSurface(w.fond, NULL, screen, &fond);
  SDL_BlitSurface(questsurf, NULL, screen, &rquesti);
  SDL_BlitSurface(c1surf, NULL, screen, &rc1);
  SDL_BlitSurface(c2surf, NULL, screen, &rc2);
  SDL_BlitSurface(repsurf, NULL, screen, &rrep);
SDL_BlitSurface(rayonsurf, NULL, screen, &rrayon);
 }else if(ale==2)
{SDL_BlitSurface(w.fond, NULL, screen, &fond);
  SDL_BlitSurface(quest2surf, NULL, screen, &rquesti2);
  SDL_BlitSurface(c1surf, NULL, screen, &rc1);
  SDL_BlitSurface(c2surf, NULL, screen, &rc2);
  SDL_BlitSurface(repsurf, NULL, screen, &rrep);
SDL_BlitSurface(rayonsurf, NULL, screen, &rrayon);}}
  
TTF_CloseFont(police);
TTF_Quit();
}

int reponseenigmealea(SDL_Event event){
switch(event.type){
         case SDL_KEYDOWN:
            if(event.key.keysym.sym == SDLK_1){
             return 0;
            }else{
              if(event.key.keysym.sym == SDLK_2){
                return 0;
             }else{
               if(event.key.keysym.sym == SDLK_3){
                 return 1;
               }
             }
            }
}return 0;
}
   





void affichageenigme (infoenigme rep, SDL_Surface *screen, enigme e){
  typedef struct{
    SDL_Rect fond;
    SDL_Rect question;
    SDL_Rect c1;
    SDL_Rect c2;
    SDL_Rect c3;
  }posenigme;
posenigme pe;
SDL_Surface *questsurf;
SDL_Surface *c1surf;
SDL_Surface *c2surf;
SDL_Surface *c3surf;
TTF_Font * police;
SDL_Color jaune = {169,157,52};
SDL_Color jaunefonce = {87,75,15};
if (TTF_Init() < 0) {
  printf("error\n");
}else{
police = TTF_OpenFont("Bebas-Regular.ttf", 24);
if (police == NULL) {
  printf("erreur de chargement du font\n");
}else{
  questsurf = TTF_RenderText_Solid(police, rep.question, jaune);
  c1surf = TTF_RenderText_Solid(police, rep.c1, jaunefonce);
  c2surf = TTF_RenderText_Solid(police, rep.c2, jaunefonce);
  c3surf = TTF_RenderText_Solid(police, rep.c3, jaunefonce);
  pe.fond.x = 200;
  pe.fond.y = 100;
  pe.fond.h = questsurf->h;
  pe.fond.w = questsurf->w;
  pe.question.x = 240;
  pe.question.y = 130;
  pe.c1.x= 400;
  pe.c1.y= 200;
  pe.c2.x= 550;
  pe.c2.y= 200;
  pe.c3.x= 700;
  pe.c3.y= 200;
  SDL_BlitSurface(e.fond, NULL, screen, &pe.fond);
  SDL_BlitSurface(questsurf, NULL, screen, &pe.question);
  SDL_BlitSurface(c1surf, NULL, screen, &pe.c1);
  SDL_BlitSurface(c2surf, NULL, screen, &pe.c2);
  SDL_BlitSurface(c3surf, NULL, screen, &pe.c3);}
TTF_CloseFont(police);
TTF_Quit();
}
}
}


int reponseenigme(infoenigme rep, SDL_Event event){
  switch(event.type){
         case SDL_KEYDOWN:
            if(event.key.keysym.sym == SDLK_1){
             if (strcmp (rep.c1, rep.j) == 0) {
               return 1;
             }
            }else{
              if(event.key.keysym.sym == SDLK_2){
                if (strcmp (rep.c2, rep.j) == 0) {
                  return 1;
                }
             }else{
               if(event.key.keysym.sym == SDLK_3){
                 if (strcmp (rep.c3, rep.j) == 0) {
                   return 1;
                 }
               }
             }
            }
}
return 0;
}
