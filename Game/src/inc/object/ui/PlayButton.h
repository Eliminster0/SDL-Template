#ifndef __PlayButton__
#define __PlayButton__

#include "Button.h"

class PlayButton : public Button
{
	public:

		PlayButton() : Button() {};
		virtual ~PlayButton() {};

		virtual int type() { return GameObject::ObjectType::PLAYBUTTON; }

};

class PlayButtonCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new PlayButton();
	}
};

#endif