#include "Laser.h"

Laser::Laser(float xposition, float yposition, float xdirection, float ydirection, float speed)
{
	this->x = xposition;
	this->y = yposition;
	this->xdirection = xdirection;
	this->ydirection = ydirection;
	this->speed = speed;
}

void Laser::start()
{
	width = 0;
	height = 0;
	texture = loadTexture("gfx/playerBullet.png");

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
