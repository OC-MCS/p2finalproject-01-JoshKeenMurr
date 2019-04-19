#include "Alien.h"

//===========================================================================
//Alien: default Alien class constructor
// parameters:
//	N/A
// return type: N/A
//===========================================================================
Alien::Alien()
{
}

//===========================================================================
//setTexture: sets the texture of the current alien object
// parameters:
//	N/A
// return type: void
//===========================================================================
void Alien::setTexture()
{
	if (!enemyTexture.loadFromFile("enemy.png"))
	{
		cout << "Unable to load enemy texture!" << endl;
		exit(EXIT_FAILURE);
	}
	// sprite for enemy

	enemy.setTexture(enemyTexture);
}

//===========================================================================
//setSecondTexture: sets the texture of the current alien object to the level two skin
// parameters:
//	N/A
// return type: void
//===========================================================================
void Alien::setSecondTexture()
{
	if (!enemyTexture.loadFromFile("enemySecond.png"))
	{
		cout << "Unable to load enemy texture!" << endl;
		exit(EXIT_FAILURE);
	}
	// sprite for enemy

	enemy.setTexture(enemyTexture);
}

//===========================================================================
//getSprite: returns the sprite of the current alien
// parameters:
//	N/A
// return type: sprite
//===========================================================================
Sprite Alien::getSprite()
{
	return enemy;
}

//===========================================================================
//getPosition: returns the current position of the alien
// parameters:
//	N/A
// return type: vector2f
//===========================================================================
Vector2f Alien::getPosition()
{
	return enemy.getPosition();
}

//===========================================================================
//getSprite: moves the current alien down the screen
// parameters:
//	N/A
// return type: void
//===========================================================================
void Alien::move()
{
	Vector2f enem = enemy.getPosition();

	enem.y = enem.y + .3;
	enemy.setPosition(enem);
}

//===========================================================================
//getSprite: returns the location of the current alien
// parameters:
//	N/A
// return type: floatRect
//===========================================================================
FloatRect Alien::getGlobalBounds()
{
	return enemy.getGlobalBounds();
}

//===========================================================================
//getSprite: sets the position of the current alien
// parameters:
//	x: x location to set the alien at
//  y: y location to set the alien at
// return type: void
//===========================================================================
void Alien::setPosition(float x, float y)
{
	enemy.setPosition(x, y);
}

