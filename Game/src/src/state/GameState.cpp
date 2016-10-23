#include "GameState.h"
#include "Button.h"


void GameState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}


void GameState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}


void GameState::setCallbacks(const std::vector<Callback>& callbacks)
{
	// go through the game objects  
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		// if they are of type MenuButton then assign a callback     
		// based on the id passed in from the file    
		if (dynamic_cast<Button*>(m_gameObjects[i]))
		{
			Button* pButton = dynamic_cast<Button*>(m_gameObjects[i]);
			pButton->setCallback(callbacks[pButton->getCallbackID()]);
		}
	}
}