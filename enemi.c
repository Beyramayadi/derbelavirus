#include "enemi.h"
void initialiser_entite(ent E[],int n){
int i;
char matrice[10][10];
strcpy(matrice[0][0],"1.png");
strcpy(matrice[1][0],"2.png");
strcpy(matrice[2][0],"3.png");
strcpy(matrice[3][0],"4.png");
strcpy(matrice[4][0],"5.png");
E[0]->position_entite.x=150;
E[0]->position_entite.y=200;
E[0]->image_entite=Load_img("1.png");
E[0]->sens_mouvement=0;
for(i=1;i<n+1;i++){
E[i]->position_entite.x=E[i-1].position_entite.x+150;
E[i]->position_entite.y=200;
E[i]->position_entite;
E[i]->image_entite=Load_img(matrice[i]);
E[i]->sens_mouvement=0;
}

void deplacementenemi(SDL_Event event,ent *E)
{	
	
	switch(event.type)
	{
		
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_UP:
                     E[0]->position_entite.y--;
                        break;
                    case SDLK_DOWN:
                E[0]->position_entite.y++;
                        break;
                    case SDLK_RIGHT:
                E[0]->position_entite..x++;
                        break;
                    case SDLK_LEFT:
                   E[0]->position_entite..x--;
                        break;
                }
                break;

	
}

void afficherentite(ent *E,SDL_Surface *ecran)
{
SDL_BlitSurface(E[i]->image_entite[entite->position_actuel],NULL,ecran,&(E[i]->position_entite));
SDL_Delay(20);
}
