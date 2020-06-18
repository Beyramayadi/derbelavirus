#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"


int main(int argc, char *argv[])
{

SDL_Init(SDL_INIT_VIDEO);
TTF_Init();

SDLKey key=SDLK_KP2;

int numEnemy=0;
int numBackground=0;
int i;
int stop=0;
Message msg;
Temps temps;
Hero hero;
Enemy enemy[20];
Entite TabEntity[maxBackground];


//ent entite[20];
char state[20];
strcpy(state,"idleR");

int nbr_enemy=15;
background ImageFond;
Map map;








//cree la surface principale (fenetre)

SDL_Surface *fenetre = NULL;
fenetre= SDL_SetVideoMode(1200 /*1360*/, 640 /*768*/, 32, SDL_HWSURFACE | SDL_DOUBLEBUF /*| SDL_FULLSCREEN*/);


//INITIALISER BACKGROUND

initialiser_background(&ImageFond,fenetre);


//INITIALISER ENNEMIE

initEnemy(enemy,nbr_enemy);

//INITIALISER HERO

initHero(&hero);


//INITIALISER ENTITE

//initialiser_entite(TabEntity[numBackground].entite,TabEntity[numBackground].nbr_entite,ImageFond,numBackground);

initialiser_entite(TabEntity,ImageFond);

//INITIALISER MAP

initMap(&map,&ImageFond,TabEntity[numBackground],&hero,&enemy[numEnemy],fenetre);

//INITIALISER TEMPS

initTemps(&temps,fenetre);



//vie et score

        SDL_Surface *hp;
	//Vie v;
	//VIE_Init(&v);
	SDL_Rect r = {0,70};
	SDL_Rect vieRect = {r.x,r.y-20};
	SDL_Rect vieRectWidth = {0,0,100,10};

	hp = SDL_CreateRGBSurface(0,100,10,32,0,0,0,0);
	SDL_FillRect(hp,NULL,0x00ff00);



//boucle "pseudo" infinie (BASE DU PROGRAMME)
int continuer=1;
SDL_Event event;
SDL_EnableKeyRepeat(10, 100); //ki tokood nezel aala key yehsebha barsha marrat

while(continuer){

if((hero.positionHero.x+hero.spriteHero->w/maxFramesEnemy>=fenetre->w)&&(ImageFond.frame.x==2000-fenetre->w)&&(ImageFond.nbrEnemyMax[numBackground]==0))
{
lvlUP(&ImageFond,&numBackground,&hero);
vieRectWidth.w = hero.hp;
initMap(&map,&ImageFond,TabEntity[numBackground],&hero,&enemy[numEnemy],fenetre);
}




//collision

int j;
for(j=0;j<TabEntity[numBackground].nbr_entite;j++)
if(collisionHeroEntite(hero,TabEntity[numBackground].entite[j])==1){
VIE_ReduireHp(&hero,2);
vieRectWidth.w = hero.hp;}



if(ImageFond.nbrEnemyMax[numBackground]>0)

if(collisionHeroEnemy(hero,enemy[numEnemy])==1)
  {       

	if((strcmp(hero.state,"punchL")==0)||(strcmp(hero.state,"punchR")==0))
	  enemy[numEnemy].vie-=15;

	else if((strcmp(hero.state,"kickL")==0)||(strcmp(hero.state,"kickR")==0))
	  enemy[numEnemy].vie-=15;
	
	//if(enemy[i].vie<=0)
        //hero.score+=(i+1)*100;	 
 
        else{
	VIE_ReduireHp(&hero,2);
	vieRectWidth.w = hero.hp;
	    }
        

	if(enemy[numEnemy].vie<=0)
	  {
	  VIE_AjouterScore(&hero,100);
	  }

  }

	
//VIE_AjouterScore(&hero,10);}






//if death

if(hero.hp <= 0)
{

	if(hero.death!=1)
	{

	   if(strcmp(hero.state,"idleR")==0)
		strcpy(hero.state,"deathR");


	   if(strcmp(hero.state,"idleL")==0)
		strcpy(hero.state,"deathL");


	}else
	    {
	    continuer= 0;
	    }

	stop=1;
}




SDL_PollEvent(&event);

switch(event.type)
        {


        case SDL_QUIT:
                continuer=0;
            break;



        case SDL_KEYDOWN:



            if(event.key.keysym.sym==SDLK_ESCAPE){continuer=0;} //échap

	  	if(stop!=1){


		    if(event.key.keysym.sym==SDLK_RIGHT)     // Flèche droite
		          {                
			  strcpy(hero.state,"walkR");
		          strcpy(state,"idleR");	     
			  }



		     if(event.key.keysym.sym==SDLK_LEFT) // Flèche gauche
		          {
		          strcpy(hero.state,"walkL");
		          strcpy(state,"idleL");
		          }



		    if(event.key.keysym.sym==SDLK_KP6)  // Flèche droite
		          {              
			  strcpy(hero.state,"runR");
			  strcpy(state,"idleR");		     
			  }



		     if(event.key.keysym.sym==SDLK_KP4) // Flèche gauche
		          {
		          strcpy(hero.state,"runL");
		          strcpy(state,"idleL");
		          }




		    if(event.key.keysym.sym==SDLK_UP) // Flèche haut
		          {
		          strcpy(hero.state,"walkUP");
			  if (strcmp(state,"idleL")==0)
		          strcpy(state,"idleL");
			  if (strcmp(state,"idleR")==0)
		          strcpy(state,"idleR");
		          }



		    if(event.key.keysym.sym==SDLK_DOWN) // Flèche bas
		          {
		          strcpy(hero.state,"walkDOWN");
			  if (strcmp(state,"idleL")==0)
		          strcpy(state,"idleL");
			  if (strcmp(state,"idleR")==0)
		          strcpy(state,"idleR");
		          }



		    if(event.key.keysym.sym==SDLK_w) // key 1 
		          {
		          if(strcmp(hero.state,"idleR")==0){
		             strcpy(hero.state,"kickR");
			     strcpy(state,"idleR");}

			  if(strcmp(hero.state,"idleL")==0){
		             strcpy(hero.state,"kickL");
			     strcpy(state,"idleL");}
		          }



		     if(event.key.keysym.sym==SDLK_q) // key 2 
		          {
		          if(strcmp(hero.state,"idleR")==0){
		             strcpy(hero.state,"punchR");
			     strcpy(state,"idleR");}

			  if(strcmp(hero.state,"idleL")==0){
		             strcpy(hero.state,"punchL");
			     strcpy(state,"idleL");}
		          }

		


            	 break;

	  } 


           default: 
                
		 if(hero.moveState==1){
			hero.moveState=0;
		        strcpy(hero.state,state);}

           break;        
}

//REFRESH SCREEN
if(enemy[numEnemy].vie<=0)
DelateEnemy(enemy,&ImageFond.nbrEnemyMax[numBackground],&numEnemy);


afficher_background(&ImageFond, &hero,fenetre,numBackground);

afficher_entite(TabEntity[numBackground].entite,TabEntity[numBackground].nbr_entite,hero,fenetre);

moveHero(&hero,&ImageFond, numBackground, TabEntity[numBackground].entite, TabEntity[numBackground].nbr_entite, &enemy[numEnemy], fenetre);

if(ImageFond.nbrEnemyMax[numBackground]>0)
moveEnemy(&enemy[numEnemy],fenetre,ImageFond,numBackground,hero);


afficher_map(&map,&ImageFond,TabEntity[numBackground],&hero,&enemy[numEnemy],ImageFond.nbrEnemyMax[numBackground],fenetre);



if(hero.positionHero.y<enemy[numEnemy].position.y)
{ 
animateHero(&hero,fenetre,state);

if(ImageFond.nbrEnemyMax[numBackground]>0)
animateEnemy(&enemy[numEnemy],hero,fenetre);
}
else
{
if(ImageFond.nbrEnemyMax[numBackground]>0)
animateEnemy(&enemy[numEnemy],hero,fenetre);

animateHero(&hero,fenetre,state);
}

if(hero.hp>0)
  if(afficher_temps(&temps,300,fenetre)==1)
  continuer=0;


if(hero.hp>0)
SDL_BlitSurface(hp,&vieRectWidth,fenetre,&vieRect);

VIE_RenderScore(&hero,&fenetre);


if(hero.hp <= 0)
afficherMessage(&msg,"test.ttf",60,255,255,255,400,300,"GAME OVER",fenetre);



SDL_Flip(fenetre);

}



//libirer la memoire
SDL_FreeSurface(temps.chrono);
free_surfaceBackground(&ImageFond);
for(i=0;i<maxBackground;i++)
free_surfaceEntite(TabEntity[i].entite,TabEntity[i].nbr_entite);
SDL_FreeSurface(hero.spriteHero);
SDL_FreeSurface(hero.spriteHero);
for(i=0;i<nbr_enemy;i++)
SDL_FreeSurface(enemy[i].image);
SDL_FreeSurface(map.cadre);
SDL_FreeSurface(map.point);
SDL_FreeSurface(fenetre);
TTF_Quit();
SDL_Quit();


return 0;
}
