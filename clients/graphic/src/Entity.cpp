#include "Entity.hpp"

zap::Entity::Entity(sf::Texture const &texture, sf::Vector2i const &setSize)
{
  _texture = texture;
  _setSize = setSize;
  _sprite.setTexture(_texture);
}

zap::Entity::~Entity() {}

void			zap::Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = &_texture;
  target.draw(_sprite, states);
}

sf::Vector2i const	&zap::Entity::getSetSize() const { return (_setSize); }
sf::Sprite const	&zap::Entity::getSprite() const { return (_sprite); }
