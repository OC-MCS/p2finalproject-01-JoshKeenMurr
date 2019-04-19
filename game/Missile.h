#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#pragma once

class Missile 
{
private:
	Sprite missileSprite; // sprite for the missile
public:
	//===========================================================================
	//Missile: default constructor for the missile class
	// parameters:
	//	N/A
	// return type: N/A
	//===========================================================================
	Missile()
	{
	}

	//===========================================================================
	//Missile: constructor for the missile class the passes the texture for the missile
	// parameters:
	//	N/A
	// return type: N/A
	//===========================================================================
	Missile(Texture &texture)
	{
		missileSprite.setTexture(texture);
	}

	Sprite getSprite();
	void setPosition(float, float);
	FloatRect getGlobalBounds();
	Vector2f getPosition();
	void missMove();
};