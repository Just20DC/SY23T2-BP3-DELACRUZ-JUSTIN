#pragma once
#include "Scene.h"
#include "GameObject.h"
#include "Controller.h"
#include "Enemy.h"
#include <vector>
#include "text.h"

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
	SDL_Texture* texture;
	void checkSpawn();
	void LogicCollision();
	void spawn();
	void despawn(Enemy* enemy);
	int points;
};

