#ifndef __Game__ 
#define __Game__

#include "TextureManager.h"
#include "GameStateMachine.h"
#include "InputHandler.h"
#include <SDL.h>
#include <iostream>

// constant for frame rate ( 60 frames per second )
const int FPS = 60; 

// constant for amount of milliseconds a frame should be ( 16.7ms )
const int DELAY_TIME = 1000.0f / FPS;

class Game 
{
	public:

	   // initialize the game
	   bool init();
	   
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

	   // get the screen width
	   int getGameWidth() const { return m_gameWidth; } 
	   
	   // get the screen height
	   int getGameHeight() const { return m_gameHeight; }

	   // get the renderer for drawing objects
	   SDL_Renderer* getRenderer() const { return renderer; }

	   // get the game state handler for changing the state of the game
	   GameStateMachine* getStateMachine() { return m_pGameStateMachine; }

	   // handle for access to the game components
	   static Game* Instance() 
	   {
		   // if there is currently no game object
		   if (s_pInstance == NULL)
		   { 
			   // create the game object
			   s_pInstance = new Game();
			   // return the object
			   return s_pInstance;
		   }
		   // there is currently a game object
		   // return the the object
		   return s_pInstance;
	   }

	private:
		
		// private constructor for singleton
		Game() {}

		// pointer to the game object
		static Game* s_pInstance;
		
		// flag to control game loop
		bool running;

		// get the display settings and create window
		bool setDefaultResolution();

		// screen width
		int m_gameWidth;

		// screen height
		int m_gameHeight;

		// frame start time
		Uint32 frameStart;
		
		// frame delta time
		Uint32 frameTime;
		
		// pointer to window object
		SDL_Window*	window;

		// pointer to renderer object
		SDL_Renderer* renderer;
		
		// pointer to the game state handler object
		GameStateMachine* m_pGameStateMachine;
		
		SDL_AudioSpec obtained;
};

typedef Game TheGame;

#endif