  
prog:mainshare.o screenshare.o
		gcc mainshare.o screenshare.o -o prog -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
mainshare.o:mainshare.c
		gcc -c mainshare.c -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
screenshare.o:screenshare.c
		gcc -c screenshare.c -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
