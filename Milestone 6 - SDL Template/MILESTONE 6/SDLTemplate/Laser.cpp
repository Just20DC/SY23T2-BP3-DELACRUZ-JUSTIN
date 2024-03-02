#include "Laser.h"


Laser::Laser(float xposition, float yposition, float xdirection, float ydirection, float speed,Side side)
{
	this->x = xposition;
	this->y = yposition;
	this->xdirection = xdirection;
	this->ydirection = ydirection;
	this->speed = speed;
	this->side = side;
}

void Laser::start()
{
	width = 0;
	height = 0;
	if (side == Side::PLAYER_SIDE) {
		texture = loadTexture("gfx/playerBullet.png");
	}
	else {
		texture = loadTexture("gfx/alienBullet.png");
	}
	
	SDL_QueryTexture(texture, NULL, NULL, &width, &height);
}

void Laser::update()
{
	x += xdirection * speed;
	y += ydirection * speed;
}

void Laser::draw()
{
	blit(texture, x, y);
}

float Laser::getXPosition()
{
	return x;
}

float Laser::getYPosition()
{
	return y;
}

float Laser::getWidth()
{
	return width;
}

float Laser::getHeight()
{
	return height;
}

Side Laser::getSide()
{
	return side;
}
