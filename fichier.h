typedef struct
{

SDL_Rect position_entite;


SDL_Surface * image_entite;
SDL_Surface * spriteleft;
SDL_Surface * spriteright;
SDL_Surface * death;



int pos_alea_max_x;
int pos_alea_min_x;

int pos_alea_max_y;
int pos_alea_min_y;

int sens_mouvement;

int vie;


}ent;



void initialiser_entite(ent E[],int n);
