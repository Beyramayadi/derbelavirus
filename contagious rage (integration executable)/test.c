int main(){
	SDL_Surface *screen, *player, *hp;
	SDL_Init(SDL_INIT_EVERYTHING);
	screen = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);

	TTF_Init();

	Vie v;
	VIE_Init(&v);
	
	SDL_Event event;
	int running = 1;

	SDL_Rect r = {50,50};
	SDL_Rect vieRect = {r.x,r.y-20};
	SDL_Rect vieRectWidth = {0,0,100,10};

	hp = SDL_CreateRGBSurface(0,100,10,32,0,0,0,0);
	SDL_FillRect(hp,NULL,0x00ff00);

	player = IMG_Load("0.png");
	while(running){
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				running = 0;
			}
			if(event.type == SDL_KEYDOWN){
				if(event.key.keysym.sym == SDLK_DOWN){
					VIE_ReduireHp(&v,10);
					vieRectWidth.w = v.hp;
				}
				if(event.key.keysym.sym == SDLK_RIGHT){
					r.x += 10;
					vieRect.x = r.x;
				}

				if(event.key.keysym.sym == SDLK_UP){
					VIE_AjouterScore(&v,100);
				}
			}
		}

		if(v.hp <= 0){
			running = 0;
		}

		SDL_FillRect(screen,NULL,0x000000);
		SDL_BlitSurface(player,NULL,screen,&r);
		SDL_BlitSurface(hp,&vieRectWidth,screen,&vieRect);
		VIE_RenderScore(&v,&screen);
		SDL_Flip(screen);
		SDL_Delay(16);
	}
	
	SDL_Quit();
	
}
