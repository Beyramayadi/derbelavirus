void initialiser_entite(ent E[],int n)
{
int i;
char entite[300];
for(i=0;i<n;i++){

E[i].image_entite=NULL;
E[i].spriteleft = NULL;
E[i].spriteright=  NULL;
E[i].death= NULL;


E[i].position_entite.x=0;
E[i].position_entite.y=0;
/*
E[i].position_entite.h=0;
E[i].position_entite.w=0;
*/


E[i].pos_alea_max_x=0;
E[i].pos_alea_min_x=0;

E[i].pos_alea_max_y=0;
E[i].pos_alea_min_y=0;



E[i].sens_mouvement=0;

E[i].vie=0;


}
