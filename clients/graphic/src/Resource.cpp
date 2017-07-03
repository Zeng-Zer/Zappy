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
  _opacity = 0;
  _sprite.setColor(sf::Color(255, 255, 255, _opacity));
}

Resource::~Resource() {}

Resource::Type const	&Resource::getType() const { return (_type); }
unsigned int		Resource::getOpacity() const { return (_opacity); }

void			Resource::setOpacity(unsigned int const o)
{
  if (o > 255)
    _opacity = 255;
  else
    _opacity = o;
  _sprite.setColor(sf::Color(255, 255, 255, _opacity));
}
