#pragma once
#include "GameObject.h"
#include "common.h"
#include "draw.h"
#include "util.h"
#include "SoundManager.h"

class PowerUp :
    public GameObject
{
public:
	PowerUp();
	~PowerUp();
	void start();
	void update();
	void draw();
	void setPosition(int xPos, int yPos);
	int getXposition();
	int getYposition();
	int getheight();
	int getwidth();
	
private:
	SDL_Texture* texture;
	Mix_Chunk* sound;
	int x;
	int y;
	int width;
	int height;
	int speed;
	float xdirection;
	float ydirection;
	float Pathchangetime;
	float CurrentPathtime;
};

