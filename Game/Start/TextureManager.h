#ifndef __TextureManager__ 
#define __TextureManager__

#pragma once
#include <string>
#include <SDL.h>
#include <map>

class TextureManager {
	public:
	
		std::map<std::string, SDL_Texture*> textureMap;

		bool load(std::string fileName, 
				  std::string id, 
				  SDL_Renderer* renderer);

		void draw(std::string id, 
				  int x, 
				  int y, 
				  int width, 
			      int  height, 
			      SDL_Renderer* renderer, 
			      SDL_RendererFlip flip = SDL_FLIP_NONE);
		
		void drawFrame(std::string id, 
					   int x, 
					   int y, 
					   int width, 
					   int  height, 
					   int currentRow, 
					   int currentFrame, 
					   SDL_Renderer*  renderer, 
					   SDL_RendererFlip flip = SDL_FLIP_NONE);
		
		static TextureManager* instance() 
		{
			if (Instance == 0) 
			{ 
				Instance = new TextureManager();    
				return Instance; 
			}

			return Instance;
		}

	private:
		static TextureManager* Instance;
		TextureManager() {};
};

// handle to the TextureManager singleton 
typedef TextureManager TheTextureManager;

#endif