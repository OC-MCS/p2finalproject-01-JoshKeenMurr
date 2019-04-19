#include "Alien.h"
#include <iostream>
#include <list>
#include <time.h>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#pragma once

// class to hold all of the aliens and control what happens to them

class AlienGroup : public Alien
{
private:
	list<Alien> alienHerd;

public:
	AlienGroup();
	void reset();
	void drawAliens(RenderWindow&, bool);
	vector<FloatRect> getGlobalbounds();
	int numofAliens();
	void killAlien(FloatRect);
	void move();
	void addBombfromAlien(Bombs&, int);
	vector<Vector2f> getVector2fPos();
	void resetPosition();
};