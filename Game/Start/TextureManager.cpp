#include "stdafx.h"
#include "TextureManager.h"
#include "SDL_image.h"

using namespace std;

TextureManager* TextureManager::Instance = 0;

bool TextureManager::load(std::string fileName, std::string  id, SDL_Renderer* renderer)
{

	SDL_Surface* TempSurface = IMG_Load(fileName.c_str());

	if (TempSurface == 0) { return false; }

	SDL_Texture* Texture = SDL_CreateTextureFromSurface(renderer, TempSurface);

	SDL_FreeSurface(TempSurface);

	// everything went ok, add the texture to our list  
	if(Texture != 0)  
	{    
		textureMap[id] = Texture;    
		return true;  
	}

	// reaching here means something went wrong  
	return false; 
} 

void TextureManager::draw(string id, int x, int y, int  width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip) 
{
	SDL_Rect srcRect, destRect;
	
	srcRect.x = 0;  
	srcRect.y = 0;  
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height; 
	
	destRect.x = x;  
	destRect.y = y;
	
	SDL_RenderCopyEx(renderer, textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(string id, int x, int y, int width, int height, int currentRow, 
							   int currentFrame, SDL_Renderer *renderer, SDL_RendererFlip flip) 
{
	SDL_Rect srcRect, destRect;  
	
	srcRect.x = width * currentFrame;  
	srcRect.y = height * (currentRow - 1);  
	srcRect.w = destRect.w = width;  
	srcRect.h = destRect.h = height;  
	
	destRect.x = x;  
	destRect.y = y;
	
	SDL_RenderCopyEx(renderer, textureMap[id], &srcRect, &destRect, 0, 0, flip);
}