#include "Game.h"
#include "GameState.h"
#include "GameObjectFactory.h"
#include "PlayButton.h"
#include "ExitButton.h"
#include "MenuState.h"
#include "PlayState.h"


// initialize the game to zero
// the instance function will then 
// create the game
Game* Game::s_pInstance = NULL;


// start function
void Game::start()
{
	// if the game was successfully started
	if (init())
		// allow the program to enter 
		// the game loop
		setRunning(true);
	else
		// if not the skip over 
		// the game loop
		setRunning(false);
}


// update function
// update the logical parts of the game objects
void Game::update() 
{
	/*--------------------------UPDATE HERE-------------------------*/
	m_pGameStateMachine->update();
	/*--------------------------UPDATE HERE-------------------------*/
}


// draw function
// draw all the updated game objects
void Game::draw()
{
	// Set the current color
	SDL_SetRenderDrawColor(renderer, 10, 50, 75, 255);

	// Clear the screen
	SDL_RenderClear(renderer);

	/*---------------------------DRAW HERE--------------------------*/
	m_pGameStateMachine->render();
	/*---------------------------DRAW HERE--------------------------*/

	// Up until now everything was drawn behind the scenes.
	// This will show the new, red contents of the window.
	SDL_RenderPresent(renderer);
}


// handle events functions
// get the user inputs and handle them accordingly
void Game::handleEvents()
{
	TheInputHandler::Instance()->update();

	// TODO add this to input handler.	
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)) 
	{ 
		//m_pGameStateMachine->changeState((GameState*)new PlayState());
	}
}


// initialization function
// start up subsystems and load assests
bool Game::init()
{
	// Initialize SDL.
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return false;

	if (!setDefaultResolution())
		return false;

	/*---------------------------LOAD HERE--------------------------*/
	TheGameObjectFactory::Instance()->registerType
		(GameObject::ObjectType::PLAYBUTTON, new PlayButtonCreator());
	TheGameObjectFactory::Instance()->registerType
		(GameObject::ObjectType::EXITBUTTON, new ExitButtonCreator());
	
	/*---------------------------LOAD HERE--------------------------*/
	

	/*------------------------START THE GAME------------------------*/
	m_pGameStateMachine = new GameStateMachine(); 
	m_pGameStateMachine->changeState((GameState*)new MenuState());
	
	return true;
}


// clean up function
// release the memory allocations
void Game::clean() 
{
	// release any resource allocation for the controllers
	TheInputHandler::Instance()->clean();

	// release any state information
	m_pGameStateMachine->clean();

	// set the pointer to null
	m_pGameStateMachine = 0;
	// delete the pointer
	delete m_pGameStateMachine;

	// clear all of the texture that were loaded
	TheTextureManager::Instance()->clearTextureMap();

	// release the resource allocation for the screen and renderer
	SDL_DestroyWindow(window);  
	SDL_DestroyRenderer(renderer);

	//Quit SDL 
	SDL_Quit();
}


bool Game::setDefaultResolution()
{

	int i;

	// Declare display mode structure to be filled in.
	SDL_DisplayMode current;

	// Get current display mode of all displays.
	for (i = 0; i < SDL_GetNumVideoDisplays(); ++i) 
	{

		int should_be_zero = SDL_GetCurrentDisplayMode(i, &current);

		if (should_be_zero != 0)
			// In case of error...
			SDL_Log("Could not get display mode for video display #%d: %s", i, SDL_GetError());

		else
			// On success, print the current display mode.
			SDL_Log("Display #%d: current display mode is %dx%dpx @ %dhz.", i, current.w, current.h, current.refresh_rate);
	}

	// Create the window where we will draw.
	window = SDL_CreateWindow("Game", 
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		0, 0,
		SDL_WINDOW_MAXIMIZED);

	// We must call SDL_CreateRenderer in order for draw calls to affect this window.
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	// store the screen width and height
	m_gameWidth  = current.w;
	m_gameHeight = current.h;

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");  // make the scaled rendering look smoother.
	SDL_RenderSetLogicalSize(renderer, 1920, 1080);

	return true;
}