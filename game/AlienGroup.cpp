#include "AlienGroup.h"

//===========================================================================
//AlienGroup: constructor for class that creates and puts 10 aliens into the list
// parameters:
//	N/A
// return type: N/A
//===========================================================================
AlienGroup::AlienGroup()
{
	
	for (float i = 0; i < 10; i++)
	{
		Alien temp;
		temp.setTexture();
		temp.setPosition(5 + i * 80,50);
		alienHerd.push_back(temp);
	}

}

//===========================================================================
//reset: creates ten new aliens when level 2 starts
// parameters:
//	N/A
// return type: void
//===========================================================================
void AlienGroup::reset()
{
	for (float i = 0; i < 10; i++) // goes through loop and creates new aliens to put into the list
	{
		Alien temp;
		temp.setSecondTexture();
		temp.setPosition(5 + i * 80, 50);
		alienHerd.push_back(temp);
	}
}

//===========================================================================
//drawAliens: draws the list of aliens onto the window
// parameters:
//    win: renderwindow varaible passed by refernce to be drawn on
// second: bool varaible that decides which type of alien is drawn
// return type: void
//===========================================================================
void AlienGroup::drawAliens(RenderWindow& win, bool second)
{
	if (!second) // if on first level
	{
		list<Alien>::iterator iter;
		for (iter = alienHerd.begin(); iter != alienHerd.end(); iter++)
		{
			iter->setTexture();
			win.draw(iter->getSprite());

		}
	}
	else if (second) // if on second level
	{
		list<Alien>::iterator iter;
		for (iter = alienHerd.begin(); iter != alienHerd.end(); iter++)
		{
			iter->setSecondTexture();
			win.draw(iter->getSprite());

		}
	}
}

//===========================================================================
//getGlobalbounds: goes through the list of aliens and returns the position of them
// parameters:
//	N/A
// return type: vector<Vector2f>
//===========================================================================
vector<FloatRect> AlienGroup::getGlobalbounds()
{
	vector<FloatRect> temp;
	int i = 0;
	list<Alien>::iterator iter;
	for (iter = alienHerd.begin(); iter != alienHerd.end(); iter++)
	{
		temp.push_back(iter->getGlobalBounds());
	}

	return temp;
}

//===========================================================================
//numofAliens: returns the number of aliens currently in the list
// parameters:
//	N/A
// return type: int
//===========================================================================
int AlienGroup::numofAliens()
{
	int count = 0;
	list<Alien>::iterator iter;
	for (iter = alienHerd.begin(); iter != alienHerd.end(); iter++)
	{
		count++; // counts number of aliens
	}

	return count;
}

//===========================================================================
//killAlien: if a missile collides with an alien, erase the alien from the list
// parameters:
//	missilepos: position of the missile
// return type: void
//===========================================================================
void AlienGroup::killAlien(FloatRect missilepos)
{
	list<Alien>::iterator iter;
	for (iter = alienHerd.begin(); iter != alienHerd.end(); /* note no ++ here*/)
	{
		if (missilepos.intersects(iter->getGlobalBounds())) // if the missile collides with an alien, erase it
			iter = alienHerd.erase(iter);
		else // else go through the list
			iter++;
	}
}

//===========================================================================
//move: goes through the list moving each alien down the screen
// parameters:
//	N/A
// return type: void
//===========================================================================
void AlienGroup::move()
{
	list<Alien>::iterator iter;
	for (iter = alienHerd.begin(); iter != alienHerd.end(); iter++)
	{
		iter->move(); // moves the alien
	}
}

//===========================================================================
//addBombfromAlien: adds a bomb to the bombs list using the position of the alien
// parameters:
//	headBomb: main bombs variable passed by reference to hold the bombs being addded
// numAliens: passes the number of aliens there are in the list of aliens
// return type: void
//===========================================================================
void AlienGroup::addBombfromAlien(Bombs &headBomb, int numAliens)
{

	bool found = false;
	int rando = rand() % numAliens + 1;
	int iterCount = 1;
	list<Alien>::iterator iter;
	for (iter = alienHerd.begin(); iter != alienHerd.end() && !found; iter++)
	{		
		if (iterCount == rando)
		{
			headBomb.addBomb(iter->getPosition());
			found = true; // if the alien that is being dropped from is found, quit the loop
		}
		iterCount++;
	}	
}

//===========================================================================
//getSprite: returns a vector of positions of all the aliens in the list
// parameters:
//	N/A
// return type: vector<Vector2f>
//===========================================================================
vector<Vector2f> AlienGroup::getVector2fPos()
{
	vector<Vector2f> temp;
	int i = 0;
	list<Alien>::iterator iter;
	for (iter = alienHerd.begin(); iter != alienHerd.end(); iter++)
	{
		temp.push_back(iter->getPosition()); // puts the locations of the aliens in the vector
	}

	return temp;
}

//===========================================================================
//resetPosition: resets the position of all the aliens in the list if the ship is hit by a bomb
// parameters:
//	N/A
// return type: void
//===========================================================================
void AlienGroup::resetPosition()
{

	int i = 0;
	list<Alien>::iterator iter;
	for (iter = alienHerd.begin(); iter != alienHerd.end(); iter++)
	{
		Vector2f temp = iter->getPosition();
		temp.y = 50;
		iter->setPosition(temp.x, temp.y); // sets the position of the current alien
		
	}
	
}