#pragma once
#include "Game.h"

class Map
{
public:
	Map();
	~Map();

	void LoadMap(int arr[31][26]);
	void DrawMap();
private:

	SDL_Rect src, dest;

	SDL_Texture* corner1;
	SDL_Texture* corner2;
	SDL_Texture* corner3;
	SDL_Texture* corner4;
	SDL_Texture* wallHor;
	SDL_Texture* wallVer;
	SDL_Texture* blank;

	int map[31][26];

};
