#include "Game.h"
#include "Camera.h"


// create the camera
Camera* Camera::s_pCamera = new Camera();


// default constructor
// set the camera postion and target 
Camera::Camera() : m_pTarget(0), m_position(0,0)
{
    
}


// we no longer need the camera
Camera::~Camera()
{
	// destroy it
    delete m_pTarget;
}


// get the postion of the camera
const Vector2D Camera::getPosition() const
{
	// if the target is set
    if(m_pTarget != 0)
    {
		// set the position of the camera so that the target is in the center
        Vector2D pos(m_pTarget->m_x - (TheGame::Instance()->getGameWidth() / 2), 0);
        
		// if the camera goes off the screen
        if(pos.m_x < 0)
        {
			// keep the camera inbounds
            pos.m_x = 0;
        }
        
		// return the position
        return pos;
    }
    
	// the camera's position with no target
    return m_position;
    
    
    
//    //Center the camera over the dot
//    camera.x = ( box.x + DOT_WIDTH / 2 ) - SCREEN_WIDTH / 2;
//    camera.y = ( box.y + DOT_HEIGHT / 2 ) - SCREEN_HEIGHT / 2;
//    
//    //Keep the camera in bounds.
//    if( camera.x < 0 )
//    {
//        camera.x = 0;
//    }
//    if( camera.y < 0 )
//    {
//        camera.y = 0;
//    }
//    if( camera.x > LEVEL_WIDTH - camera.w )
//    {
//        camera.x = LEVEL_WIDTH - camera.w;
//    }
//    if( camera.y > LEVEL_HEIGHT - camera.h )
//    {
//        camera.y = LEVEL_HEIGHT - camera.h;
//    }
}


// update the camera's position
void Camera::update(Vector2D velocity)
{
	// add a velocity vector to the current postion
    m_position += velocity;
    
	// if the camera goes off the screen
    if(m_position.m_x < 0)
    {
		// keep the camera inbounds
        m_position.m_x = 0;
    }
}

