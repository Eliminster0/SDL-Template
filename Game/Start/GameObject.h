#ifndef __GameObject__ 
#define __GameObject__

#pragma once
#include <SDL_render.h>
#include "LoaderParams.h"

class GameObject {
	public:
		virtual void draw()	  = 0;
		virtual void update() = 0;
		virtual void clean()  = 0;
	protected:

		GameObject(const LoaderParams* params) {}
		virtual ~GameObject() {};
};

#endif