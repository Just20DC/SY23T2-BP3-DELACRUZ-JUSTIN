#pragma once
#include "GameObject.h"
#include "common.h"
#include "draw.h"

enum class Side {
	PLAYER_SIDE,
	ENEMY_SIDE
};

class Laser :
    public GameObject
{
public:
	Laser(float xposition, float yposition, float xdirection, float ydirection, float speed, Side side);
	void start();
	void update();
	void draw();
	float getXPosition();
	float getYPosition();
	float getWidth();
	float getHeight();
	Side getSide();
private:
	SDL_Texture* texture;
	Side side;
	int x;
	int y;
	int width;
	int height;
	int speed;
	float xdirection;
	float ydirection;
};

