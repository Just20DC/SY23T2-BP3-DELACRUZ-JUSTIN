#pragma once
#include "Scene.h"
#include "GameObject.h"
#include "Controller.h"

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
};

