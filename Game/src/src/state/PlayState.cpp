#include "PlayState.h"
#include "SDL.h"
#include "Game.h"
#include <iostream>


const int PlayState::s_playID = GameState::State::PLAYSTATE;


bool PlayState::onEnter() 
{ 
	std::cout << "entering PlayState\n";

	StateParser stateParser;
	stateParser.parseState(
		"../src/res/xml/state.xml",
		s_playID,
		&m_gameObjects,
		&m_textureIDList);

	//pushback 0 callbackID start from 1 
	m_callbacks.push_back(0);

	// set the callbacks for menu items  
	setCallbacks(m_callbacks);
	
	return true; 
}


bool PlayState::onExit() 
{
	std::cout << "exiting PlayState\n";  
	return true; 
}