#include "UI.h"

//===========================================================================
//UI: default constructor for the UI class the sets the number of lives to 3 and sets the font
// parameters:
//	N/A
// return type: N/A
//===========================================================================
UI::UI()
{
	lives = 3;


	if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
		die("couldn't load font");
}

//===========================================================================
//startScreen: draws the title and start button onto the window
// parameters:
//	win: renderwindow variable passed by reference to be drawn on
// return type: void
//===========================================================================
void UI::startScreen(RenderWindow& win)
{

	// title of the game
	Text title("Alien Warfare III", font, 75);
	title.setPosition(138, 100);
	win.draw(title);

	// start button
	Text startButton("START", font, 75);
	startButton.setPosition(300, 300);
	win.draw(startButton);
	startBut = startButton; // setting the private data to the start button
}

//===========================================================================
//winner: displays on the screen that the user beat the game
// parameters:
//	win: renderwindow variable passed by reference to be drawn on
// return type: void
//===========================================================================
void UI::winner(RenderWindow& win)
{
	//title showing that you won
	Text titleWin("YOU WIN", font, 75);
	titleWin.setPosition(138, 100);
	win.draw(titleWin);
}

//===========================================================================
//dead: displays on the screen that the user lost the game
// parameters:
//	win: renderwindow variable passed by reference to be drawn on
// return type: void
//===========================================================================
void UI::dead(RenderWindow& win)
{

	//title showing that you died
	Text titleDead("YOU DIED HAHA", font, 75);
	titleDead.setPosition(138, 100);
	win.draw(titleDead);
}

//===========================================================================
//winner: returns the position of the startbutton
// parameters:
//	N/A
// return type: FloatRect
//===========================================================================
FloatRect UI::getSGB()
{
	return startBut.getGlobalBounds();
}

//===========================================================================
//setBackground: sets the background of the game
// parameters:
//	N/A
// return type: void
//===========================================================================
void UI::setBackground()
{
	if (!starsTexture.loadFromFile("stars.jpg"))
	{
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}

	background.setTexture(starsTexture);
	// The texture file is 640x480, so scale it up a little to cover 800x600 window
	background.setScale(1.5, 1.5);
}

//===========================================================================
//getBack: returns the background sprite
// parameters:
//	N/A
// return type: sprite
//===========================================================================
Sprite UI::getBack()
{
	return background;
}

//===========================================================================
//lifeScore: displays the current life and score of the user
// parameters:
//	win: renderwindow variable passed by reference to be drawn on
//  add: score of the used currently
// return type: void
//===========================================================================
void UI::lifeScore(RenderWindow& win, int add)
{

	//displaying the score lable
	Text scoreTitle("Score: ", font, 20);
	scoreTitle.setPosition(6, 4);
	win.draw(scoreTitle);

	//displays the lives lable
	Text liveTitle("Lives", font, 20);
	liveTitle.setPosition(740, 4);
	win.draw(liveTitle);

	// displays the users current lives
	string livesText = to_string(getLives());
	Text lives(livesText, font, 20);
	lives.setPosition(740, 30);
	win.draw(lives);
	
	// displays the users current score
	string sScore = to_string(add);
	Text scoreAmount(sScore, font, 20);
	scoreAmount.setPosition(8, 30);
	win.draw(scoreAmount);
}

//===========================================================================
//getLives: returns the number of lives the user currently has
// parameters:
//	N/A
// return type: int
//===========================================================================
int UI::getLives()
{
	return lives;
}

//===========================================================================
//setLives: subtracts one live from the lives variable
// parameters:
//	N/A
// return type: void
//===========================================================================
void UI::setLives()
{
	lives--;
}

