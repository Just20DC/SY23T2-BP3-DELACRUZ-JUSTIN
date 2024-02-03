#pragma once
#include "GameObject.h"
#include "common.h"
#include "draw.h"
#include "SoundManager.h"
#include "Laser.h"
#include <vector>
#include "util.h"
#include "Controller.h"

class Enemy :
    public GameObject
{
public:
	Enemy();
	~Enemy();
	void start();
	void update();
	void draw();
	void setPlayerTarget(Controller* player);
	void setPosition(int x, int y);
private:
	Controller* enemytarget;
	SDL_Texture* texture;
	Mix_Chunk* sound;
	int x;
	int y;
	float directionY;
	float directionX;
	int width;
	int height;
	int speed;
	float rechargeCount;
	float Currentrecharge;
	float Pathchangetime;
	float CurrentPathtime;
	std::vector<Laser*> lasers;
};

