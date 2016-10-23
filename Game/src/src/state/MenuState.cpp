#include "MenuState.h"
#include "PlayState.h"
#include <iostream>

const int MenuState::s_menuID = GameState::State::MENUSTATE;
	

bool MenuState::onEnter() 
{ 
	std::cout << "entering MenuState\n";
	
	StateParser stateParser;  
	stateParser.parseState(
		"../src/res/xml/state.xml", 
		s_menuID, 
		&m_gameObjects, 
		&m_textureIDList);
	
	//pushback 0 callbackID start from 1 
	m_callbacks.push_back(0); 

	// index 1 : therefore the callbackID attribute must be set to 1 to implement this function
	m_callbacks.push_back(s_menuToPlay);
	// index 2 : therefore the callbackID attribute must be set to 2 to implement this function
	m_callbacks.push_back(s_exitFromMenu);

	// set the callbacks for menu items  
	setCallbacks(m_callbacks);
	
	return true; 
}


bool MenuState::onExit() 
{ 
	m_exiting = true;

	// clean the game objects
	if (m_loadingComplete && !m_gameObjects.empty())
	{
		m_gameObjects.back()->clean();
		m_gameObjects.pop_back();
	}

	m_gameObjects.clear();

	// clear the texture manager
	for(int i = 0; i < m_textureIDList.size(); i++)
	{
		TheTextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
	}
	
	// reset the input handler
	TheInputHandler::Instance()->reset();

	std::cout << "exiting MenuState\n";  
	return true; 
}


void MenuState::s_menuToPlay() 
{ 
	std::cout << "Play button clicked\n"; 
	TheGame::Instance()->getStateMachine()->changeState((GameState*)new PlayState());
}


void MenuState::s_exitFromMenu() 
{ 
	std::cout << "Exit button clicked\n";
	TheGame::Instance()->quit();
}