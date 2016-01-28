#include "Character.h"

Character::Character(Texture* texture, Vec2 pos, CharacterType *characterType) :Entity(texture, pos), characterType(characterType)
{

}

Character::Character(Texture* texture, Vec2 pos, Vec2 dimensions, CharacterType *characterType) : Entity(texture, pos, dimensions), characterType(characterType)
{

}

Character::Character(Texture* texture, Vec2 pos, Vec2 dimensions, Vec2 spriteDimensions, CharacterType *characterType) : Entity(texture, pos, dimensions, Vec2(0, 0), spriteDimensions), characterType(characterType)
{

}
Character::~Character()
{
}

void Character::update(float dt)
{

}

void Character::render(SDL_Renderer* renderer)
{
	characterType->render(renderer, pos, dimensions, state, frame);
}