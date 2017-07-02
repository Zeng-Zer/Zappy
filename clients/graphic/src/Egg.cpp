#include "Egg.hpp"

Egg::Egg(sf::Texture const &texture, sf::Vector2i const &setSize):
  Entity(texture, setSize)
{
  sf::Vector2f		tmp;

  tmp.x = 0;
  tmp.y = _texture.getSize().y / setSize.y;
  _sprite.setTextureRect(sf::IntRect(tmp.x, tmp.y, _texture.getSize().x / setSize.x, _texture.getSize().y / setSize.y));
}

Egg::~Egg() {}

void			Egg::setPosOnGrid(sf::Vector2i const &p, TileMap const &map)
{
  setPosition(adaptCoords(map.mapToCoords(p)));
  _curPos = p;
}
