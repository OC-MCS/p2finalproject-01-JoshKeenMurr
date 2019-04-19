#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Bombs.h"
#pragma once

// class that contains everything for a single alien

class Alien : public Bombs
{
private:
	Texture enemyTexture;
	Sprite enemy;
	

public:
	Alien();
	void setTexture();
	void setSecondTexture();
	void setPosition(float, float);

	Vector2f getPosition();
	Sprite getSprite();
	void move();
	FloatRect getGlobalBounds();
};