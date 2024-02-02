#include "Controller.h"
#include "Scene.h"

Controller::~Controller()
{
	for (int i = 0; i < lasers.size(); i++) {

		delete lasers[i];
	}
	lasers.clear();
}

void Controller::start()
{
	texture = loadTexture("gfx/player.png");

	x = 100;
	y = 100;
	width = 0;
	height = 0;
	speed = 2;
	rechargeCount = 8;
	Currentrecharge = 0;
	Siderecharge = 6;
	CurrentSideRC = 0;

	SDL_QueryTexture(texture, NULL, NULL, &width, &height);

	sound = SoundManager::loadSound("sound/334227__jradcoolness__laser.ogg");
}

void Controller::update()
{
	if (app.keyboard[SDL_SCANCODE_W]) {
		y -= speed;
	}
	if (app.keyboard[SDL_SCANCODE_S]) {
		y += speed;
	}
	if (app.keyboard[SDL_SCANCODE_A]) {
		x -= speed;
	}
	if (app.keyboard[SDL_SCANCODE_D]) {
		x += speed;
	}
	if (app.keyboard[SDL_SCANCODE_LSHIFT]) {
		speed = 5;
	}
	if (app.keyboard[SDL_SCANCODE_BACKSPACE]) {
		speed = 2;
	}

	if (Currentrecharge > 0)
		Currentrecharge--;

	if (app.keyboard[SDL_SCANCODE_F] && Currentrecharge == 0) {

		SoundManager::playSound(sound);
		Laser* laser = new Laser(x + width,y - 2 + height/2 ,1, 0, 10);
		lasers.push_back(laser);
		getScene()->addGameObject(laser);
		

		Currentrecharge = rechargeCount;
	}
	if (app.keyboard[SDL_SCANCODE_G] && CurrentSideRC == 0) {
		SoundManager::playSound(sound);
		Laser* sidelaserL = new Laser(x, y, 1, 0, 10);
		Laser* sidelaserR = new Laser(x, y - 4 + height, 1, 0, 10);
		lasers.push_back(sidelaserL);
		lasers.push_back(sidelaserR);
		getScene()->addGameObject(sidelaserL);
		getScene()->addGameObject(sidelaserR);
		
	}
	for (int i = 0; i < lasers.size(); i++) {

		if (lasers[i]->getXPosition() > SCREEN_WIDTH) {
			Laser* lasertoerase = lasers[i];
			lasers.erase(lasers.begin() + i);
			delete lasertoerase;
			break;
		}
	}
}

void Controller::draw()
{
	blit(texture, x, y);
}

int Controller::getXPosition()
{
	return x;
}

int Controller::getYPosition()
{
	return y;
}
