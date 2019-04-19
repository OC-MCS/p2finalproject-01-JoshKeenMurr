#include <iostream>
#include <string>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#pragma once

// class that handles all of the UI in the game

class UI
{
private:
	Texture starsTexture;
	Sprite background;
	Text startBut;
	int lives;
	Font font;

	//===========================================================================
	//die: kills the current function it gets called to
	// parameters:
	// msg: string containing the message to be said
	// return type: void
	//===========================================================================
	void die(string msg)
	{
		cout << msg << endl;
		exit(-1);
	}

public:
	UI();
	FloatRect getSGB();
	void startScreen(RenderWindow&);
	void winner(RenderWindow&);
	void setBackground();
	Sprite getBack();
	void lifeScore(RenderWindow&, int);
	int getLives();
	void setLives();
	void dead(RenderWindow&);
};

