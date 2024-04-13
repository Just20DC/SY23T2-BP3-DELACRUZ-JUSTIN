#pragma once
#include "Scene.h"
#include "GameObject.h"
#include <vector>
#include "text.h"
#include "Snake.h"
#include "util.h"
#include "Food.h"

class GameScene : public Scene
{
public:

	GameScene();
	~GameScene();
	void start();
	void draw();
	void update();

	void collisionLogic();
	void selfCollision();
	

private:

	Snake* player;
	Food* apple;
	int points;
	
	SDL_Texture* texture;
	std::vector<Food*> goods;
};

