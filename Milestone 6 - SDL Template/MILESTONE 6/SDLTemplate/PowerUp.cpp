#include "PowerUp.h"
#include "Scene.h"

PowerUp::PowerUp()
{
}

PowerUp::~PowerUp()
{
}

void PowerUp::start()
{
	texture = loadTexture("gfx/points.png");

	xdirection = -1;
	ydirection = 1;
	width = 0;
	height = 0;
	speed = 2;
	Pathchangetime = (rand() % 300) + 180;

	SDL_QueryTexture(texture, NULL, NULL, &width, &height);

	sound = SoundManager::loadSound("sound/342749__rhodesmas__notification-01.ogg");



}

void PowerUp::update()
{
	x += xdirection * speed;
	y += ydirection * speed;

	if (CurrentPathtime > 0) {
		CurrentPathtime--;
	}
	if (CurrentPathtime == 0) {
		ydirection = -ydirection;
		CurrentPathtime = Pathchangetime;
	}
}

void PowerUp::draw()
{
	blit(texture, x, y);
}

void PowerUp::setPosition(int xPos, int yPos)
{
	this->x = xPos;
	this->y = yPos;
}

int PowerUp::getXposition()
{
	return x;
}

int PowerUp::getYposition()
{
	return y;
}

int PowerUp::getheight()
{
	return height;
}

int PowerUp::getwidth()
{
	return width;
}


