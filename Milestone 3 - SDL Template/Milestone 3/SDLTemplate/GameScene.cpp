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
	spawntimer = 300;
	spawntime = 300;

	for (int i = 0; i < 3; i++) {

		spawn();
		spawntimer = spawntime;
	}
	
}

void GameScene::draw()
{
	Scene::draw();
}

void GameScene::update()
{
	Scene::update();

	if (spawntimer > 0) {
		spawntimer--;
	}

	if (spawntimer <= 0) {
		
		enemy = new Enemy();
		this->addGameObject(enemy);
		enemy->setPlayerTarget(controller);

		enemy->setPosition(1200, 300 + (rand() % 300));
		Reinforcement.push_back(enemy);
		spawntimer = spawntime;
	}

	
}

void GameScene::spawn()
{
	enemy = new Enemy();
	this->addGameObject(enemy);
	enemy->setPlayerTarget(controller);

	enemy->setPosition(1200, 300 + (rand() % 300));
	Reinforcement.push_back(enemy);
}
