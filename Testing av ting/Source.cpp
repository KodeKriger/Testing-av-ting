#include "SDL.h"
#include "Game.h"
#include <SDL_render.h>

Game *game = nullptr;
int main(int argc, char* argv[]) {

	//Variabler for å cappe fps til 60
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;
	//Gameloop
	game = new Game();
	game->init("Pacman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 832, 960, false);
	while (game->running())
	{

		frameStart = SDL_GetTicks();
		game->eventHandler();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
	//Cleaner for når gameloop slutter
	game->clean();
	return 0;
}