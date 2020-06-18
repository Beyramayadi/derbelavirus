#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"



//**************MINIMAP****************


//INITMAP

void initMap(Map *map, background *ImageFond, Entite ENT, Hero *hero, Enemy *enemy , SDL_Surface *fenetre){

int i;



map->cadre=IMG_Load("CHINAMAPCADREFINALE.png");
map->point=IMG_Load("pointvert.png");
map->pointEnemy=IMG_Load("pointrougenoire1.png");

map->PositionCadre.x=fenetre->w-map->cadre->w;
map->PositionCadre.y=0;

map->PositionPoint.x=20+map->PositionCadre.x+(abs(ImageFond->position.x-hero->positionHero.x-ImageFond->frame.x)/ 6);
map->PositionPoint.y=12+map->PositionCadre.y+(abs(ImageFond->position.y-hero->positionHero.y)/ 6);


map->PositionPointEnemy.x=20+map->PositionCadre.x+(abs(ImageFond->position.x-enemy->position.x)/ 6);
map->PositionPointEnemy.y=12+map->PositionCadre.y+(abs(ImageFond->position.y-enemy->position.y)/ 6);


map->pointEntite=IMG_Load("point rouge1.png");

SDL_Rect PositionPointEntite[ENT.nbr_entite];

for(i=0;i<ENT.nbr_entite;i++)
{
map->PositionPointEntite[i].x=map->PositionCadre.x+(abs(ImageFond->position.x-ENT.entite[i].position_entite.x)/ 6);
map->PositionPointEntite[i].y=-13+map->PositionCadre.y+(abs(ImageFond->position.y-ENT.entite[i].position_entite.y-ENT.entite[i].image_entite->h)/ 6);
}

}



//AFFICHERMAP

void afficher_map(Map *map, background *ImageFond, Entite ENT, Hero *hero, Enemy *enemy,int nbrEnemyMax, SDL_Surface *fenetre){

int i;


map->PositionPoint.x=12+map->PositionCadre.x+(abs(ImageFond->position.x-hero->positionHero.x-ImageFond->frame.x)/ 6);
map->PositionPoint.y=20+map->PositionCadre.y+(abs(ImageFond->position.y-hero->positionHero.y)/ 6);



SDL_BlitSurface(map->cadre, NULL, fenetre, &map->PositionCadre);
SDL_BlitSurface(map->point, NULL, fenetre, &map->PositionPoint);



for(i=0;i<ENT.nbr_entite;i++)
{
SDL_BlitSurface(map->pointEntite, NULL, fenetre, &map->PositionPointEntite[i]);
}


if(nbrEnemyMax>0){
map->PositionPointEnemy.x=12+map->PositionCadre.x+(abs(ImageFond->position.x-enemy->position.x-ImageFond->frame.x)/ 6);
map->PositionPointEnemy.y=20+map->PositionCadre.y+(abs(ImageFond->position.y-enemy->position.y)/ 6);
SDL_BlitSurface(map->pointEnemy, NULL, fenetre, &map->PositionPointEnemy);
}

}





//*********BACKGROUND*****************

//INITBACKGROUND

void initialiser_background(background *ImageFond, SDL_Surface *fenetre){

ImageFond->image[0]=IMG_Load("china1.png");
ImageFond->image[1]=IMG_Load("china2.png");
ImageFond->image[2]=IMG_Load("china3.png");
ImageFond->image[3]=IMG_Load("china4.png");
ImageFond->image[4]=IMG_Load("china5.png");

ImageFond->position.x=0;
ImageFond->position.y=0;
ImageFond->position.w=0;
ImageFond->position.h=0;

ImageFond->frame.w=ImageFond->image[0]->w;
ImageFond->frame.h=ImageFond->image[0]->h;
ImageFond->frame.x=0;
ImageFond->frame.y=0;


ImageFond->zone[0].max=fenetre->h;
ImageFond->zone[0].min=fenetre->h-50;
ImageFond->zone[1].max=fenetre->h;
ImageFond->zone[1].min=fenetre->h-50;
ImageFond->zone[2].max=fenetre->h;
ImageFond->zone[2].min=fenetre->h-50;
ImageFond->zone[3].max=fenetre->h;
ImageFond->zone[3].min=fenetre->h-90;
ImageFond->zone[4].max=fenetre->h;
ImageFond->zone[4].min=fenetre->h-70;


ImageFond->nbrEnemyMax[0]=1;
ImageFond->nbrEnemyMax[1]=2;
ImageFond->nbrEnemyMax[2]=3;
ImageFond->nbrEnemyMax[3]=4;
ImageFond->nbrEnemyMax[4]=5;



}



