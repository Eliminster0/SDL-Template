// Start.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <SDL.h>


	SDL_Window* window;
	SDL_Renderer* renderer;
	const Uint8 *keystates;
	SDL_Event event;

	SDL_AudioSpec obtained;


int _tmain(int argc, _TCHAR* argv[])
{

		
	// Initialize SDL.
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return 1;

	// Create the window where we will draw.
	window = SDL_CreateWindow("Hello",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		800, 400,
		0);

	// We must call SDL_CreateRenderer in order for draw calls to affect this window.
	renderer = SDL_CreateRenderer(window, -1, 0);

	keystates = SDL_GetKeyboardState( NULL );

	
	// Set the current color
	SDL_SetRenderDrawColor(renderer, 55, 0, 100, 255);

	// Clear the screen
	SDL_RenderClear(renderer);

	// Up until now everything was drawn behind the scenes.
	// This will show the new, red contents of the window.
	SDL_RenderPresent(renderer);

	// Give us time to see the window.
	SDL_Delay(5000);


	//Quit SDL 
	SDL_Quit(); 

	return 0;
}


