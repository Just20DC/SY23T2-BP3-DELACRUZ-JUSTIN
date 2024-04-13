#include "Snake.h"

Snake::Snake()
{
	
}

void Snake::start()
{
	headTexture = loadTexture("gfx/head.png");
	bodyTexture = loadTexture("gfx/body.png");

	tempX = 0;
	tempY = 0;

	x = 0;
	y = 0;
	dx = 0;
	dy = 0;

	isAlive = true;
	hasMoved = false;
	width = 0;
	height = 0;
	
	SDL_QueryTexture(headTexture, NULL, NULL, &width, &height);

	addSegment(x, y);
}

void Snake::update()
{
	std::cout << "Head" << body[0]->x << std::endl;
	if (body.size() > 1) {
		std::cout << "2nd Segment" << body[1]->x << std::endl;
		if (body.size() > 2) {
			std::cout << "3nd Segment" << body[2]->x << std::endl;
		}
	}

	movement();
	outofboundscheck();

}

void Snake::draw()
{
	if (!isAlive) return;

	for (int i = 0; i < body.size(); i++) {

		blit(headTexture, body[i]->x, body[i]->y);
	}
	
}

void Snake::outofboundscheck()
{
	for (int i = 0; i < body.size(); i++) {
		if (body[i]->x > SCREEN_WIDTH) {

			body[i]->x = 0;

		}
		if (body[i]->x < 0) {

			body[i]->x = SCREEN_WIDTH;

		}

		if (body[i]->y > SCREEN_HEIGHT) {

			body[i]->y = 0;

		}

		if (body[i]->y < 0) {

			body[i]->y = SCREEN_HEIGHT;

		}
	}
}

void Snake::movement()
{
	if (app.keyboard[SDL_SCANCODE_W] && dy != 5) {

		dx = 0;
		dy = -5;

	}

	if (app.keyboard[SDL_SCANCODE_A] && dx != 5) {

		dx = -5;
		dy = 0;

	}

	if (app.keyboard[SDL_SCANCODE_S] && dy != -5) {

		dx = 0;
		dy = 5;

	}

	if (app.keyboard[SDL_SCANCODE_D] && dx != -5) {

		dx = 5;
		dy = 0;

	}

	Segment* snakeHead = *(body.begin()); //Grid

	tempX += dx;
	tempY += dy;

	if (tempX % 25 == 0) {
		snakeHead->x += tempX;
		tempX = 0;
	}

	if (tempY % 25 == 0) {
		snakeHead->y += tempY;
		tempY = 0;
	}


	for (int i = body.size() - 1; i > 0; i--) { //For the other parts to follow

		body[i]->x = body[i - 1]->x;
		body[i]->y = body[i - 1]->y;

	}
}

void Snake::addSegment(int x, int y)
{
	Segment* seg = new Segment(x, y);
	body.push_back(seg);
}

void Snake::Collisioncheckself(bool hasEaten)
{
	Segment* face = body[0];

	if (hasEaten == false) {
		for (int i = 1; i < body.size(); i++) {
			if (face->x == body[i]->x && face->y == body[i]->y) {
				isAlive = false;
				break;
			}
		}
	}

	else {
		return;
	}
}

void Snake::parthasMoved(bool a)
{
	hasMoved = a;
}

void Snake::IsPartAlive(bool a)
{
	isAlive = a;
}

int Snake::getX()
{
	return x;
}

int Snake::getY()
{
	return y;
}

int Snake::getWidth()
{
	return width;
}

int Snake::getHeight()
{
	return height;
}

bool Snake::getIsAlive()
{
	return isAlive;
}

bool Snake::getHasMoved()
{
	return hasMoved;
}

std::vector<Segment*> const& Snake::getV() const
{
	// TODO: insert return statement here
	return body;
}