//AFFICHERBACKGROUND

void afficher_background(background *ImageFond, Hero *hero, SDL_Surface *fenetre, int num_Background){


SDL_BlitSurface(ImageFond->image[num_Background], &ImageFond->frame, fenetre, &ImageFond->position);


}





void free_surfaceBackground(background *ImageFond){

int i;

for(i=0;i<maxBackground;i++){

SDL_FreeSurface(ImageFond->image[i]);
}
}





//***************ENNEMIE********************


//INITENEMY

void initEnemy(Enemy enemy[],int nbr_enemy){


char matrice[nbr_enemy][30];


strcpy(matrice[0],"enemy.png");
strcpy(matrice[1],"enemy.png");
strcpy(matrice[2],"enemy.png");
strcpy(matrice[3],"enemy.png");
strcpy(matrice[4],"enemy.png");
strcpy(matrice[5],"enemy.png");
strcpy(matrice[6],"enemy.png");
strcpy(matrice[7],"enemy.png");
strcpy(matrice[8],"enemy.png");
strcpy(matrice[9],"enemy.png");
strcpy(matrice[10],"enemy.png");
strcpy(matrice[11],"enemy.png");
strcpy(matrice[12],"enemy.png");
strcpy(matrice[13],"enemy.png");
strcpy(matrice[14],"enemy.png");
strcpy(matrice[15],"enemy.png");


int i=0;

for(i=0;i<nbr_enemy;i++){

	enemy[i].frame[maxStatesEnemy][maxFramesEnemy];
int j;


				enemy[i].image=IMG_Load(matrice[i]);
			
			
		//walkR
			for (j=11;j>=0;j--)
			{
				enemy[i].frame[0][j].w=enemy[i].image->w/maxFramesEnemy;
				enemy[i].frame[0][j].h=enemy[i].image->h/maxStatesEnemy;
				enemy[i].frame[0][j].y=0;
				enemy[i].frame[0][11-j].x=j*(enemy[i].image->w/maxFramesEnemy);

			}	

		//walkL
			for (j=0;j<12;j++)
			{
				enemy[i].frame[1][j].w=enemy[i].image->w/maxFramesEnemy;
				enemy[i].frame[1][j].h=enemy[i].image->h/maxStatesEnemy;
				enemy[i].frame[1][j].y=enemy[i].image->h/maxStatesEnemy;
				enemy[i].frame[1][j].x=j*(enemy[i].image->w/maxFramesEnemy);
			}
   

				enemy[i].position.x=2000/*-(300*i)*/;
				enemy[i].position.y=400;
				enemy[i].frameEnemy.x=0;
				enemy[i].frameEnemy.y=0;


        enemy[i].sens_mouvement_horizontal=1; //right to left
        enemy[i].sens_mouvement_vertical=(i%2); //top to bottom
	enemy[i].vie=100+(100*(i/2));

/*	
	enemy[i].frameEnemy.w=enemy[i].image->w;
	enemy[i].frameEnemy.h=enemy[i].image->h;;
	enemy[i].frameEnemy.x=0;
	enemy[i].frameEnemy.y=0;	
*/

 }
}


//ANIMATEENEMY

int animeEnemy=0;
void animateEnemy(Enemy *enemy, Hero hero, SDL_Surface * fenetre)
{

		int j;
                

	    if (enemy->sens_mouvement_horizontal==0)
	    {
	    	j=0;
		    //hero->moveState=1;
	    	(animeEnemy)++;
	    	if ((animeEnemy)==12)
	    		(animeEnemy)=1;
	    }
	    
	    
	     if (enemy->sens_mouvement_horizontal==1)
	    {
	    	j=1;
		    //hero->moveState=1;
	    	(animeEnemy)++;
	    	if ((animeEnemy)==12)
	    		(animeEnemy)=1;
	    }
	    
	   
SDL_BlitSurface(enemy->image, &enemy->frame[j][animeEnemy] , fenetre , &enemy->position);
//SDL_Delay(50);

}





