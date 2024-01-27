#pragma once
#include "GameObject.h"
#include "common.h"
#include "draw.h"
#include "SoundManager.h"
#include "Laser.h"
#include <vector>

class Controller :
	public GameObject
{
public:
	~Controller();
	void start();
	void update();
	void draw();
private:
	SDL_Texture* texture;
	Mix_Chunk* sound;
	int x;
	int y;
	int width;
	int height;
	int speed;
	float rechargeCount;
	float Currentrecharge;
	float Siderecharge;
	float CurrentSideRC;
	std::vector<Laser*> lasers;
};

