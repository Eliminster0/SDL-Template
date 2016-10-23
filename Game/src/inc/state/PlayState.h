#ifndef __PlayState__
#define __PlayState__

#include "GameState.h"

class PlayState : GameState
{
	public:

		virtual bool onEnter();
		virtual bool onExit();

		virtual int getStateID() const { return s_playID; }
	
	private:

		static const int s_playID;
};

#endif