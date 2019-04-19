#include "Bombs.h"

//===========================================================================
//getGlobalbounds: returns a vector of positions of all the bombs in the list of bombs
// parameters:
//	N/A
// return type: vector<Vector2f>
//===========================================================================
vector<Vector2f> Bombs::getGlobalbounds()
{
	vector<Vector2f> temp;
	int i = 0;
	list<Bomb>::iterator iter;
	for (iter = downFall.begin(); iter != downFall.end(); iter++)
	{
		temp.push_back(iter->getPosition());
	}

	return temp;
}

//===========================================================================
//addBomb: adds a bomb to list of bombs
// parameters:
//	alienPos: position of the alien to start the bomb from
// return type: Vector2f
//===========================================================================
void Bombs::addBomb(Vector2f alienPos)
{
	Bomb temp(bombTexture);

	temp.setPosition(alienPos.x + 5, alienPos.y);
	downFall.push_back(temp);
}

//===========================================================================
//dropBombBomb: deletes any bombs that leave the screen 
// parameters:
//	N/A
// return type: void
//===========================================================================
void Bombs::dropBombBomb()
{
	bool kickout = false;

	list<Bomb>::iterator iter;
	for (iter = downFall.begin(); iter != downFall.end() && !kickout;)
	{
		Vector2f currentPos = iter->getPosition();
		if (currentPos.y > 550)
		{
			iter = downFall.erase(iter);
			kickout = true;
		}
		else
		{
			iter++;
		}
	}	
}

//===========================================================================
//moveAllBombs: moves all bombs in the list down the screen
// parameters:
//	N/A
// return type: void
//===========================================================================
void Bombs::moveAllBombs()
{

	list<Bomb>::iterator iter;
	for (iter = downFall.begin(); iter != downFall.end(); iter++)
	{

		iter->bombMove();

	}
}

//===========================================================================
//drawBombs: draws all the bombs in the list onto the window
// parameters:
//	window: renderWindow variable passed by reference so that it can be drawn on
// return type: void
//===========================================================================
void Bombs::drawBombs(RenderWindow& window)
{

	list<Bomb>::iterator iter;
	for (iter = downFall.begin(); iter != downFall.end(); iter++)
	{
		window.draw(iter->getSprite());		
	}
}

//===========================================================================
//hitShip: returns a booleal var of whether or not a bomb hit the ship
// parameters:
//	shipPos: FloatRect varaible containing the position of the ship
// return type: bool
//===========================================================================
bool Bombs::hitShip(FloatRect shipPos)
{
	bool hit = false;

	list<Bomb>::iterator iter;
	for (iter = downFall.begin(); iter != downFall.end(); iter++)
	{

		if (iter->getGlobalBounds().intersects(shipPos))
			hit = true;
	}
	return hit;
}

//===========================================================================
//hitShipDelete: deletes a bomb from the list if it comes in contact with the ship
// parameters:
//	shipPos: FloatRect varaible containing the position of the ship
// return type: void
//===========================================================================
void Bombs::hitShipDelete(FloatRect shipPos)
{
	list<Bomb>::iterator iter;
	for (iter = downFall.begin(); iter != downFall.end();)
	{

		if (iter->getGlobalBounds().intersects(shipPos))
		{
			iter = downFall.erase(iter);
		}
		else
			iter++;
	}
}