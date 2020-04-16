typedef struct { ENTITE_SECONDAIRE

 SDL_Surface* normal[5];
 SDL_Surface* deces[5];
 SDL_Rect position;
 int vie;

}ent_sec;


void initialiser_ennemi(ent_sec *ennemi);
