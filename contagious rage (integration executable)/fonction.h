#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#define maxFramesHero  13
#define maxStatesHero  10
#define maxFramesEnemy  12
#define maxStatesEnemy  2
#define maxChar 10
#define maxBackground 5
//#define maxEnemy 5


typedef struct 
{
	SDL_Surface *spriteHero;
	SDL_Rect frameHero[maxStatesHero][maxFramesHero];
        SDL_Rect positionHero;
	char state[maxChar];
        int speed;
	int moveState;
	int death; //(0 ou 1)

	//vie et score
	int hp;
	int score;
	SDL_Surface *bar, *msg;
	TTF_Font *font;
	SDL_Rect r;
	char scoreText[10];

}Hero;



typedef struct ENTITE_SECONDAIRE
{

SDL_Rect position_entite;
SDL_Surface * image_entite;
SDL_Rect frame;


}ent;


//background


typedef struct
{

int max;
int min;

}Displacement;



typedef struct BACKGROUND
{

SDL_Rect position;
SDL_Surface * image[maxBackground];
SDL_Rect frame;
Displacement zone[maxBackground];
int nbrEnemyMax[maxBackground];

}background;






typedef struct TEMPS
{

TTF_Font *font0,*font1;
SDL_Color colorChrono,colorMsg;
SDL_Surface *chrono,*msg;
SDL_Rect PositionChrono,PositionMsg;

}Temps;







typedef struct MINIMAP
{

SDL_Surface *cadre;
SDL_Surface *point;
SDL_Surface *pointEntite;
SDL_Surface *pointEnemy;
SDL_Rect PositionCadre;
SDL_Rect PositionPoint;
SDL_Rect PositionPointEntite[100];
SDL_Rect PositionPointEnemy;


}Map;




typedef struct Message
{

TTF_Font *font;
SDL_Color colorMsg;
SDL_Surface *msgSurface;
SDL_Rect PositionMsg;

}Message;








typedef struct ENNEMIE
{

SDL_Rect position;
SDL_Rect frame[maxStatesEnemy][maxFramesEnemy];
SDL_Surface * image;
int sens_mouvement_vertical;
int sens_mouvement_horizontal;
SDL_Rect frameEnemy;
int vie;

}Enemy;





typedef struct
{

ent entite[20];
int nbr_entite;

}Entite;

typedef struct
{
char mot[50];
}Mot;



void free_surfaceBackground(background *ImageFond);
void initialiser_background(background *ImageFond, SDL_Surface *fenetre);
void afficher_background(background *ImageFond, Hero *hero, SDL_Surface *fenetre, int num_Background);
void free_surfaceEntite(ent E[],int n);
void initialiser_entite(Entite TabEntity[], background ImageFond);
void afficher_entite(ent E[],int n, Hero hero, SDL_Surface * fenetre);
void moveHero(Hero *hero, background *ImageFond, int numBackground, ent E[], int n, Enemy *enemy, SDL_Surface *fenetre);
void initHero(Hero *hero);
void animateHero(Hero *hero,SDL_Surface * fenetre ,char state[]);
//GESTION DE TEMPS;
int afficher_temps(Temps *temps, int duree_en_seconde,SDL_Surface *fenetre);
void initTemps(Temps * temps,SDL_Surface *fenetre);
//MINI MAP
void initMap(Map *map, background *ImageFond, Entite ENT, Hero *hero, Enemy *enemy , SDL_Surface *fenetre);
void afficher_map(Map *map, background *ImageFond, Entite entite, Hero *hero, Enemy *enemy,int nbrEnemyMax, SDL_Surface *fenetre);
//collision
int collisionHeroEntite(Hero hero, ent entite);
int collisionHeroEnemy(Hero hero, Enemy enemy);
//afficher message
void afficherMessage(Message *msg, char Font[],int taille, int R, int B, int G, int posx, int posy, char message[], SDL_Surface *fenetre);
//VIE ET SCORE

void VIE_Init(Hero *hero);
void VIE_ReduireHp(Hero *hero, int degat);
void VIE_AjouterHp(Hero *hero, int degat);
void VIE_AjouterScore(Hero *hero, int score);
void VIE_RenderScore(Hero *hero, SDL_Surface **screen);


//ENNEMIE
void initEnemy(Enemy enemy[], int nbr_enemy);
void animateEnemy(Enemy *enemy, Hero hero, SDL_Surface * fenetre);
void moveEnemy(Enemy *enemy, SDL_Surface * fenetre, background ImageFond, int numBackground, Hero hero);
void DelateEnemy(Enemy enemy[], int *nbrEnemyMax, int *numEnemy);


//gestion des niveau
void lvlUP(background *ImageFond, int *numBackground, Hero *hero);



#endif
