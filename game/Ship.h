#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#pragma once

// class containing functions for the ship 

class Ship
{
private:
	Texture shipTexture;
	Sprite shipSprite;
	Vector2f shipPos;
public:
	Ship();
	void moveShip();
	void setTexture();
	void setPosition();
	Sprite getSprite();
	Vector2f getPosition();
	FloatRect getGlobalBounds();
};