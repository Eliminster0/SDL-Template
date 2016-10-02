#ifndef __LoaderParams__
#define __LoaderParams__

#pragma once

class LoaderParams {
	public:
		
		LoaderParams(
			int x, 
			int y, 
			int width, 
			int height, 
			char* textureID) 
			: 
			x(x), 
			y(y), 
			width(width), 
			height(height), 
			textureID(textureID) { }
		
		int getX() const { return x; }  
		int getY() const { return y; }  
		int getWidth() const { return  width;  }  
		int getHeight() const { return height; }  
		char* getTextureID() const { return textureID; }
	private:
		
		int x;  
		int y;
		
		int width;  
		int height;
		
		char* textureID;
};

#endif