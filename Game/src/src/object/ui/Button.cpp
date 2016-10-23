#include "Button.h"


void Button::load(std::unique_ptr<LoaderParams> const &pParams)
{
	// get position
	m_position = Vector2D(pParams->getX(), pParams->getY());

	// get drawing variables
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextureID();
	m_numFrames = pParams->getNumFrames();

	m_callbackID = pParams->getCallbackID();
}


void Button::draw()
{
	TextureManager::Instance()->drawFrame(
		m_textureID,
		(Uint32)m_position.getX(),
		(Uint32)m_position.getY(),
		m_width,
		m_height,
		m_currentRow,
		m_currentFrame,
		TheGame::Instance()->getRenderer(),
		m_angle,
		m_alpha);
}


void Button::update()
{
	Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();

	if (pMousePos->getX() < (m_position.getX() + m_width)
		&& pMousePos->getX() > m_position.getX()
		&& pMousePos->getY() < (m_position.getY() + m_height)
		&& pMousePos->getY() > m_position.getY())
	{
		m_currentFrame = MOUSE_OVER;
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT) && m_bReleased)
		{
			// set the state of the button to clicked
			m_currentFrame = CLICKED;
			// call the function that was assinged to the button
			if (m_callback != 0)
			{
				m_callback();
			}

			m_bReleased = false;

		}
		else if (!TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			m_bReleased = true;
			m_currentFrame = MOUSE_OVER;
		}
	}
	else
	{
		m_currentFrame = MOUSE_OUT;
	}
}