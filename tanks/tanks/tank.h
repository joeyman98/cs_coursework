#pragma once
#include "LTexture.h"
#include <math.h>
class tank
{
public:
	tank();

	~tank();

	//Handle any SDL events that affect the tank
	void handleEvents(SDL_Event& e);

	//Perform any movement on the tank
	void move();

	//process all other actions
	void shooting();

	//Render the tank and the tank turret
	void render();
private:
	//The x and y coorinates for the tank
	int x;
	int y;

	//The speed the tank can move
	int speed;

	//The current movement direction of the tank
	int direction;

	//The angle of aiming
	int aimAngle;

	//The tank texture
	LTexture texture;

};

