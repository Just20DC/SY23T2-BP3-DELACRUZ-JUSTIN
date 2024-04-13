#pragma once
#include "GameObject.h"
#include <vector>
#include "Food.h"
#include "util.h"




struct Segment {
    int x;
    int y;
 
    Segment(int posx, int posy) {

        x = posx;
        y = posy;

    }
};

class Snake :
    public GameObject
{
public:
    Snake();
    void start();
    void update();
    void draw();
    void outofboundscheck();
    void movement();
    void addSegment(int x, int y);
    void Collisioncheckself(bool hasEaten);
    void parthasMoved(bool a);
    void IsPartAlive(bool a);

    int getX();
    int getY();
    int getWidth();
    int getHeight();
    bool getIsAlive();
    bool getHasMoved();

    std::vector<Segment*> const& getV() const;

private:
   
    std::vector<Segment*> body;
    SDL_Texture* headTexture;
    SDL_Texture* bodyTexture;

    int x;
    int y;
    int width;
    int height;
    int dx;
    int dy;
    int tempX;
    int tempY;
    bool isAlive;
    bool hasMoved;
    
    
};


