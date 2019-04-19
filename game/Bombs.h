#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>
#include "Bomb.h"
#pragma once

// class that holds all of the single bombs

class Bombs 
{
private:
	list<Bomb> downFall;
	Texture bombTexture;
	
public:
	//===========================================================================
	//Bombs: constructor for Bombs class that loadds the texture of the bomb
	// parameters:
	//	N/A
	// return type: N/A
	//===========================================================================
	Bombs()
	{
		if (!bombTexture.loadFromFile("bathbomb.png"))
		{
			cout << "Unable to load ship texture!" << endl;
			exit(EXIT_FAILURE);
		}
	}
	
	void dropBombBomb();
	void moveAllBombs();
	void addBomb( Vector2f);
	void drawBombs(RenderWindow&);
	bool hitShip(FloatRect);
	void hitShipDelete(FloatRect);
	vector<Vector2f> getGlobalbounds();
};