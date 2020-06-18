  
prog:main.o screenshare.o
		gcc main.o screenshare.o -o prog -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
main.o:main.c
		gcc -c main.c -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
screenshare.o:screenshare.c
		gcc -c screenshare.c -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