//MOVEENEMY

void moveEnemy(Enemy *enemy, SDL_Surface * fenetre, background ImageFond, int numBackground, Hero hero){




int posxMax=/*ImageFond.frame.x+*/fenetre->w-(enemy->image->w/maxFramesEnemy);
int posxMin=50;
int posyMax=ImageFond.zone[numBackground].min-(enemy->image->h/maxStatesEnemy);
int posyMin=ImageFond.zone[numBackground].max-(enemy->image->h/maxStatesEnemy);



if(enemy->position.y<=posyMax)
enemy->sens_mouvement_vertical=1;

if(enemy->position.y>=posyMin)
enemy->sens_mouvement_vertical=0;


if(enemy->position.x>=posxMax)
enemy->sens_mouvement_horizontal=1;

if(enemy->position.x<=posxMin)
enemy->sens_mouvement_horizontal=0;

if(enemy->sens_mouvement_horizontal==0){
enemy->position.x+=6;
}
else
{
enemy->position.x-=6;
}




if(enemy->sens_mouvement_vertical==0){
enemy->position.y-=2;
}
else
{
enemy->position.y+=2;
}


}





//DELATEENEMY


void DelateEnemy(Enemy enemy[], int *nbrEnemyMax, int *numEnemy){

int i;
int k;


	//(*numEnemy)++;

     if(enemy[*numEnemy].vie<=0)
     //{
	  /* for(k=(*numEnemy);k<(*nbrEnemyMax)-1;k++)
           {
	   //printf("test\n");
	   enemy[*numEnemy]=enemy[(*numEnemy)+1];
	   //printf("%d\n",(*numEnemy));
           }
           (*nbrEnemyMax)--;
	   //(*numEnemy)++;*/
	  /*for(i=0;i<0;i++)
	   enemy[*numEnemy]=enemy[(*numEnemy)+1];*/
	if((*nbrEnemyMax)>0){
	   (*nbrEnemyMax)--;
	   (*numEnemy)++;}
   //  }

}





//***********ENTITES SECONDAIRES***************

//INITENTITE

