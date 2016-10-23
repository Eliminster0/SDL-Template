#ifndef __GameState__
#define __GameState__

#include <string>
#include <vector>
#include "StateParser.h"
#include "Callback.h"

class GameState
{
	public:
    
		enum State : int
		{
			MENUSTATE = 101,
			PLAYSTATE = 102
		};

		virtual ~GameState() {}
    
		virtual void update();
		virtual void render();
    
		virtual bool onEnter() = 0;
		virtual bool onExit() = 0;
    
		virtual int getStateID() const = 0;
    
		virtual void resume() {}
    
	protected:
    
		GameState() : 
			m_loadingComplete(false), 
			m_exiting(false)
		{
        }
    
		bool m_loadingComplete;
		bool m_exiting;

		typedef void(*Callback)();  
		virtual void setCallbacks(const std::vector<Callback>& callbacks);
		
		std::vector<Callback> m_callbacks;
		std::vector<GameObject*> m_gameObjects;
		std::vector<std::string> m_textureIDList;
};

#endif
