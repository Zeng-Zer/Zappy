#include "Entity.hpp"

Entity::Entity(sf::Texture const &texture, sf::Vector2i const &setSize)
{
  _texture = texture;
  _setSize = setSize;
  _sprite.setTexture(_texture);
}

Entity::~Entity() {}

void			Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = &_texture;
  target.draw(_sprite, states);
}

sf::Vector2i const	&Entity::getSetSize() const { return (_setSize); }
sf::Sprite const	&Entity::getSprite() const { return (_sprite); }
