#pragma once
#include "GameObject.h"
#include "common.h"
#include "draw.h"

class Laser :
    public GameObject
{
public:
	Laser(float xposition, float yposition, float xdirection, float ydirection, float speed);
	void start();
	void update();
	void draw();
	float getXPosition();
	float getYPosition();
	float getWidth();
	float getHeight();

private:
	SDL_Texture* texture;
	int x;
	int y;
	int width;
	int height;
	int speed;
	float xdirection;
	float ydirection;
};

