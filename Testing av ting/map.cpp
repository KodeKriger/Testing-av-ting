#include "map.h"
#include "TextureManager.h"

int PacmanMap[31][26]
{
	{1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,4}
};

Map::Map()
{
	
	corner1 = TextureManager::LoadTexture("assets/BottomRightCorner.png");
	corner2 = TextureManager::LoadTexture("assets/BottomLeftCorner.png");
	corner3 = TextureManager::LoadTexture("assets/TopRightCorner.png");
	corner4 = TextureManager::LoadTexture("assets/TopLeftCorner.png");
	wallHor = TextureManager::LoadTexture("assets/HorizontalWall.png");
	wallVer = TextureManager::LoadTexture("assets/VerticalWall.png");
	blank = TextureManager::LoadTexture("assets/Floor.png");

	LoadMap(PacmanMap);
	src.x = 0;
	src.y = 0;
	src.w = dest.w = 32;
	src.h = dest.h = 32;

	dest.x = dest.y = 0;
}

void Map::LoadMap(int arr[31][26])
{
	for (int rad = 0; rad < 30; rad++)
	{
		for (int kolonne = 0; kolonne < 26; kolonne++) {
			map[rad][kolonne] = arr[rad][kolonne];
		}
	}
}
void Map::DrawMap()
{
	int type = 0;
	for (int rad = 0; rad < 30; rad++)
	{
		for (int kolonne = 0; kolonne < 26; kolonne++) {
			type = map[rad][kolonne];
			dest.x = kolonne * 32;
			dest.y = rad * 32;

			switch (type)
			{
			case 0:
				TextureManager::Draw(blank, src, dest);
				break;
			case 1:
				TextureManager::Draw(corner1, src, dest);
				break;
			case 2:
				TextureManager::Draw(corner2, src, dest);
				break;
			case 3: 
				TextureManager::Draw(corner3, src, dest);
				break;
			case 4:
				TextureManager::Draw(corner4, src, dest);
				break;
			case 5:
				TextureManager::Draw(wallHor, src, dest);
				break;
			case 6:
				TextureManager::Draw(wallVer, src, dest);


			default:
				break;
			}
		}
	}
}