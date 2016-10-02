#include "stdafx.h"
#include "Game.h"

Game* Game::Instance = 0;

Game::Game() 
{
	if (init("Game", 800, 400, 0))
		setRunning(true);
	else
		setRunning(false);

	while (isRunning())
	{
		update();
		draw();

		// Give us time to see the window.
		SDL_Delay(5000);
		setRunning(false);
	}

	clean();
}

void Game::update() 
{
	
}

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

void Game::handleEvents()
{
	keystates = SDL_GetKeyboardState(NULL);
	
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				setRunning(false);
				break;
			default:
				break;
		}
	}
}


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

void Game::clean() 
{
	SDL_DestroyWindow(window);  
	SDL_DestroyRenderer(renderer);
	
	//Quit SDL 
	SDL_Quit();
}