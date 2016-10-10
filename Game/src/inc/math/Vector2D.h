#ifndef __Vector2D__
#define __Vector2D__

#include<math.h> 

class Vector2D 
{ 
	public:  

		// default constructor
		Vector2D()
		{
			m_x = 0;
			m_y = 0;
		}

		// xy coordinates
		float m_x;
		float m_y;

		// constructor
		Vector2D(float x, float y): m_x(x), m_y(y) {}

		// find the length of the vector
		float length() { return sqrt(m_x * m_x + m_y * m_y); }

		// normalize vector to a unit vector
		void normalize()
		{
			float l = length();
			// we never want to attempt to divide by 0  
			if (l > 0)
			{
				(*this) *= 1 / l;
			}
		}

		// getters
		float getX() { return m_x; }
		float getY() { return m_y; }

		// setters
		void setX(float x) { this->m_x = x; }
		void setY(float y) { this->m_y = y; }

		/*----- operator overloading -----*/
		
		// adding two vectors 
		// this vector appears as the left operand
		Vector2D operator+(const Vector2D& v2) const { return Vector2D(m_x + v2.m_x, m_y + v2.m_y); }
		
		// adding two vectors 
		// this vector can be the right operand
		// friend is required to access the private member variables
		friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2) 
		{
			v1.m_x += v2.m_x;  v1.m_y += v2.m_y;
			return v1;
		}

		// subtracting two vectors 
		// this vector appears as the left operand
		Vector2D operator-(const Vector2D& v2) const { return Vector2D(m_x - v2.m_x, m_y - v2.m_y); }

		// subtracting two vectors 
		// this vector can be the right operand
		// friend is required to access the private member variables
		friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2) 
		{
			v1.m_x -= v2.m_x;  v1.m_y -= v2.m_y;
			return v1;
		}

		// scalar multiplication
		Vector2D operator*(float scalar) { return Vector2D(m_x * scalar, m_y * scalar); }

		// scalar multiplication
		// *= operation (i.e. vector *= 2)
		Vector2D& operator*=(float scalar) 
		{
			m_x *= scalar;  m_y *= scalar;
			return *this;
		}

		// scalar division
		Vector2D operator/(float scalar) { return Vector2D(m_x / scalar, m_y / scalar); }
		
		// scalar division
		// /= operation (i.e. vector /= 2)
		Vector2D& operator/=(float scalar) 
		{
			m_x /= scalar;  m_y /= scalar;
			return *this;
		}
};

#endif