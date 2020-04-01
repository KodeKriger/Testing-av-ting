#pragma once
#include "SDL.h"
#include <stdio.h>
class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int x, int y, int width, int height, bool fullscreen);
	void eventHandler();
	void update();
	bool running() { return isRunning; };
	void render();
	void clean();

	static SDL_Renderer* renderer;
	static SDL_Event event;
private:
	int cnt = 0;
	bool isRunning;
	SDL_Window* window;
};
