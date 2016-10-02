#ifndef __Game__ 
#define __Game__

#pragma once

#include "TextureManager.h"
#include <SDL.h>

class Game {
	public:
	   ~Game();
	   bool init(const char* title, int height, int width, int flags);
	   void update();
	   void draw();
	   void handleEvents();
	   void clean();
	   bool isRunning() { return running; }
	   void setRunning(bool value) { running = value; }

	   SDL_Renderer* getRenderer() const { return renderer; }

	   static Game* instance() 
	   {
		   if (Instance == 0)
		   { 
			   Instance = new Game();
			   return Instance;
		   }
		   return Instance;
	   }

	private:
		Game();
		static Game* Instance;

		typedef TextureManager TheTextureManager;
		bool running;
		const Uint8 *keystates;
		
		SDL_Window*		window;
		SDL_Renderer* renderer;
		SDL_Event		 event;
		SDL_AudioSpec obtained;
};

#endif