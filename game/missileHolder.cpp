#include "missileHolder.h"

//===========================================================================
//getPosition: returns a vector of Vector2f locations of the missiles on screen
// parameters:
//	N/A
// return type: vector<Vector2f>
//===========================================================================
vector<FloatRect> missileHolder::getGlobalbounds()
{
	vector<FloatRect> temp;
	int i = 0;
	list<Missile>::iterator iter;
	for (iter = missileList.begin(); iter != missileList.end(); iter++)
	{
		temp.push_back(iter->getGlobalBounds());
	}

	return temp; // returns the vector
}

//===========================================================================
//addMiss: adds a missile to the list of missiles
// parameters:
//	shipPos: position of the ship where the missile will start from
// return type: void
//===========================================================================
void missileHolder::addMiss(Vector2f shipPos)
{
	Missile temp(missileTexture);

	temp.setPosition(shipPos.x, shipPos.y);
	missileList.push_back(temp); // adds a new missile to the list
}

//===========================================================================
//deleteMissiles: deletes a missile if it goes off the top of the screen
// parameters:
//	N/A
// return type: void
//===========================================================================
void missileHolder::deleteMissiles()
{
	bool kickout = false;

	list<Missile>::iterator iter;
	for (iter = missileList.begin(); iter != missileList.end() && !kickout;)
	{
		Vector2f currentPos = iter->getPosition();
		if (currentPos.y < 0) // if missile goes off screen, delete it
		{
			iter = missileList.erase(iter);
			kickout = true;
		}
		else // else, continue throught the loop
		{
			iter++;
		}
	}
}

//===========================================================================
//moveAllMiss: goes through the list and moves all missiles toward the top of the screen
// parameters:
//	N/A
// return type: void
//===========================================================================
void missileHolder::moveAllMiss()
{

	list<Missile>::iterator iter;
	for (iter = missileList.begin(); iter != missileList.end(); iter++)
	{
		iter->missMove();
	}
}

//===========================================================================
//drawMiss: goes through the list and draws all missiles onto the screen
// parameters:
//	window: renderwindow variable passed by reference that gets drawn on
// return type: void
//===========================================================================
void missileHolder::drawMiss(RenderWindow& window)
{

	list<Missile>::iterator iter;
	for (iter = missileList.begin(); iter != missileList.end(); iter++)
	{
		window.draw(iter->getSprite());  // draws the missile sprite onto the screen
	}
}

//===========================================================================
//checkEmpty: checks if the list is empty
// parameters:
//	N/A
// return type: bool
//===========================================================================
bool missileHolder::checkEmpty()
{
	return missileList.empty(); // returns bool of whether or not the list is empty
}

//===========================================================================
//getNumMissile: returns the number of missiles in the list
// parameters:
//	N/A
// return type: int
//===========================================================================
int missileHolder::getNumMissile() 
{
	int count = 0;
	list<Missile>::iterator iter;
	for (iter = missileList.begin(); iter != missileList.end(); iter++) // goes through the list
	{
		count++;
	}
	return count;
}

//===========================================================================
//missileHitAlien: if a missile hits an alien, delete the missile from the list
// parameters:
//	alienPos: pos of the alien that is being tested
// return type: void
//===========================================================================
void missileHolder::missileHitAlien(FloatRect alienPos)
{
	list<Missile>::iterator iter;
	for (iter = missileList.begin(); iter != missileList.end();)
	{

		if (iter->getGlobalBounds().intersects(alienPos)) // if the missile comes in contact with the alien, delete the missile
		{
			iter = missileList.erase(iter);
		}
		else // go through the rest of the loop
			iter++;
	}
}