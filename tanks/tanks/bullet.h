#pragma once
#include "LTexture.h"
#include "bulletData.h"
class bullet
{
public:
	bullet(bulletData newBullet, SDL_Renderer* renderer);
	~bullet();

	void move();
	void render(SDL_Renderer* renderer);

private:
	//The x and y coordinate of the bullet
	int x;
	int y;

	//The direction of movement
	double direction;

	//The amount of times the bullet can bounce
	int bounce;

	//The speed of the bullet
	int speed;

	LTexture* bulletTexture;
};