void initialiser_entite(Entite TabEntity[], background ImageFond){

int i;
int j;
Mot matrice[10][10];


//init entites pour chaque background

//background"1"
TabEntity[0].nbr_entite=2;
strcpy(matrice[0][0].mot,"skeleton4.png");
strcpy(matrice[1][0].mot,"skeleton0.png");
//strcpy(matrice[2][0].mot,"skeleton1.png");
//strcpy(matrice[3][0].mot,"pile.png");
//strcpy(matrice[4][0].mot,"point rouge.png");

//background"2"
TabEntity[1].nbr_entite=3;
strcpy(matrice[0][1].mot,"deadman.png");
strcpy(matrice[1][1].mot,"skeleton2.png");
strcpy(matrice[2][1].mot,"pile.png");
//strcpy(matrice[3][1].mot,"skeleton2.png");
//strcpy(matrice[4][1].mot,"point rouge.png");

//background"3"
TabEntity[2].nbr_entite=4;
strcpy(matrice[0][2].mot,"skeleton3.png");
strcpy(matrice[1][2].mot,"pile.png");
strcpy(matrice[2][2].mot,"skeleton0.png");
strcpy(matrice[3][2].mot,"trashbag.png");
//strcpy(matrice[4][2].mot,"point rouge.png");

//background"4"
TabEntity[3].nbr_entite=5;
strcpy(matrice[0][3].mot,"plant.png");
strcpy(matrice[1][3].mot,"skeleton3.png");
strcpy(matrice[2][3].mot,"pile.png");
strcpy(matrice[3][3].mot,"skeleton1.png");
strcpy(matrice[4][3].mot,"skull.png");

//background"5"
TabEntity[4].nbr_entite=5;
strcpy(matrice[0][4].mot,"plant.png");
strcpy(matrice[1][4].mot,"skeleton1.png");
strcpy(matrice[2][4].mot,"trashbag.png");
strcpy(matrice[3][4].mot,"skeleton4.png");
strcpy(matrice[4][4].mot,"skeleton3.png");
//strcpy(matrice[4][5].mot,"skeleton0.png");


for(j=0;j<maxBackground;j++){

Displacement tab[TabEntity[j].nbr_entite];

for(i=0;i<TabEntity[j].nbr_entite;i++){

TabEntity[j].entite[i].image_entite=IMG_Load(matrice[i][j].mot);
tab[i].max=ImageFond.zone[j].max-TabEntity[j].entite[i].image_entite->h;
tab[i].min=ImageFond.zone[j].min-TabEntity[j].entite[i].image_entite->h;
}


TabEntity[j].entite[0].position_entite.x=(int)(ImageFond.image[j]->w)/(TabEntity[j].nbr_entite+1);
TabEntity[j].entite[0].position_entite.y=(int)(((double)rand()*(double)(tab[0].max-tab[0].min)/(double)RAND_MAX))+tab[0].min;
TabEntity[j].entite[0].frame.w=TabEntity[j].entite[0].image_entite->w;
TabEntity[j].entite[0].frame.h=TabEntity[j].entite[0].image_entite->h;;
TabEntity[j].entite[0].frame.x=0;
TabEntity[j].entite[0].frame.y=0;



for(i=1;i<TabEntity[j].nbr_entite;i++){

TabEntity[j].entite[i].position_entite.x=(int)((ImageFond.image[j]->w)/(TabEntity[j].nbr_entite+1)*(i+1));
TabEntity[j].entite[i].position_entite.y=(int)(((double)rand()*(double)(tab[i].max-tab[i].min)/(double)RAND_MAX))+tab[i].min;

TabEntity[j].entite[i].frame.w=TabEntity[j].entite[i].image_entite->w;
TabEntity[j].entite[i].frame.h=TabEntity[j].entite[i].image_entite->h;
TabEntity[j].entite[i].frame.x=0;
TabEntity[j].entite[i].frame.y=0;

}
}
}

//AFFICHERENTITE

void afficher_entite(ent E[],int n, Hero hero, SDL_Surface * fenetre){

int i;

for(i=0;i<n;i++){
/*
if(E[i].position_entite.x<0){
E[i].frame.x+=hero.speed;
E[i].position_entite.x=0;


if(E[i].position_entite.x+E[i].image_entite->w-hero.speed==0){
E[i].frame.x-=hero.speed;
E[i].position_entite.x=0;
}
}*/

SDL_BlitSurface(E[i].image_entite, &E[i].frame, fenetre, &E[i].position_entite);

}
}




void free_surfaceEntite(ent E[],int n){

int i;

for(i=0;i>n;i++){

SDL_FreeSurface(E[i].image_entite);

}
}









//*********HERO**********


//INITHERO

int walkR=0,walkL=0;

