void initialiser_ennemi(ent_sec *ennemi){

ennemi->vie=100;

ennemi->normal[0]= IMG_Load("");
ennemi->normal[1]= IMG_Load("");
ennemi->normal[2]= IMG_Load("");
ennemi->normal[3]= IMG_Load("");
ennemi->normal[4]= IMG_Load("");


ennemi->deces[0]= IMG_Load("");
ennemi->deces[1]= IMG_Load("");
ennemi->deces[2]= IMG_Load("");
ennemi->deces[3]= IMG_Load("");
ennemi->deces[4]= IMG_Load("");


ennemi->position.x = 0;
ennemi->position.y = 800;
ennemi->position.w = ennemi->normal[0]->w;
ennemi->position.h = ennemi->normal[0]->h;


}
