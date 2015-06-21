#include "Texture.h"
#include "Utility.h"

/*Constructs the texture*/
Texture::Texture(SDL_Renderer* renderer, int r, int g, int b)
{
	/*Declaring the surface*/
	SDL_Surface *surface;

	/*Creating the surface*/
	surface = SDL_CreateRGBSurface(0, 1, 1, 32, 0, 0, 0, 0);

	/*Filling the surface with the color*/
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, (Uint8)r, (Uint8)g, (Uint8)b));
	
	/*Converts the surface into texture data*/
	textureData = SDL_CreateTextureFromSurface(renderer, surface);

	/*delete the surface from memory*/
	SDL_FreeSurface(surface);
}

/*Constructs the texture using SDL image*/
Texture::Texture(std::string fileLocation, SDL_Renderer* renderer)
{
	/*Loads the image as a surface*/
	SDL_Surface* image = IMG_Load(fileLocation.c_str());

	/*Error Check - If unable to load image then end program*/
	if (!image)
	{
		/*initialise the message*/
		std::string message = "Unable to load image from: " + fileLocation + ", Error is: " + IMG_GetError();
		Utility::log(Utility::E, message);
	}

	/*Converts the surface into texture data*/
	textureData = SDL_CreateTextureFromSurface(renderer, image);

	/*delete the surface from memory*/
	SDL_FreeSurface(image);

	/*get the size of the texture*/
	SDL_QueryTexture(textureData, NULL, NULL, &textureWidth, &textureHeight);
}

/*Constructs the texture using a bmp image*/
Texture::Texture(std::string fileLocation, SDL_Renderer* renderer, bool magentaAlpha)
{
	/*Loads the image as a surface*/
	SDL_Surface* image = SDL_LoadBMP(fileLocation.c_str());
	/*Error Check - If unable to load image then end program*/
	if (!image)
	{
		/*initialise the message*/
		std::string message = "Unable to load image from: " + fileLocation + ", Error is: " + IMG_GetError();
		Utility::log(Utility::E, message);
	}
	/*Check if the images magenta is to be used as the alpha*/
	if (magentaAlpha)
	{
		/*Replaces magenta with alpha*/
		SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, 255, 0, 255));
	}

	/*Converts the surface into texture data*/
	textureData = SDL_CreateTextureFromSurface(renderer, image);

	/*delete the surface from memory*/
	SDL_FreeSurface(image);

	/*get the size of the texture*/
	SDL_QueryTexture(textureData, NULL, NULL, &textureWidth, &textureHeight);
}

/*Destructs the Texture*/
Texture::~Texture()
{
	/*deletes the texture from memory*/
	SDL_DestroyTexture(textureData);
}

/*Getter # Texture*/
SDL_Texture* Texture::getTexture()
{
	/*returns the texture data*/
	return textureData;
}

/*Getter # Width*/
int Texture::getWidth()
{
	/*returns the textureWidth*/
	return textureWidth;
}

/*Getter # Height*/
int Texture::getHeight()
{
	/*returns the textureHeight*/
	return textureHeight;
}

/*Pushes the texture to the Renderer*/
void Texture::pushToScreen(SDL_Renderer* renderer, int x, int y)
{
	/*create the destination rectangle of the texture*/
	SDL_Rect destRect;
	destRect.x = x; /*destination x coordinate*/
	destRect.y = y; /*destination y coordinate*/
	destRect.w = textureWidth; /*destination width (scale along the x axis)*/
	destRect.h = textureHeight; /*destination height (scale along the y axis)*/

	/*Copy the texture to the renderer at the destination rectangle*/
	SDL_RenderCopy(renderer, textureData, NULL, &destRect);

}

/*Pushes the scaled texture to the Renderer*/
void Texture::pushToScreen(SDL_Renderer* renderer, int x, int y, int width, int height)
{
	/*create the destination rectangle of the texture*/
	SDL_Rect destRect;
	destRect.x = x; /*destination x coordinate*/
	destRect.y = y; /*destination y coordinate*/
	destRect.w = width; /*destination width (scale along the x axis)*/
	destRect.h = height; /*destination height (scale along the y axis)*/

	/*Copy the texture to the renderer at the destination rectangle*/
	SDL_RenderCopy(renderer, textureData, NULL, &destRect);

}

/*Pushes part of the texture to the Renderer*/
void Texture::pushSpriteToScreen(SDL_Renderer* renderer, int x, int y, int srcX, int srcY, int srcWidth, int srcHeight)
{
	/*create the destination rectangle of the texture*/
	SDL_Rect destRect;
	destRect.x = x; /*destination x coordinate*/
	destRect.y = y; /*destination y coordinate*/
	destRect.w = srcWidth; /*destination width (scale along the x axis)*/
	destRect.h = srcHeight; /*destination height (scale along the y axis)*/

	/*create the source rectangle of the texture*/
	SDL_Rect srcRect;
	srcRect.x = srcX; /*source x coordinate*/
	srcRect.y = srcY; /*source y coordinate*/
	srcRect.w = srcWidth; /*source width*/
	srcRect.h = srcHeight; /*source height*/

	/*Copy the texture to the renderer at the destination rectangle*/
	SDL_RenderCopy(renderer, textureData, &srcRect, &destRect);

}

/*Pushes a scaled part of the texture to the Renderer*/
void Texture::pushSpriteToScreen(SDL_Renderer* renderer, int x, int y, int srcX, int srcY, int srcWidth, int srcHeight, int width, int height)
{
	/*create the destination rectangle of the texture*/
	SDL_Rect destRect;
	destRect.x = x; /*destination x coordinate*/
	destRect.y = y; /*destination y coordinate*/
	destRect.w = width; /*destination width (scale along the x axis)*/
	destRect.h = height; /*destination height (scale along the y axis)*/

	/*create the source rectangle of the texture*/
	SDL_Rect srcRect;
	srcRect.x = srcX; /*source x coordinate*/
	srcRect.y = srcY; /*source y coordinate*/
	srcRect.w = srcWidth; /*source width*/
	srcRect.h = srcHeight; /*source height*/

	/*Copy the texture to the renderer at the destination rectangle*/
	SDL_RenderCopy(renderer, textureData, &srcRect, &destRect);

}