void initHero(Hero *hero)
{

        
	hero->frameHero[maxStatesHero][maxFramesHero];
	int i;

	hero->spriteHero=IMG_Load("spritesheet.png");
        
	
//walkR
	for (i=0;i<9;i++)
	{
		hero->frameHero[0][i].w=hero->spriteHero->w/maxFramesHero;
		hero->frameHero[0][i].h=hero->spriteHero->h/maxStatesHero;
		hero->frameHero[0][i].y=0;
		hero->frameHero[0][i].x=i*(hero->spriteHero->w/maxFramesHero);

	}

//walkL
	for (i=8;i>=0;i--)
	{
		hero->frameHero[1][i].w=hero->spriteHero->w/maxFramesHero;
		hero->frameHero[1][i].h=hero->spriteHero->h/maxStatesHero;
		hero->frameHero[1][i].y=hero->spriteHero->h/maxStatesHero;
		hero->frameHero[1][8-i].x=i*(hero->spriteHero->w/maxFramesHero);
	}

//runL
        for (i=0;i<8;i++)
	{
		hero->frameHero[2][i].w=hero->spriteHero->w/maxFramesHero;
		hero->frameHero[2][i].h=hero->spriteHero->h/maxStatesHero;
		hero->frameHero[2][i].y=2*(hero->spriteHero->h/maxStatesHero);
		hero->frameHero[2][i].x=i*(hero->spriteHero->w/maxFramesHero);
	}

//runR
        for (i=7;i>=0;i--)
	{
		hero->frameHero[3][i].w=hero->spriteHero->w/maxFramesHero;
		hero->frameHero[3][i].h=hero->spriteHero->h/maxStatesHero;
		hero->frameHero[3][i].y=3*(hero->spriteHero->h/maxStatesHero);
		hero->frameHero[3][7-i].x=i*(hero->spriteHero->w/maxFramesHero);
	}

//kickR
        for (i=0;i<13;i++)
	{
		hero->frameHero[4][i].w=hero->spriteHero->w/maxFramesHero;
		hero->frameHero[4][i].h=hero->spriteHero->h/maxStatesHero;
		hero->frameHero[4][i].y=4*(hero->spriteHero->h/maxStatesHero);
		hero->frameHero[4][i].x=i*(hero->spriteHero->w/maxFramesHero);
	}
//kickL
        for (i=maxFramesHero-1;i>=0;i--)
	{
		hero->frameHero[5][i].w=hero->spriteHero->w/maxFramesHero;
		hero->frameHero[5][i].h=hero->spriteHero->h/maxStatesHero;
		hero->frameHero[5][i].y=5*(hero->spriteHero->h/maxStatesHero);
		hero->frameHero[5][12-i].x=i*(hero->spriteHero->w/maxFramesHero);
	}
//punchR
        for (i=0;i<10;i++)
	{
		hero->frameHero[6][i].w=hero->spriteHero->w/maxFramesHero;
		hero->frameHero[6][i].h=hero->spriteHero->h/maxStatesHero;
		hero->frameHero[6][i].y=6*(hero->spriteHero->h/maxStatesHero);
		hero->frameHero[6][i].x=i*(hero->spriteHero->w/maxFramesHero);
	}
//punchL
        for (i=9;i>=0;i--)
	{
		hero->frameHero[7][i].w=hero->spriteHero->w/maxFramesHero;
		hero->frameHero[7][i].h=hero->spriteHero->h/maxStatesHero;
		hero->frameHero[7][i].y=7*(hero->spriteHero->h/maxStatesHero);
		hero->frameHero[7][9-i].x=i*(hero->spriteHero->w/maxFramesHero);
	}


//deathR
        for (i=0;i<13;i++)
	{
		hero->frameHero[8][i].w=hero->spriteHero->w/maxFramesHero;
		hero->frameHero[8][i].h=hero->spriteHero->h/maxStatesHero;
		hero->frameHero[8][i].y=8*(hero->spriteHero->h/maxStatesHero);
		hero->frameHero[8][i].x=i*(hero->spriteHero->w/maxFramesHero);
	}
//deathL
        for (i=12;i>=0;i--)
	{
		hero->frameHero[9][i].w=hero->spriteHero->w/maxFramesHero;
		hero->frameHero[9][i].h=hero->spriteHero->h/maxStatesHero;
		hero->frameHero[9][i].y=9*(hero->spriteHero->h/maxStatesHero);
		hero->frameHero[9][12-i].x=i*(hero->spriteHero->w/maxFramesHero);
	}



//position initiale

         hero->positionHero.x=50;
         hero->positionHero.y=410;

//direction initiatile

         strcpy(hero->state,"idleR");

//vitesse
 
	 hero->speed=12;

//move state init
         hero->moveState=0;

//death init
	 hero->death=0;


	hero->hp = 100;
	hero->r.w = 100;
	hero->r.h = 10;

	hero->bar = SDL_CreateRGBSurface(0,100,10,32,0,0,0,0);
	SDL_FillRect(hero->bar, NULL, 0x00ff00);

	hero->font = TTF_OpenFont("Superstar M54.ttf",32);
	hero->score = 0;


}




