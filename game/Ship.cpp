#include "Ship.h"

//===========================================================================
//ship: default constructor for the ship
// parameters:
//	N/A
// return type: N/A
//===========================================================================
Ship::Ship()
{
}

//===========================================================================
//setPosition: used when level one and two starts to make the ship begin in the middle
// parameters:
//	N/A
// return type: void
//===========================================================================
void Ship::setPosition()
{
	float shipX = 800 / 2.0f;
	float shipY = 600 / 1.1f;
	shipPos.x = shipX;
	shipPos.y = shipY;

	shipSprite.setPosition(shipPos); // setting the ships position

}

//===========================================================================
//moveShip: moves the ship when the left or right arrow key is pressed, unless it is too far left or right it doesnt move anywhere
// parameters:
//	N/A
// return type: void
//===========================================================================
void Ship::moveShip()
{
	const float DISTANCE = 5.0;

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		// left arrow is pressed: move our ship left 5 pixels
		// 2nd parm is y direction. We don't want to move up/down, so it's zero.
		Vector2f offScreen = shipSprite.getPosition();
		if (offScreen.x < 2)
		{
			shipSprite.move(0, 0);
		}
		else
			shipSprite.move(-DISTANCE, 0);
	}

	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		// right arrow is pressed: move our ship right 5 pixels
		Vector2f offScreen = shipSprite.getPosition();
		if (offScreen.x > 774)
		{
			shipSprite.move(0, 0);
		}
		else
			shipSprite.move(DISTANCE, 0);
	}
}

//===========================================================================
//setTexture: sets the texture of the ship
// parameters:
//	N/A
// return type: void
//===========================================================================
void Ship::setTexture()
{
	if (!shipTexture.loadFromFile("ship.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}

	shipSprite.setTexture(shipTexture);
}

//===========================================================================
//getSprite: returns the sprite of the ship
// parameters:
//	N/A
// return type: Sprite
//===========================================================================
Sprite Ship::getSprite()
{
	return shipSprite;
}

//===========================================================================
//getPosition: returns the Vector2f position of the ship
// parameters:
//	N/A
// return type: Vector2f
//===========================================================================
Vector2f Ship::getPosition()
{
	return shipSprite.getPosition();
}

//===========================================================================
//getGlobalBounds: returns the FloatRect position of the ship
// parameters:
//	N/A
// return type: FloatRect
//===========================================================================
FloatRect Ship::getGlobalBounds()
{
	return shipSprite.getGlobalBounds();
}