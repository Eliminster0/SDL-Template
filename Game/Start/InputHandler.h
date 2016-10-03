#ifndef __InputHandler__
#define __InputHandler__

#pragma once
#include <SDL.h>
#include <vector>
#include "Vector2D.h"

enum mouse_buttons 
{ 
	LEFT = 0, 
	MIDDLE = 1, 
	RIGHT = 2 
};

class InputHandler {
	public:  
		
		void update();  
		void clean();
		 
		bool getMouseButtonState(int buttonNumber) { return mouseButtonStates[buttonNumber]; }
		
		Vector2D* getMousePosition() { return mousePosition; }

		bool isKeyDown(SDL_Scancode key);


		static InputHandler* instance() 
		{
			if (Instance == 0) 
			{ 
				Instance = new InputHandler(); 
			}
			return Instance;
		}

	private:
	
		InputHandler();  
	   ~InputHandler() {}
		static InputHandler* Instance;

		// pointer for mouse pointer
		Vector2D* mousePosition;

		// pointer for user input
		const Uint8* keystates;

		// vector to hold mouse button states
		std::vector<bool> mouseButtonStates;

		void onKeyDown(); 
		void onKeyUp();

		void onMouseMove(SDL_Event& event); 
		void onMouseButtonDown(SDL_Event& event); 
		void onMouseButtonUp(SDL_Event& event);
}; 

typedef InputHandler TheInputHandler;

#endif


