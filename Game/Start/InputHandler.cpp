#include "stdafx.h"
#include "InputHandler.h"
#include "Game.h"
#include <iostream>

InputHandler* InputHandler::Instance = 0;

InputHandler::InputHandler()
{
	for (int i = 0; i < 3; i++) 
	{ 
		mouseButtonStates.push_back(false); 
	}
	mousePosition = new Vector2D(0, 0);
}

void InputHandler::update()
{
	SDL_Event event;
	keystates = SDL_GetKeyboardState(0);

	while (SDL_PollEvent(&event))
	{
		switch (event.type) 
		{
			case SDL_QUIT:      TheGame::instance()->quit();    
				break;
			case SDL_MOUSEMOTION:      
				onMouseMove(event);    
				break;
			case SDL_MOUSEBUTTONDOWN:      
				onMouseButtonDown(event);    
				break;
			case SDL_MOUSEBUTTONUP:      
				onMouseButtonUp(event);   
				break;
			case SDL_KEYDOWN:      
				onKeyDown();    
				break;
			case SDL_KEYUP:      
				onKeyUp();    
				break;
			default:    
				break;
		}
	}
}

void InputHandler::onKeyDown()
{
	if (isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::instance()->quit();
	}
}

void InputHandler::onKeyUp()
{

}

void InputHandler::onMouseMove(SDL_Event& event)
{
	mousePosition->setX(event.motion.x);
	mousePosition->setY(event.motion.y);
}

void InputHandler::onMouseButtonDown(SDL_Event& event) 
{
	if (event.button.button == SDL_BUTTON_LEFT)   { mouseButtonStates[LEFT]   = true; }
	if (event.button.button == SDL_BUTTON_MIDDLE) { mouseButtonStates[MIDDLE] = true; }
	if (event.button.button == SDL_BUTTON_RIGHT)  { mouseButtonStates[RIGHT]  = true; }
}

void InputHandler::onMouseButtonUp(SDL_Event& event)
{
	if (event.button.button == SDL_BUTTON_LEFT)   { mouseButtonStates[LEFT]   = false; }
	if (event.button.button == SDL_BUTTON_MIDDLE) { mouseButtonStates[MIDDLE] = false; }
	if (event.button.button == SDL_BUTTON_RIGHT)  { mouseButtonStates[RIGHT]  = false; }
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
	if (keystates != 0) 
	{ 
		if (keystates[key] == 1) 
		{ 
			return true; 
		} 
		else 
		{ 
			return false; 
		} 
	}
	return false;
}

void InputHandler::clean()
{

}