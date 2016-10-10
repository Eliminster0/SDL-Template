#ifndef __Camera__
#define __Camera__

#include <iostream>
#include "Vector2D.h"

class Camera
{
    public:
    
		// handle to access member functions
		static Camera* Instance()
		{
			// we don't have a camera
			if(s_pCamera == 0)
			{
				// create one
				s_pCamera = new Camera();
			}
			// return the camera
			return s_pCamera;
		}
    
		// update camera
		void update(Vector2D velocity);
    
		// fix the camera to a target
		void setTarget(Vector2D* target) { m_pTarget = target; }

		// set xy coordinates of camera
		void setPosition(const Vector2D& position) { m_position = position; }
    
		// where in the world is? Camera San Diego... 
		const Vector2D getPosition() const;
    
    private:
		
		// private constructor/destructor
		Camera();
		~Camera();
    
		// the camera's target
		Vector2D* m_pTarget;
    
		// the camera's position
		Vector2D m_position;
    
		// pointer to the camera object
		static Camera* s_pCamera;
};

typedef Camera TheCamera;

#endif
