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

sf::Vector2f	        Entity::adaptCoords(sf::Vector2f const &p) const
{
  sf::Vector2f		v;
  sf::Vector2f		tmp = static_cast<sf::Vector2f>(getSprite().getTexture()->getSize());

  v.x = p.x - tmp.x / getSetSize().x * getScale().x / 2;
  v.y = p.y - tmp.y / getSetSize().y * getScale().y;
  return (v);
}
