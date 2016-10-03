// Start.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"

int _tmain(int argc, _TCHAR* argv[])
{
	// call the game so it will start itself
	TheGame::instance()->start();

	// the game loop
	while (TheGame::instance()->isRunning())
	{
		// get the current time at 
		// the top of the frame
		TheGame::instance()->setFrameStart(SDL_GetTicks());

		// handle user input
		TheGame::instance()->handleEvents();

		// update game objects
		TheGame::instance()->update();

		// draw game objects
		TheGame::instance()->draw();

		//set the delta time between frames
		TheGame::instance()->setFrameTime
			(SDL_GetTicks() - TheGame::instance()->getFrameStart());

		// if the frame took less than 
		// 16.7 milliseconds to update
		if (TheGame::instance()->getFrameTime()< DELAY_TIME)
		{
			// then wait to start next frame
			SDL_Delay((int)(DELAY_TIME - TheGame::instance()->getFrameTime()));
		}
	}

	TheGame::instance()->clean();
	
	// the game is done, end the program
	return 0;
}


