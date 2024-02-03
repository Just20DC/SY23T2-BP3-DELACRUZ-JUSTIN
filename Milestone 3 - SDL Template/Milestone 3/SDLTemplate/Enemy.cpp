#include "Enemy.h"
#include "Scene.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::start()
{
	texture = loadTexture("gfx/enemy.png");

	directionX = -1;
	directionY = 1;
	width = 0;
	height = 0;
	speed = 2;
	rechargeCount = 60;
	Currentrecharge = 0;
	Pathchangetime = (rand() % 300) + 180;

	SDL_QueryTexture(texture, NULL, NULL, &width, &height);

	sound = SoundManager::loadSound("sound/334227__jradcoolness__laser.ogg");
}

void Enemy::update()
{
	x += directionX * speed;
	y += directionY * speed;

	if (CurrentPathtime > 0) {
		CurrentPathtime--;
	}
	if (CurrentPathtime == 0){
		directionY = -directionY;
		CurrentPathtime = Pathchangetime;
	}
	if (Currentrecharge > 0)
		Currentrecharge--;

	if (Currentrecharge == 0) {
		float DX = -1;
		float DY = 0;

		calcSlope(enemytarget->getXPosition(), enemytarget->getYPosition(), x,y,&DX,&DY);

		SoundManager::playSound(sound);
		Laser* laser = new Laser(x + width, y - 2 + height / 2, DX, DY, 10);
		lasers.push_back(laser);
		getScene()->addGameObject(laser);


		Currentrecharge = rechargeCount;
	}
	for (int i = 0; i < lasers.size(); i++) {

		if (lasers[i]->getXPosition() < 0) {
			Laser* lasertoerase = lasers[i];
			lasers.erase(lasers.begin() + i);
			delete lasertoerase;
			break;
		}
	}

}

void Enemy::draw()
{
	blit(texture, x, y);
}

void Enemy::setPlayerTarget(Controller* player)
{
	enemytarget = player;
}

void Enemy::setPosition(int xPos, int yPos)
{
	this->x = xPos;
	this->y = yPos;
}
