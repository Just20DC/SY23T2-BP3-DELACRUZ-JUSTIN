#include "GameScene.h"
#include "Scene.h"

GameScene::GameScene()
{
	// Register and add game objects on constructor
	controller = new Controller();
	this->addGameObject(controller);

	points = 0;
	
	
}

GameScene::~GameScene()
{
	delete controller;
}

void GameScene::start()
{
	Scene::start();
	
	// Initialize any scene logic here
	initFonts();
	

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
	drawText(110, 20, 255, 255, 255, TEXT_CENTER, "POINTS: %03d", points);

	if (controller->getIsAlive() == false) {

		drawText(SCREEN_WIDTH / 2, 300, 255, 0, 0, TEXT_CENTER, "G A M E  O V E R");
	}

	
	
}

void GameScene::update()
{
	Scene::update();
	checkSpawn();
	LogicCollision();
}

void GameScene::checkSpawn()
{
	if (spawntimer > 0) {
		spawntimer--;
	}

	if (spawntimer <= 0) {

		enemy = new Enemy();
		this->addGameObject(enemy);
		enemy->setPlayerTarget(controller);

		enemy->setPosition(1200, 300 + (rand() % 300));
		Reinforcement.push_back(enemy);

		powerup = new PowerUp();
		this->addGameObject(powerup);
		powerup->setPosition(1200, 300 + (rand() % 300));
		bonus.push_back(powerup);

		spawntimer = spawntime;


	}

}

void GameScene::LogicCollision()
{
	for (int i = 0; i < objects.size(); i++) {

		Laser* laser = dynamic_cast<Laser*> (objects[i]);
		
		if (powerup != NULL) {
			
			int collision = checkCollision(
				controller->getXPosition(), controller->getYPosition(), controller->getWidth(), controller->getHeight(),
				powerup->getXposition(),powerup->getYposition(),powerup->getwidth(),powerup->getheight());

			if (collision == 1) {

				controller->checkPowerUp();
			}
		}
		if (laser != NULL) {
			if (laser->getSide() == Side::ENEMY_SIDE) {

				int collision = checkCollision(
					controller->getXPosition(), controller->getYPosition(), controller->getWidth(), controller->getHeight(),
					laser->getXPosition(), laser->getYPosition(), laser->getWidth(), laser->getHeight());

				if (collision == 1) {

					controller->doDeath();
					break;
				}
			}
			else if (laser->getSide() == Side::PLAYER_SIDE) {

				for (int i = 0; i < Reinforcement.size(); i++) {

					Enemy* currentTarget = Reinforcement[i];

					int collision = checkCollision(
						currentTarget->getXPosition(), currentTarget->getYPosition(), currentTarget->getWidth(), currentTarget->getHeight(),
						laser->getXPosition(), laser->getYPosition(), laser->getWidth(), laser->getHeight());

					if (collision == 1) {
						
						despawn(currentTarget);
						points++;
						break;
					}
				}
			}
		}
	}
}

void GameScene::spawn()
{
	enemy = new Enemy();
	this->addGameObject(enemy);
	enemy->setPlayerTarget(controller);

	enemy->setPosition(1200, 300 + (rand() % 300));
	Reinforcement.push_back(enemy);

	if (points == 10) {
		this->addGameObject(enemy);
		enemy->setPlayerTarget(controller);
		enemy->setPosition(1200, 300 + (rand() % 300));
		Reinforcement.push_back(enemy);
	}
}

void GameScene::despawn(Enemy* enemy)
{
	int index = -1;
	for (int i = 0; i < Reinforcement.size(); i++) {
		if (enemy == Reinforcement[i]) {
			index = i;
			break;
		}
	}
	
	if (index != -1) {
		Reinforcement.erase(Reinforcement.begin() + index);
		delete enemy;
		
	
	}

	if (points == 10) {
		
		Reinforcement.erase(Reinforcement.begin() + index);
		Reinforcement.clear();
		
	}
}
