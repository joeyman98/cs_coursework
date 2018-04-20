#pragma once
#include "LTexture.h"
class wall
{
public:
	wall(int x, int y, int width, int height);
	~wall();

	void render();

private:
	//The x and y coordinates of the object
	int x;
	int y;

	//The width and height of the object
	int width;
	int height;

	SDL_Rect texture;
};