//====================================================================
// Joshua Murray
// Due Friday, April 19
// Programming II: Assigment #8
// Description: Create a program that is the simplified version of "Space Invaders."
// 
//====================================================================

#include "Alien.h"
#include "AlienGroup.h"
#include "Missile.h"
#include "Ship.h"
#include "UI.h"
#include "Bombs.h"
#include "missileHolder.h"
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf; 


int main()
{
	srand(time(NULL)); // calling this allows randow numbers to be used
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600; // setting the window length and width

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");
	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	// Gameplay variables
	Bombs headBomb; 
	AlienGroup enemies;
	enemies.setTexture();
	missileHolder clip;
	Ship ship;
	ship.setTexture();
	ship.setPosition();
	UI userInter;
	userInter.setBackground();


	int count = 0; // var to hold the users score /100

	bool startFirst = false; // bool to represent currently being on lvl one
	bool startSecond = false; // bool to represent currently being on lvl two
	bool end = false; // bool to represent finishing the game and winning
	bool dead = false; // bool to represent losing the game
	bool alienTake = false; // bool to represent the aliens passing the edge of the screen

	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		// For now, we just need this so we can click on the window and close it
		Event event;

		window.draw(userInter.getBack());


		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Space)
				{

					if (startFirst || startSecond) // if space is pressed, add a missile to the clip var
					{
						Vector2f pos = ship.getPosition();
						pos.x += 3;
						pos.y -= 8;
						clip.addMiss(pos); // adds a missile
					}
				}
			}
		}


		if (!startFirst && !end && !dead && !startSecond) // while every variable is false, will display start screen
		{
			window.draw(userInter.getBack());
			userInter.startScreen(window);
			if (event.type == Event::MouseButtonReleased)
			{
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
				if (userInter.getSGB().contains(mousePos)) // if the mouse button is released while over the start button, it will begin the game
				{
					startFirst = true;
				}
			}
			window.display();
		}

		else if (startFirst || startSecond)
		{
			window.draw(userInter.getBack()); // draw the background
			userInter.lifeScore(window, count * 100); // display the current score of the game
			ship.moveShip();

			// draw the ship on top of background 
			// (the ship from previous frame was erased when we drew background)
			window.draw(ship.getSprite());

			//window.draw(enemies.getTexture());
			
			enemies.drawAliens(window, startSecond);
			enemies.move(); // move the enemies

			headBomb.moveAllBombs(); // move the bombs
			
			int rando;
			if (startFirst) // how often bombs drop in lv one
				rando = rand() % 20 + 1;
			else if (startSecond) // how often bombs drop in lv two
				rando = rand() % 10 + 1;
			if (rando == 1 && enemies.numofAliens() != 0)
				enemies.addBombfromAlien(headBomb, enemies.numofAliens()); // add a bomb to the head bomb list using the alien
			headBomb.dropBombBomb();
			headBomb.drawBombs(window); // draw the bombs onto the window
			
			if (headBomb.hitShip(ship.getGlobalBounds())) // if the ship is hit by a bomb, lose a life, delete the bomb that hit it, and reset the aliens positions
			{
				userInter.setLives();
				headBomb.hitShipDelete(ship.getGlobalBounds());
				enemies.resetPosition();
			}


			clip.drawMiss(window); // draw the missiles onto the window
			if (clip.getNumMissile() != 0) // if there is a missile on screen
			{
				clip.moveAllMiss(); // move missiles
				clip.deleteMissiles(); // delete missiles that are off screen

				
				int i = 0;
				int numAliens = enemies.numofAliens();
				vector<FloatRect> missileBounds = clip.getGlobalbounds(); // vector to hold the location of all missiles
				vector<FloatRect> enemyBounds = enemies.getGlobalbounds(); // vector to hold the location of all aliens
				vector<Vector2f> temp = enemies.getVector2fPos();
				while (numAliens > 0)
				{
					for (int p = 0; p < clip.getNumMissile() && !alienTake; p++)
					{
						if (missileBounds[p].intersects(enemyBounds[i])) // if a missile hits an alien, delete the alien, missile, and increase score
						{
							FloatRect tempPos = enemyBounds[i];
							enemies.killAlien(missileBounds[p]);
							clip.missileHitAlien(tempPos);
							count++;
							
						}
					}
					numAliens--;
					i++;
				}
				
			} // end body of animation loop
			vector<Vector2f> temp = enemies.getVector2fPos();
			for (int i = 0; i < enemies.numofAliens(); i++)// if an alien is off the screen, lose game
			{
				if (temp[i].y > 580)
				{
					alienTake = true; 

				}
			}
			if (count == 10 && startFirst) // if you kill all 10 aliens of lv one, reset the ships pos, and create and draw new enemies
			{
				startFirst = false;
				startSecond = true;
				ship.setPosition();
				enemies.reset();
			}
			else if (count == 20 && startSecond) // if you kill all the aliens in lv two, display the win screen
			{
				startSecond = false;
				end = true;
			}
			else if (userInter.getLives() == 0 || alienTake) // if you run out of lives or an alien makes it off the map, you lose
			{
				startFirst = false;
				startSecond = false;
				dead = true;
			}

			window.display(); // display everything
		}

		else if (end) // display the win screen
		{
			window.draw(userInter.getBack());
			userInter.winner(window);
			window.display();
		}

		else if (dead) // display the death screen
		{
			window.draw(userInter.getBack());
			userInter.dead(window);
			window.display();
		}
	}
	return 0;
}