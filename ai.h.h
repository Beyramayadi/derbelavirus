#ifndef _ENTITE_H
#define _ENTITE_H


typedef struct ennemie
{


int direction;
SDL_Rect pos;
SDL_Surface *tab[4],*tab2[2];
int etat;
int etat2,etat3;
int p1,p2;


}ennemie;

ennemie initialiser_ennemie(ennemie e);
ennemie deplacer_ennemie( ennemie e ,SDL_Surface *ecran, SDL_Rect pos,SDL_Rect positionperso);
void freesurfaceennemi(ennemie *e);





#endif