//ANIMATEHERO



int animeHero=0;
int moveSpeed=0;
void animateHero(Hero *hero,SDL_Surface * fenetre, char state[])
{
		int j;
                


	    if (strcmp(hero->state,"walkR")==0)
	    {
                moveSpeed=50;
	    	j=0;
		hero->moveState=1;
	    	(animeHero)++;
	    	if ((animeHero)==9)
	    		(animeHero)=1;
	    }
	     if (strcmp(hero->state,"walkL")==0)
	    {
                moveSpeed=50;
	    	j=1;
		hero->moveState=1;
	    	(animeHero)++;
	    	if ((animeHero)==9)
	    		(animeHero)=1;
	    }



	    if (strcmp(hero->state,"runR")==0)
	    {
                moveSpeed=50;
	    	j=2;
		hero->moveState=1;
	    	(animeHero)++;
	    	if ((animeHero)==8)
	    		(animeHero)=0;
	    }
	     if (strcmp(hero->state,"runL")==0)
	    {
                moveSpeed=50;
	    	j=3;
		hero->moveState=1;
	    	(animeHero)++;
	    	if ((animeHero)==8)
	    		(animeHero)=0;
	    }




             if (strcmp(hero->state,"walkUP")==0)
	    {
		if(strcmp(state,"idleR")==0)
	    	{j=0;}else{j=1;}
                moveSpeed=100;
		hero->moveState=1;
	    	(animeHero)++;
	    	if ((animeHero)==9)
	    		(animeHero)=0;
	    }
	     if (strcmp(hero->state,"walkDOWN")==0)
	    {
		if(strcmp(state,"idleR")==0)
	    	{j=0;}else{j=1;}
                moveSpeed=100;
		hero->moveState=1;
	    	(animeHero)++;
	    	if ((animeHero)==9)
	    		(animeHero)=0;
	    }




            if (strcmp(hero->state,"kickR")==0)
	    {
	        moveSpeed=70;
	    	j=4;
	    	(animeHero)++;
	    	if ((animeHero)==12){
	    		(animeHero)=0;
			hero->moveState=1;}
	    }




	    if (strcmp(hero->state,"kickL")==0)
	    {
	        moveSpeed=70;
	    	j=5;
	    	(animeHero)++;
	    	if ((animeHero)==12){
	    		(animeHero)=0;
			hero->moveState=1;}
	    }




            if (strcmp(hero->state,"punchR")==0)
	    {
	        moveSpeed=70;
	    	j=6;
	    	(animeHero)++;
	    	if ((animeHero)==10){
	    		(animeHero)=0;
		        hero->moveState=1;}
	    }




	    if (strcmp(hero->state,"punchL")==0)
	    {
	        moveSpeed=70;
	    	j=7;
	    	(animeHero)++;
	    	if ((animeHero)==10){
	    		(animeHero)=0;
			hero->moveState=1;}
	    }


            
//death

            if (strcmp(hero->state,"deathR")==0)
	    {
	        moveSpeed=250;
		//hero->moveState=1;
	    	j=8;
	    	(animeHero)++;
	    	if ((animeHero)==13){
	    		(animeHero)=5;
			//hero->moveState=1;
                         hero->death=1;}
	    }


              

	    if (strcmp(hero->state,"deathL")==0)
	    {
	        moveSpeed=250;
		//hero->moveState=1;
	    	j=9;
	    	(animeHero)++;
	    	if ((animeHero)==13){
	    		(animeHero)=5;
			//hero->moveState=1;
                         hero->death=1;}
	    }



             
	     if (strcmp(hero->state,"idleR")==0)
	    {
	    	j=0;
	    	animeHero=0;
	      moveSpeed=100;
	    }
	     if (strcmp(hero->state,"idleL")==0)
	    {
	    	j=1;
	    	animeHero=0;
	    	moveSpeed=100;
	    }


		
/*          
            if (strcmp(hero->state,"idleUP")==0)
	    {
	    	j=0;
	    	animeHero=0;
	    }
	     if (strcmp(hero->state,"idleDOWN")==0)
	    {
	    	j=1;
	    	animeHero=0;
	    }
*/




SDL_BlitSurface(hero->spriteHero , &hero->frameHero[j][animeHero] , fenetre , &hero->positionHero);
SDL_Delay(50);

}




