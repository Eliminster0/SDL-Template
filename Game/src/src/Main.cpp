#include "Game.h"
#include <iostream>


int main(int argc, char* args[])
{
	// call the game so it will start itself
	TheGame::Instance()->start();

	// the game loop
	while (TheGame::Instance()->isRunning())
	{
		// get the current time at 
		// the top of the frame
		TheGame::Instance()->setFrameStart(SDL_GetTicks());

		// handle user input
		TheGame::Instance()->handleEvents();

		// update game objects
		TheGame::Instance()->update();

		// draw game objects
		TheGame::Instance()->draw();

		//set the delta time between frames
		TheGame::Instance()->setFrameTime
		(SDL_GetTicks() - TheGame::Instance()->getFrameStart());

		// if the frame took less than 
		// 16.7 milliseconds to update
		if (TheGame::Instance()->getFrameTime()< DELAY_TIME)
		{
			// then wait to start next frame
			SDL_Delay((int)(DELAY_TIME - TheGame::Instance()->getFrameTime()));
		}
	}

	TheGame::Instance()->clean();

	// the game is done, end the program
	return 0;
}