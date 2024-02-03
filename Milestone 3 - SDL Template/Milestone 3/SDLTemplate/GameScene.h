#pragma once
#include "Scene.h"
#include "GameObject.h"
#include "Controller.h"
#include "Enemy.h"
#include <vector>

class GameScene : public Scene
{
public:

	GameScene();
	~GameScene();
	void start();
	void draw();
	void update();
private:
	Controller* controller;
	Enemy* enemy;

	float spawntime;
	float spawntimer;
	
	std::vector<Enemy*> Reinforcement;
	void spawn();
};

