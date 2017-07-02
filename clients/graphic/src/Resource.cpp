#include "Resource.hpp"

Resource::Resource(sf::Texture const &texture, sf::Vector2i const &setSize, Type t):
  Entity(texture, setSize)
{
  sf::Vector2f		tmp;

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

Resource::~Resource() {}
Resource::Type const	&Resource::getType() const { return (_type); }
