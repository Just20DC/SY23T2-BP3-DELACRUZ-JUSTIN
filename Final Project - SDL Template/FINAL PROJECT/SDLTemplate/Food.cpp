#include "Food.h"


Food::Food()
{

}





void Food::start()
{
	texture = loadTexture("gfx/apple_red.png");
	x = 0;
	y = 0;
	width = 0;
	height = 0;

	

	sfx = SoundManager::loadSound("sound/apple_bite.ogg");

}

void Food::Changecoordinates(int xPos, int yPos)
{
	this->x = xPos;
	this->y = yPos;
}


void Food::update()
{
	Changecoordinates(rand() % 300 + 300, rand() % 400 + 300);
}

void Food::draw()
{
	blit(texture, x, y);
}

int Food::getterX()
{
	return x;
}

int Food::getterY()
{
	return y;
}

int Food::getwidth()
{
	return width;
}

int Food::getheight()
{
	return height;
}


