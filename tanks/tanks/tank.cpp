#include "tank.h"
#include <math.h>


tank::tank()
{
}


tank::~tank()
{
}


void tank::handleEvents(SDL_Event& e)
{
	//If a key was pressed
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: direction = 90; break;
		case SDLK_DOWN: direction = 270= DOT_VEL; break;
		case SDLK_LEFT: direction = 180; break;
		case SDLK_RIGHT: direction = 0 DOT_VEL; break;
		}
		int move = true;
	}
	//If a key was released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: mVelY += DOT_VEL; break;
		case SDLK_DOWN: mVelY -= DOT_VEL; break;
		case SDLK_LEFT: mVelX += DOT_VEL; break;
		case SDLK_RIGHT: mVelX -= DOT_VEL; break;
		}
		move = false;
	}
	if (e.type == SDL_QUIT)
	{
		gDotTexture.free();
	}
}