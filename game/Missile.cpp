#include "Missile.h"

//===========================================================================
//setPosition: sets the position of the missile
// parameters:
//	x: x location for the missile
//  y: y location for the missile
// return type: void
//===========================================================================
void Missile::setPosition(float x, float y)
{
	missileSprite.setPosition(x, y);
}

//===========================================================================
//getPosition: returns the vector2f position of the missile
// parameters:
//	N/A
// return type: Vector2f
//===========================================================================
Vector2f Missile::getPosition()
{
	return missileSprite.getPosition();
}

//===========================================================================
//getGlobalBounds: returns the FloatRect of the position of the missile
// parameters:
//	N/A
// return type: FloatRect
//===========================================================================
FloatRect Missile::getGlobalBounds()
{
	return missileSprite.getGlobalBounds();
}

//===========================================================================
//getSprite: returns the sprite of the missile
// parameters:
//	N/A
// return type: Sprite
//===========================================================================
Sprite Missile::getSprite()
{
	return missileSprite;
}

//===========================================================================
//missMove: moves the missile up the screen
// parameters:
//	N/A
// return type: void
//===========================================================================
void Missile::missMove()
{
	Vector2f missPos = missileSprite.getPosition(); // temp variable to hold the changed position

	missPos.y = missPos.y - 15;
	missileSprite.setPosition(missPos);
}