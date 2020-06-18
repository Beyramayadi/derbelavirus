#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "ai.h"



int main(int argc, char **argv)
{
        SDL_Surface *ecran = NULL;
    SDL_Surface *perso= NULL,*back=NULL;
    SDL_Event event;
    SDL_Rect positionperso;
    SDL_Rect position,pos;
position.x=700;
position.y=650;

    int continuer = 1;
    ennemie e;
    
    pos.x=0;
    pos.y=0;

    positionperso.w=100;
    positionperso.h=200;
    positionperso.x=0;
    positionperso.y=400;


    
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(1000, 518, 32, SDL_HWSURFACE |SDL_DOUBLEBUF);
    SDL_WM_SetCaption(" Game   ", NULL);
    
    perso = IMG_Load("perso0.png");
  
    
    back=IMG_Load("123.png");
        SDL_BlitSurface(back, NULL, ecran, &pos);   
    SDL_BlitSurface(perso, NULL, ecran, &positionperso);
    e=initialiser_ennemie(e);

    SDL_Flip(ecran);


    while(continuer)
    {   

        
       e=deplacer_ennemie( e ,ecran,position,positionperso);
SDL_BlitSurface(back, NULL, ecran, &pos);
    SDL_BlitSurface(perso, NULL, ecran, &positionperso);

       SDL_PollEvent(&event);
       switch(event.type)
        {
            case SDL_QUIT:
            continuer = 0;
            break;
            case SDL_KEYDOWN:
            
            switch(event.key.keysym.sym)
            {   

                case SDLK_LEFT:
             
                positionperso.x -=3;
                 


                break;

                case SDLK_RIGHT:
            
                positionperso.x +=3;

           

                break;
                
            
            }
          

       
                  SDL_BlitSurface(perso, NULL, ecran, &positionperso);

		SDL_Flip(ecran);
 
                  
       
        }

    }

	SDL_FreeSurface(back);
    SDL_FreeSurface(perso);

    freesurfaceennemi(&e);
    
    SDL_Quit();
    return EXIT_SUCCESS;
}
