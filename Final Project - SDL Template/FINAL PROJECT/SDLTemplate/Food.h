#pragma once
#include "GameObject.h"
#include "common.h"
#include "draw.h"
#include "util.h"
#include "SoundManager.h"
#include "Snake.h"

class Food :
    public GameObject
{
public:
    Food();
    void start();
    void Changecoordinates(int xPos, int yPos);
    void update();
    void draw();
    int getterX();
    int getterY();
    int getwidth();
    int getheight();
    
   

private:
    SDL_Texture* texture;
    Mix_Chunk* sfx;
    int x;
    int y;
    int width;
    int height;
   
    
};

