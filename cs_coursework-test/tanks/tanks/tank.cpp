#pragma once
#include "tank.h"
#include "degradconvert.h"
#include <cmath>
#include <iostream>


tank::tank(SDL_Renderer* renderer)
{
	//The x and y coorinates for the tank
	x = 0;
	y = 0;

	//The speed the tank can move
	speed = 5;

	//Whether the tank should move or not
	move = false;

	//The angle of aiming
	aimAngle = 0;

	//All the movement inputs
	up = false;
	down = false;
	left = false;
	right = false;

	//The tank texture
	texture.loadFromFile("images/tank.png", renderer);
	turret.loadFromFile("images/turret.png", renderer);

	mx = 0;
	my = 0;

	shoot = false;
}


tank::~tank()
{

}


void tank::handleEvents(SDL_Event& e)
{
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_w: up = true; break;
		case SDLK_s: down = true; break;
		case SDLK_a: left = true; break;
		case SDLK_d: right = true; break;
		}
		move = true;
	}
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_w: up = false; break;
		case SDLK_s: down = false; break;
		case SDLK_a: left = false; break;
		case SDLK_d: right = false; break;
		}
	}
	if (e.type == SDL_MOUSEMOTION) 
	{
		mx = e.motion.x;
		my = e.motion.y;
	}
	if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && e.key.repeat == 0)
	{
		shoot = true;
	}
	if (e.type == SDL_QUIT)
	{
		texture.free();
	}
}

int tank::rotationDirection()
{
	int dir = 0;
	if (inputDirection > direction)
	{

		if (fabs(direction - inputDirection) > 180)
		{
			dir = -1;
		}
		else
		{
			dir = 1;
		}
	}
	else if (inputDirection < direction)
	{
		int i = 0;
		if (fabs(direction - inputDirection) > 180)
		{
			dir = 1;
		}
		else
		{
			dir = -1;
		}
	}
	return dir;
}

void tank::processMovement()
{
	//Calculate the amount of directional inputs
	int inputCount = up + down + left + right;
	inputDirection = (down * 90) + (left * 180) + (up * 270);

	int xsp = 0;
	int ysp = 0;

	//Calculate the overall direction of the inputs used
	if (right)
	{
		if (inputDirection > 180)
		{
			inputDirection += 360;
		}
	}
	if (inputCount > 0)
	{
		//Calcuate the overall direction
		inputDirection = inputDirection / inputCount;
		if (direction >= 360) { direction -= 360; }
		if (direction < 0) { direction += 360; }

		//Rotate the tank to the direction of the inputs
		int i = 0;
		while (i < 5 && inputDirection != direction)
		{
			direction += rotationDirection();
			i += 1;
		}

		xsp = round(speed * cos(degtorad(direction)));
		ysp = round(speed * sin(degtorad(direction)));

		x += xsp;
		y += ysp;
	}
	aimAngle = atan2(my-(y + 16), mx-(x + 16));
}

bulletData tank::shooting()
{
	bulletData newBullet;
	if (shoot)
	{
		newBullet.x = x + 12;
		newBullet.y = y + 12;
		newBullet.direction = aimAngle;
		newBullet.shoot = true;
	}
	else 
	{
		newBullet.shoot = false;
	}
	shoot = false;
	return newBullet;
}

void tank::render(SDL_Renderer* renderer)
{
	texture.render(x, y, renderer, NULL, direction);
	turret.render(x+5, y+12, renderer, NULL, radtodeg(aimAngle));
}