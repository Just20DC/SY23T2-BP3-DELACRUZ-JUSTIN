#include "GameScene.h"

GameScene::GameScene()
{
	// Register and add game objects on constructor
	controller = new Controller();
	this->addGameObject(controller);
}

GameScene::~GameScene()
{
	delete controller;
}

void GameScene::start()
{
	Scene::start();
	// Initialize any scene logic here
}

void GameScene::draw()
{
	Scene::draw();
}

void GameScene::update()
{
	Scene::update();
}
