#ifndef __Button__ 
#define __Button__

#include "GameObject.h"
#include "GameObjectFactory.h"

class Button : public GameObject
{
	public:
		
		enum button_state
		{
			MOUSE_OUT = 0, 
			MOUSE_OVER = 1, 
			CLICKED = 2
		};

		virtual void load(std::unique_ptr<LoaderParams> const &pParams);
		virtual void draw();
		virtual void update();

		void setCallback(void(*callback)()) { m_callback = callback; } 
		int getCallbackID() { return m_callbackID; }

		virtual void clean() {};
		virtual void collision() {};
		
		virtual int type() = 0;

		// base class needs virtual destructor
		virtual ~Button() {}

	protected:

		Button() : GameObject(), 
				m_currentFrame(Button::button_state::MOUSE_OUT),
				m_bReleased(true)
		{
		}
		
		bool m_bReleased;

		int m_currentFrame;
		int m_callbackID;
		void(*m_callback)();
};

#endif