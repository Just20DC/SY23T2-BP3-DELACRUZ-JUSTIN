#include "GameScene.h"
#include "Scene.h"

GameScene::GameScene()
{
	// Register and add game objects on constructor
	player = new Snake;
	this->addGameObject(player);

	apple = new Food;
	this->addGameObject(apple);

	points = 0;
}

GameScene::~GameScene()
{
	delete player;
}

void GameScene::start()
{
	Scene::start();
	
	// Initialize any scene logic here
	initFonts();
	

	
	
}

void GameScene::draw()
{
	Scene::draw();
	drawText(110, 20, 255, 255, 255, TEXT_CENTER, "POINTS: %03d", points);

	if (player->getIsAlive() == false) {

		drawText(SCREEN_WIDTH / 2, 300, 255, 0, 0, TEXT_CENTER, "G A M E  O V E R");
	}

	
	
}

void GameScene::update()
{
	Scene::update();
	
	collisionLogic();
	selfCollision();
}



void GameScene::collisionLogic()
{
	Segment* front = player->getV()[0];
	std::vector<Segment*> snakeBody = player->getV();

	for (int i = 0; i < objects.size(); i++) {

		Food* food = dynamic_cast<Food*>(objects[i]);

		if (food != NULL) {

			int collision = checkCollision(
				front->x, front->y, player->getWidth(), player->getHeight(),
				food->getterX(), food->getterY(), food->getwidth(), food->getheight()
			);

			if (collision == 1) {

				
					player->addSegment(snakeBody[snakeBody.size() - 1]->x, snakeBody[snakeBody.size() - 1]->y);
					points++;

				
				break;
			}
		}
		
	}
	
}

void GameScene::selfCollision()
{
	std::vector<Segment*> body = player->getV();
	Segment* head = player->getV()[0];

	for (int i = 1; i < player->getV().size(); i++) {
		if (head->x == body[i]->x && head->y == body[i]->y) {
			player->IsPartAlive(false);
			break;
		}
	}
}








