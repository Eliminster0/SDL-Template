#ifndef __Game__ 
#define __Game__

#pragma once

#include "TextureManager.h"
#include "InputHandler.h"
#include <iostream>
#include <SDL.h>

// constant for frame rate ( 60 frames per second )
const int FPS = 60; 

// constant for amount of milliseconds a frame should be ( 16.7ms )
const int DELAY_TIME = 1000.0f / FPS;

class Game {
	public:
	      
	   // initialize the game
	   bool init(const char* title, int height, int width, int flags);
	   
	   // update game objects
	   void update();
	   
	   // draw the game objects
	   void draw();

	   // handle user input
	   void handleEvents();
	   
	   // clean up
	   void clean();

	   // quit game
	   void quit() { setRunning(false); }

	   // start the game
	   void start();

	   // check is game is still running
	   bool isRunning() { return running; }

	   // set flag for game loop
	   void setRunning(bool value) { running = value; }

	   // set the current time at the top of the frame
	   void setFrameStart(Uint32 time) { frameStart = time; }
	   
	   //get the delta time between frames
	   void setFrameTime(Uint32 time) { frameTime = time; }

	   // get the frame start time
	   Uint32 getFrameStart() { return frameStart;  }
	   
	   // get the delta time
	   Uint32 getFrameTime() { return frameTime; }

	   // get the renderer for drawing objects
	   SDL_Renderer* getRenderer() const { return renderer; }

	   // handle for access to the game components
	   static Game* instance() 
	   {
		   if (Instance == NULL)
		   { 
			   Instance = new Game();
			   return Instance;
		   }
		   return Instance;
	   }

	private:
		
		// private constructor for singleton
		Game() {}

		// pointer to the game object
		static Game* Instance;
		
		// flag to control game loop
		bool running;

		// frame start time
		Uint32 frameStart;
		
		// frame delta time
		Uint32 frameTime;
		
		// pointer to window object
		SDL_Window*	window;

		// pointer to renderer object
		SDL_Renderer* renderer;

		SDL_AudioSpec obtained;
};

typedef Game TheGame;

#endif