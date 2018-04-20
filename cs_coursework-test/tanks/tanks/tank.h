#pragma once
#include "LTexture.h"
#include <cmath>
#include "bulletData.h"

class tank
{
public:
	tank(SDL_Renderer* renderer);

	~tank();

	//Handle any SDL events that affect the tank
	void handleEvents(SDL_Event& e);

	//Perform any movement on the tank
	void processMovement();

	void checkCollision();

	int rotationDirection();

	//process all other actions
	bulletData shooting();

	//Render the tank and the tank turret
	void render(SDL_Renderer* renderer);
private:
	//The x and y coorinates for the tank
	int x;
	int y;

	//The speed the tank can move
	int speed;

	//The current movement direction of the tank
	int direction;

	//The direction the tank will rotate towards
	int inputDirection;

	//Whether the tank should move or not
	bool move;

	//The angle of aiming
	double aimAngle;

	//All the movement inputs
	bool up;
	bool down;
	bool left;
	bool right;

	//The tank texture
	LTexture texture;

	LTexture turret;

	int mx;
	int my;

	bool shoot;

};

