#include "../entities/Entity.h"
#include "Tile.h"
#include <Vector>

class Map : public Entity
{
public:
	/**
	@brief Creates the map for the level

	@param p - The position of the map
	@param d - The dimensions of the map in tiles
	*/
	Map(Vec2 p, Vec2 d);
	~Map();

	/**
	@brief Update any internal values.

	@param dt - delta time.
	*/
	void update(float dt);

	/**
	@brief Render any sprites relevant to the entity
	*/
	void render(SDL_Renderer *renderer);

private:

	std::vector<std::vector<Tile*>> mapLayerOne;
	std::vector<std::vector<Tile*>> mapLayerTwo;

	/**
	@brief Creates a blank map
	*/
	void createBlankMap();


};