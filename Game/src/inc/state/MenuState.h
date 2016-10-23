#ifndef __MenuState__
#define __MenuState__

#include "GameState.h"
#include "GameObject.h"

class MenuState : GameState
{
	public:

		virtual bool onEnter();
		virtual bool onExit();

		virtual int getStateID() const { return s_menuID; }

	private:

		// callback functions for button clicks
		static void s_menuToPlay();
		static void s_exitFromMenu();

		static const int s_menuID;
};

#endif