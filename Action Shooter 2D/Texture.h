#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>

/**
@brief Creates a Texture for use with a renderer.
Creates a Texture from an image file, this can then be used with a renderer.
@author Jamie Slowgrove
*/
class Texture
{
private:
	///The Texture data
	SDL_Texture* textureData;
	///The width of the Texture.
	int textureWidth;
	///The height of the Texture.
	int textureHeight;

public:
	/**
	Constructs the Texture.
	Creates a Texture using an RGB value. This will create a 1x1 rectangle of that colour that can be scaled.
	@param renderer A pointer to the renderer.
	@param r The red value.
	@param g The green value.
	@param b The blue value.
	*/
	Texture(SDL_Renderer* renderer, int r, int g, int b);

	/**
	Constructs the Texture.
	Creates a Texture using an image location and a renderer. This is for use with SDL image.
	@param fileLocation The location of the image file.
	@param renderer The renderer.
	*/
	Texture(std::string fileLocation, SDL_Renderer* renderer);

	/**
	Constructs the Texture.
	Creates a Texture using an image location and a renderer. The magenta pixels of this image can
	represent alpha if needed.
	@param fileLocation The location of the image file.
	@param renderer The renderer.
	@param magentaAlpha If true any magenta pixels in the image will be converted to alpha.
	*/
	Texture(std::string fileLocation, SDL_Renderer* renderer, bool magentaAlpha);

	/**
	Destructs the Texture deleting the Texture from memory.
	*/
	~Texture();

	/**
	Getter # Returns a pointer to the Texture.
	@returns A pointer to the Texture data.
	*/
	SDL_Texture* getTexture();

	/**
	Getter # Returns textureWidth.
	@returns The value of textureWidth.
	*/
	int getWidth();

	/**
	Getter # Returns textureHeight.
	@returns The value of textureHeight.
	*/
	int getHeight();

	/**
	Pushes the image to the Renderer, to the XY Coordinates.
	@param renderer The renderer.
	@param x The x coordinate of the image.
	@param y The y coordinate of the image.
	*/
	void pushToScreen(SDL_Renderer* renderer, int x, int y);

	/**
	Pushes the image to the Renderer, to the XY Coordinates. This is scaled to the width and height
	inputed.
	@param renderer The renderer.
	@param x The x coordinate of the image.
	@param y The y coordinate of the image.
	@param width The width of the scaled image.
	@param height The height of the scaled image.
	*/
	void pushToScreen(SDL_Renderer* renderer, int x, int y, int width, int height);

	/**
	Pushes the image to the Renderer, to the XY Coordinates. Only displays the source rectangle inputed.
	@param renderer The renderer.
	@param x The x coordinate of the image.
	@param y The y coordinate of the image.
	@param srcX The x coordinate of the source image.
	@param srcY The y coordinate of the source image.
	@param srcWidth The width of the source image.
	@param srcHeight The height of the source image.
	*/
	void pushSpriteToScreen(SDL_Renderer* renderer, int x, int y, int srcX, int srcY, int srcWidth, int srcHeight);

	/**
	Pushes the image to the Renderer, to the XY Coordinates. Only displays the source rectangle inputed.
	This is scaled to the width and height inputed.
	@param renderer The renderer.
	@param x The x coordinate of the image.
	@param y The y coordinate of the image.
	@param srcX The x coordinate of the source image.
	@param srcY The y coordinate of the source image.
	@param srcWidth The width of the source image.
	@param srcHeight The height of the source image.
	@param width The width of the scaled image.
	@param height The height of the scaled image.
	*/
	void pushSpriteToScreen(SDL_Renderer* renderer, int x, int y, int srcX, int srcY, int srcWidth, int srcHeight, int width, int height);
};