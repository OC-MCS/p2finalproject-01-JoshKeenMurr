#include "Bomb.h"


//===========================================================================
//getPosition: returns the current position of the bomb sprite
// parameters:
//	N/A
// return type: Vector2f
//===========================================================================
Vector2f Bomb::getPosition()
{
	return bomb.getPosition();
}

//===========================================================================
//setPosition: sets the current position of the bomb sprite
// parameters:
//	x: float variable holding the x location
//  y: float variable holding the y location
// return type: void
//===========================================================================
void Bomb::setPosition(float x, float y)
{
	bomb.setPosition(x, y);
}

//===========================================================================
//bombMove: moves a single bomb sprite down the screen
// parameters:
//	N/A
// return type: void
//===========================================================================
void Bomb::bombMove()
{
	Vector2f bombPos = bomb.getPosition();

	bombPos.y = bombPos.y + 10;
	bomb.setPosition(bombPos);
}

//===========================================================================
//getSprite: returns the sprite of the bomb
// parameters:
//	N/A
// return type: Sprite
//===========================================================================
Sprite Bomb::getSprite()
{
	return bomb;
}

//===========================================================================
//drawBomb: draws the bomb sprite onto the window
// parameters:
//	window: RenderWindow variable thats passed by reference so that it can be drawn on
// return type: void
//===========================================================================
void Bomb::drawBomb(RenderWindow& window)
{
	window.draw(bomb);
}

//===========================================================================
//getGlobalBounds: returns the current position of the bomb sprite
// parameters:
//	N/A
// return type: FloatRect
//===========================================================================
FloatRect Bomb::getGlobalBounds()
{
	return bomb.getGlobalBounds();
}