/**
* @file main.c
* @author Beyram Ayadi
* @version 1.0
* @date 16,6,2020
*
*/






#include <stdlib.h>
#include <stdio.h>
#include "screenshare.h"


int main()
{

    SDL_Surface*ecran=NULL;
    background back;
    back=Initialisation_map(back);
    SDL_Event e;
    int c=1;
    SDL_Init(SDL_INIT_EVERYTHING);
    ecran = SDL_SetVideoMode(1200,640, 32, SDL_HWSURFACE);
    while(c)
    {
        affichage_backi(back,ecran);
        back=scroll1(back,e);
        back=scroll2(back,e);
        //affichage_background(back,ecran);
        SDL_PollEvent(&e);
        switch(e.type)
        {
            case SDL_QUIT:
            c=0;
            break;
        }


    }
    SDL_Quit();




return 0;
}
