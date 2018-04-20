#include "bullet.h"



bullet::bullet(bulletData newBullet, SDL_Renderer* renderer)
{
	x = newBullet.x;
	y = newBullet.y;
	direction = newBullet.direction;

	bounce = 1;
	speed = 6;
	bulletTexture = new LTexture();
	bulletTexture->loadFromFile("images/bullet.png",renderer);
}


bullet::~bullet()
{
	bulletTexture->free();
}

void bullet::move()
{
	int moveX = round(speed * cos(direction));
	int moveY = round(speed * sin(direction));

	x += moveX;
	y += moveY;
}

void bullet::render(SDL_Renderer* renderer)
{
	bulletTexture->render(x, y, renderer);
}
