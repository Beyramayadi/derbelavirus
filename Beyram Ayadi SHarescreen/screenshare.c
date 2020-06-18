/**
* @file screenshare.C
* @author Beyram Ayadi
* @version 1.0
* @date 16,6,2020
*
*/  
#include <stdlib.h>
#include <stdio.h>
#include "screenshare.h"

background scroll1(background back,SDL_Event e)
{  
SDL_PollEvent(&e);
    switch(e.type)
    {     	
case SDL_KEYDOWN:
    	
  	switch(e.key.keysym.sym)
        {
                   case SDLK_LEFT:
                   back.cam1.x-=200;
                   break;
                   case SDLK_RIGHT:
                   back.cam1.x+=200;
                   break;
        }
	
	
	if(back.cam1.x>=1200)
		back.cam1.x=1200;
	if(back.cam1.x<=0)
		back.cam1.x=0;
    }
return back;	    	      
}

background scroll2(background back,SDL_Event e)
{  
SDL_PollEvent(&e);
    switch(e.type)
    {     	
case SDL_KEYDOWN:
    	
  	switch(e.key.keysym.sym)
        {
                   case SDLK_q:
                   back.cam2.x-=200;
                   break;
                   case SDLK_d:
                   back.cam2.x+=200;
                   break;
        }
	
	
	if(back.cam2.x>=1200)
		back.cam2.x=1200;
	if(back.cam2.x<=0)
		back.cam2.x=0;
    }
return back;	    	      
}


background Initialisation_map (background back)
{

back.positionback1.x=0;
back.positionback1.y=0;
back.positionback1.w=600;
back.positionback1.h=640;

back.cam1.x=0;
back.cam1.y=0;
back.cam1.h=640;
back.cam1.w=600;
back.speed1=10;
back.positionback2.x=602;
back.positionback2.y=0;
back.positionback2.w=600;
back.positionback2.h=640;
back.cam2.x=0;
back.cam2.y=0;
back.cam2.h=640;
back.cam2.w=600;
back.speed2=10;

back.background1=IMG_Load("map.jpg");
return back;
}




void affichage_backi(background back,SDL_Surface*ecran)
{

SDL_BlitSurface(back.background1,&back.cam1,ecran,&back.positionback1);
SDL_Flip(ecran);
SDL_BlitSurface(back.background1,&back.cam2,ecran,&back.positionback2);
SDL_Flip(ecran);

}



