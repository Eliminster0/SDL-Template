#include "stdafx.h"
#include "Game.h"

// initialize the game to zero
// the instance function will then 
// create the game
Game* Game::Instance = NULL;

// update function
// update the logical parts of the game objects
void Game::update() 
{
	/*--------------------------UPDATE HERE-------------------------*/
	

	/*--------------------------UPDATE HERE-------------------------*/
}

// draw function
// draw all the updated game objects
void Game::draw()
{
	// Set the current color
	SDL_SetRenderDrawColor(renderer, 55, 0, 100, 255);

	// Clear the screen
	SDL_RenderClear(renderer);

	/*---------------------------DRAW HERE--------------------------*/

	
	/*---------------------------DRAW HERE--------------------------*/

	// Up until now everything was drawn behind the scenes.
	// This will show the new, red contents of the window.
	SDL_RenderPresent(renderer);
}

// handle events functions
// get the user inputs and handle them accordingly
void Game::handleEvents()
{
	TheInputHandler::instance()->update();
}

// initialization function
// start up subsystems and load assests
bool Game::init(const char* title, int height, int width, int flags)
{
	// Initialize SDL.
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return false;

	// Create the window where we will draw.
	window = SDL_CreateWindow(title,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		height, width, flags);

	// We must call SDL_CreateRenderer in order for draw calls to affect this window.
	renderer = SDL_CreateRenderer(window, -1, 0);

	/*---------------------------LOAD HERE--------------------------*/


	/*---------------------------LOAD HERE--------------------------*/

	return true;
}

// clean up function
// release the allocations
void Game::clean() 
{
	TheInputHandler::instance()->clean();

	SDL_DestroyWindow(window);  
	SDL_DestroyRenderer(renderer);

	//Quit SDL 
	SDL_Quit();
}

void Game::start()
{
	// if the game was successfully started
	if (init("Game", 800, 400, 0))
		// allow the program to enter 
		// the game loop
		setRunning(true);
	else
		// if not the skip over 
		// the game loop
		setRunning(false);
}