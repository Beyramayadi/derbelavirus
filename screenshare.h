#ifndef SCREENSHARE_H_INCLUDED
#define SCREENSHARE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct background
{
        SDL_Rect cam1;
	SDL_Rect cam2;
	SDL_Surface *background1;
	int  speed1;
        int  speed2;
	
        SDL_Rect positionback1;
	SDL_Rect positionback2;
int button;
}background;



background Initialisation_map (background back);
void affichage_backi(background backi,SDL_Surface*ecran);

background scroll1(background back,SDL_Event e);
background scroll2(background back,SDL_Event e);



#endif // SCREENSHARE_H_INCLUDED