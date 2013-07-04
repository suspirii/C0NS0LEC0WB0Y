#include "SDL/SDL.h"
#include "control.h"
#include "object.h"
#include "game.h"
#include "video.h"

char running = 1;

int main(int argc,char *argv[]) {
	SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTTHREAD);

	loadVideo("resource/test.png","resource/tile.png");
	loadLevel(gmLvl);
	
	while(running) {		
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 170,0,170));	

		getInput();
		updateGame();
		drawGame();

		SDL_Flip(screen);
		SDL_Delay(25);
	}

	exitVideo();
	SDL_Quit();
	
	return 0;
}
