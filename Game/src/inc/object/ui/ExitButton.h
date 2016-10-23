#ifndef __ExitButton__
#define __ExitButton__

#include "Button.h"

class ExitButton : public Button
{
	public:
		
		ExitButton() : Button() {};
		virtual ~ExitButton() {};

		virtual int type() { return GameObject::ObjectType::EXITBUTTON; }

};

class ExitButtonCreator : public BaseCreator 
{ 
	GameObject* createGameObject() const 
	{ 
		return new ExitButton(); 
	} 
};

#endif