//MOVEHERO



void moveHero(Hero *hero, background *ImageFond, int numBackground, ent E[], int n, Enemy *enemy, SDL_Surface *fenetre){

int i;
int j;
int k;


//Init de speed

if((strcmp(hero->state,"walkR")==0)||(strcmp(hero->state,"walkL")==0))
hero->speed=10;
if((strcmp(hero->state,"runR")==0)||(strcmp(hero->state,"runL")==0))
hero->speed=20;

//walk OR run RIGHT

if((strcmp(hero->state,"walkR")==0)||(strcmp(hero->state,"runR")==0))
{

	if(hero->positionHero.x<=(fenetre->w*0.6))
	{
	hero->positionHero.x+=hero->speed;			
	}

	else
	{

	    if(ImageFond->frame.x<ImageFond->image[numBackground]->w-fenetre->w)
  	      {    

			  //if(enemy->position.x>0)
			   //{
				ImageFond->frame.x+=hero->speed;
				enemy->position.x-=hero->speed;
			        for(i=0;i<n;i++){E[i].position_entite.x-=hero->speed;
						if(E[i].position_entite.x<0){
						   E[i].frame.x+=hero->speed;
						   E[i].position_entite.x=0;}}
			   //}

	     }
             else if(hero->positionHero.x<fenetre->w-(hero->spriteHero->w/maxFramesHero))
                hero->positionHero.x+=hero->speed;
        }
}
		




if((strcmp(hero->state,"walkL")==0)||(strcmp(hero->state,"runL")==0))
{

	if(hero->positionHero.x>(fenetre->w*0.3))
	{
	hero->positionHero.x-=hero->speed;			
	}

	else
	{

	    if(ImageFond->frame.x>0)
  	      {    
	       //for(j=0;j<n1;j++) 
	         //{
			//  if(*enemy[j].position.x>0)
			  // {
				ImageFond->frame.x-=hero->speed;
				enemy->position.x+=hero->speed;
			        for(i=0;i<n;i++){E[i].position_entite.x+=hero->speed;
						if((E[i].position_entite.x>0)&&(E[i].frame.x)!=0){
						E[i].position_entite.x-=hero->speed;
						E[i].frame.x-=hero->speed;}
			     }
		// }									
	     }
             else if(hero->positionHero.x>=0)
                hero->positionHero.x-=hero->speed;
        }
}




if(hero->positionHero.y>ImageFond->zone[numBackground].min-(hero->spriteHero->h/maxStatesHero))
{
	 hero->speed=12;
	 if(strcmp(hero->state,"walkUP")==0)
	   hero->positionHero.y-=hero->speed;
}



if(hero->positionHero.y<ImageFond->zone[numBackground].max-(hero->spriteHero->h/maxStatesHero))
{
  	 hero->speed=12;
	 if(strcmp(hero->state,"walkDOWN")==0)
	   hero->positionHero.y+=hero->speed;
}



}












//**************GESTION DU TEMPS***************



//INITTEMPS

void initTemps(Temps * temps, SDL_Surface *fenetre){


temps->font0=TTF_OpenFont("digital-7.ttf",30);
temps->font1=TTF_OpenFont("test.ttf",20);

//color chrono
temps->colorChrono.r=255;
temps->colorChrono.g=255;
temps->colorChrono.b=255;

//color msg
temps->colorMsg.r=255;
temps->colorMsg.g=255;
temps->colorMsg.b=255;


temps->msg=NULL;
temps->PositionMsg.x=fenetre->w-(fenetre->w/3)-50;
temps->PositionMsg.y=0;

temps->chrono=NULL;
temps->PositionChrono.x=fenetre->w-(fenetre->w/3)-50;
temps->PositionChrono.y=30;

}





//AFFICHERTEMPS


