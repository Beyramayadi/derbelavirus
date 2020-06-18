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

ennemie initialiser_ennemie(ennemie e)
{

 e.direction=1;

 e.pos.x=700;
 e.pos.y=400;
 e.pos.w=137;
 e.pos.h=64;

 e.tab[0]. IMG_Load("0.PNG");

 e.tab[1] = IMG_Load("1.PNG");

 e.tab[2] = IMG_Load("12.PNG");

 e.tab[3] = IMG_Load("2.PNG");


 e.tab2[0] = IMG_Load("2l.png");

 e.tab2[1] = IMG_Load("3l.png");



 e.p1=0;
 e.p2=0;

 e.etat=0; /*for walking */
 e.etat2=0;/*for running left */
 e.etat3=0; /*for running right */


return e;
}

ennemie deplacer_ennemie( ennemie e ,SDL_Surface *ecran, SDL_Rect pos,SDL_Rect positionperso)
{int i=0;
// calculer distance entre personnage et ennemie 
int d=e.pos.x-(positionperso.x+positionperso.w);


if(((d<=0)&&(d>=-180))&&(e.pos.y>=positionperso.y))
{


printf("collision \n");
return e;
}
/*********************************************************************************************************************************/

/*personnage a gauche de l'ennemie distance positive */
if((d>=0)&&(d<=200))
{
if((d>=0)&&(d<=200))
{
e.p1 = SDL_GetTicks();
if (e.p1 - e.p2 >=500 )
{
e.direction=1;	
if((e.direction==1)&&(e.pos.x>positionperso.x)){e.pos.x-=25;}
else if((e.direction==1)&&(e.pos.x<=positionperso.x)){e.direction=0;
e.pos.x+=25;}



SDL_BlitSurface(e.tab2[e.etat2], NULL, ecran, &e.pos);
SDL_Flip(ecran);
printf("pos e :x %d \n",e.pos.x );
printf("etat running left  %d \n",e.etat2 );
printf("d %d \n",d );
SDL_Flip(ecran);
e.p2=e.p1;
if(e.etat2<1){e.etat2++;} 
else{e.etat2=0;}
}
}
return e;
}

else 
e.p1 = SDL_GetTicks();
if (e.p1 - e.p2 >=500 )
{
if((e.direction==1)&&(e.pos.x>pos.y)){e.pos.x-=10;}
else if((e.direction==1)&&(e.pos.x<=pos.y)){e.direction=0;e.etat=2;e.pos.x+=10;}
else if((e.direction==0)&&(e.pos.x<pos.x)){e.pos.x+=10;}
else {e.direction=1;e.etat=0;}


SDL_BlitSurface(e.tab[e.etat], NULL, ecran, &e.pos);
SDL_Flip(ecran);
printf(" pos  pos e :x %d \n",e.pos.x );
printf("etat walking  %d \n",e.etat );
printf("direction %d \n",e.direction );
printf("distance %d \n",d );
SDL_Flip(ecran);
e.p2=e.p1;
if((e.direction==1)&&(e.etat<1)){e.etat++;} 
else if(e.etat==1){e.etat=0;}
else if((e.direction==0)&&(e.etat<3)){e.etat++;}
else{e.etat=2;}

}

return e;
}

SDL_Flip(ecran);
}
void freesurfaceennemi(ennemie *e)
{
int i,j;
for(i=0;i<4;i++)
SDL_FreeSurface(e->tab[i]);
for(j=0;j<2;j++)
SDL_FreeSurface(e->tab2[j]);

}




