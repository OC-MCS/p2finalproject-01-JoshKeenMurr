#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>
#include "Missile.h"
#pragma once

class missileHolder : public Missile
{
private:
	list<Missile> missileList; // list that holds the missiles
	Texture missileTexture;

public:
	//===========================================================================
	//missileHolder: constructor for the missileHolder class that sets the texture
	// parameters:
	//	N/A
	// return type: N/A
	//===========================================================================
	missileHolder()
	{
		if (!missileTexture.loadFromFile("missile.png"))
		{
			cout << "Unable to load ship texture!" << endl;
			exit(EXIT_FAILURE);
		}
	}

	vector<FloatRect> getGlobalbounds();

	void deleteMissiles();
	void moveAllMiss();
	void addMiss(Vector2f);
	void drawMiss(RenderWindow&);
	bool checkEmpty();
	int getNumMissile();
	void missileHitAlien(FloatRect);
};