int afficher_temps(Temps *temps, int duree_en_seconde, SDL_Surface *fenetre){

int duree=0;

char timeText[20];
sprintf(timeText,"%d%c%d",(duree_en_seconde-1-(SDL_GetTicks()/1000))/60,':',(duree_en_seconde-1-(SDL_GetTicks()/1000))%60);
temps->chrono=TTF_RenderText_Blended(temps->font0,timeText,temps->colorChrono);
temps->msg=TTF_RenderText_Blended(temps->font1,"time left:",temps->colorMsg);

duree=SDL_GetTicks()/1000;

if(duree<duree_en_seconde){

 SDL_BlitSurface(temps->chrono, NULL, fenetre, &temps->PositionChrono);
 SDL_BlitSurface(temps->msg, NULL, fenetre, &temps->PositionMsg);

return 0;
}

return 1; 

}







//collisionHeroEntite


int collisionHeroEntite(Hero hero, ent entite){

	int leftSidehero = hero.positionHero.x;
	int rightSidehero = hero.positionHero.x + hero.spriteHero->w/maxFramesHero;
	int tophero = hero.positionHero.y+160;
	int bottomhero= hero.positionHero.y + hero.spriteHero->h/maxStatesHero;

	int leftSideEntite = entite.position_entite.x;
	int rightSideEntite = entite.position_entite.x + entite.position_entite.w;
	int topEntite = entite.position_entite.y;
	int bottomEntite = entite.position_entite.y + entite.position_entite.h;

	if((bottomhero-10 <= topEntite )||(tophero+10 >= bottomEntite )||(rightSidehero-80 <= leftSideEntite)||(leftSidehero+80 >= rightSideEntite))
		return 0;
	else
		return 1;
}






//collisionHeroEnemy

int collisionHeroEnemy(Hero hero, Enemy enemy){


			int leftSidehero = hero.positionHero.x;
			int rightSidehero = hero.positionHero.x + hero.spriteHero->w/maxFramesHero;
			int tophero = hero.positionHero.y+160;
			int bottomhero= hero.positionHero.y + hero.spriteHero->h/maxStatesHero;

			int leftSideEnemy = enemy.position.x;
			int rightSideEnemy = enemy.position.x + enemy.image->w/maxFramesEnemy;
			int topEnemy = enemy.position.y+160;
			int bottomEnemy = enemy.position.y + enemy.image->h/maxStatesEnemy;

			if((bottomhero-10 <= topEnemy+10 )||(tophero+10 >= bottomEnemy-10 )||(rightSidehero-80 <= leftSideEnemy+80)||(leftSidehero+80 >= rightSideEnemy-80))
				return 0;
			else
				return 1;
		}
		








//vie et score


void VIE_ReduireHp(Hero *hero, int degat){
	hero->hp -= degat;
}

void VIE_AjouterScore(Hero *hero, int score){
	hero->score += score;
}


void VIE_RenderScore(Hero *hero, SDL_Surface **screen){
	SDL_Color color = {255,255,255};
	sprintf(hero->scoreText,"%d",hero->score);
	hero->msg = TTF_RenderText_Solid(hero->font,hero->scoreText,color);
	SDL_BlitSurface(hero->msg,NULL,*screen,NULL);
}


//AFFICHERMESSAGE
                      

void afficherMessage(Message *msg, char Font[],int taille, int R, int B, int G, int posx, int posy, char message[], SDL_Surface *fenetre){


msg->font=TTF_OpenFont(Font,taille);

//color msg
msg->colorMsg.r=R;
msg->colorMsg.g=B;
msg ->colorMsg.b=G;

//position msg

msg->PositionMsg.x=posx;
msg->PositionMsg.y=posy;


msg->msgSurface=TTF_RenderText_Blended(msg->font,message,msg->colorMsg);
SDL_BlitSurface(msg->msgSurface, NULL, fenetre, &msg->PositionMsg);

}



void lvlUP(background *ImageFond, int *numBackground, Hero *hero)
{

        hero->positionHero.x=50;
        hero->positionHero.y=410;

	hero->hp = 100;
	hero->r.w = 100;
	hero->r.h = 10;

	hero->bar = SDL_CreateRGBSurface(0,100,10,32,0,0,0,0);

	
	(*numBackground)++;

	ImageFond->frame.x=0;

}






