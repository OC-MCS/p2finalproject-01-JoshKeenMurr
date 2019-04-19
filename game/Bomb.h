#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>
#pragma once

// Base class for the bombs

class Bomb
{
private:
	Sprite bomb;
public:
	//===========================================================================
	//Bomb: Default constructor 
	//===========================================================================
	Bomb()
	{
	}

	//===========================================================================
	//Bomb: sets texture of the sprite for the bomb class
	// parameters:
	//	texture: Tetxure variable containing the texture for the bomb
	// return type: N/A
	//===========================================================================
	Bomb(Texture &texture)
	{
		bomb.setTexture(texture);
	}
	
	Vector2f getPosition();
	void setPosition(float x, float y);
	void bombMove();
	Sprite getSprite();
	void drawBomb(RenderWindow&);
	FloatRect getGlobalBounds();
};