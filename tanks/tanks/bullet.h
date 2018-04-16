#pragma once
#include "LTexture.h"
class bullet
{
public:
	bullet();
	~bullet();

	void move();
	void render();

private:
	//The x and y coordinate of the bullet
	int x;
	int y;

	//The direction of movement
	int direction;

	//The amount of times the bullet can bounce
	int bounce;

	//The speed of the bullet
	int speed;

	LTexture texture;
};

