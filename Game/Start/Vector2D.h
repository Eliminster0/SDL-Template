#ifndef __Vector2D__
#define __Vector2D__

#pragma once
#include<math.h> 

class Vector2D 
{ 
	public:  

		// constructor
		Vector2D(float x, float y): x(x), y(y) {}

		// find the length of the vector
		float length() { return sqrt(x * x + y * y); }

		// operator overloading
		
		// adding two vectors 
		// this vector appears as the left operand
		Vector2D operator+(const Vector2D& v2) const { return Vector2D(x + v2.x, y + v2.y); }
		
		// adding two vectors 
		// this vector can be the right operand
		// friend is required to access the private member variables
		friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2) 
		{
			v1.x += v2.x;  v1.y += v2.y;
			return v1;
		}

		// subtracting two vectors 
		// this vector appears as the left operand
		Vector2D operator-(const Vector2D& v2) const { return Vector2D(x - v2.x, y - v2.y); }

		// subtracting two vectors 
		// this vector can be the right operand
		// friend is required to access the private member variables
		friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2) 
		{
			v1.x -= v2.x;  v1.y -= v2.y;
			return v1;
		}

		// scalar multiplication
		Vector2D operator*(float scalar) { return Vector2D(x * scalar, y * scalar); }

		// scalar multiplication
		// *= operation (i.e. vector *= 2)
		Vector2D& operator*=(float scalar) 
		{
			x *= scalar;  y *= scalar;
			return *this;
		}

		// scalar division
		Vector2D operator/(float scalar) { return Vector2D(x / scalar, y / scalar); }
		
		// scalar division
		// /= operation (i.e. vector /= 2)
		Vector2D& operator/=(float scalar) 
		{
			x /= scalar;  y /= scalar;
			return *this;
		}

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
		float getX() { return x; }  
		float getY() { return y; }
		
		// setters
		void setX(float x) { this->x = x; }  
		void setY(float y) { this->y = y; }

	private:

		float x;
		float y;
		
};

#endif