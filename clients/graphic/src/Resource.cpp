#include "Resource.hpp"

zap::Resource::Resource() {}
zap::Resource::~Resource() {}

void			zap::Resource::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = &_texture;
  target.draw(_sprite, states);
}

void			zap::Resource::load(sf::Texture const &texture, sf::Vector2i const &setSize, Type t)
{
  sf::Vector2f		tmp;

  _texture = texture;
  _setSize = setSize;
  _sprite.setTexture(_texture);
  if (t == THYSTAME)
    {
      t = MENDIANE;
      _sprite.setColor(sf::Color::Green);
    }
  tmp.x = (10 + t - 1) * _texture.getSize().x / _setSize.x;
  tmp.y = 0;
  if (t == FOOD)
    {
      tmp.x = 1 * _texture.getSize().x / _setSize.x;
      tmp.y = 5 * _texture.getSize().y / _setSize.y;
    }
  _sprite.setTextureRect(sf::IntRect(tmp.x, tmp.y, _texture.getSize().x / setSize.x, _texture.getSize().y / setSize.y));
}
