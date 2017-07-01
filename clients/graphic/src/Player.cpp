#include "Player.hpp"

Player::Player(sf::Texture const &texture, sf::Vector2i const &setSize, Direction d):
  Entity(texture, setSize)
{
  sf::Vector2f		tmp;

  tmp.x = 0;
  tmp.y = (d + 1) * 2 * _texture.getSize().y / setSize.y;
  _sprite.setTextureRect(sf::IntRect(tmp.x, tmp.y, _texture.getSize().x / setSize.x, _texture.getSize().y / setSize.y));
}

Player::~Player() {}

void			Player::turn(Side s)
{
  _curDir = static_cast<Direction>((_curDir + (s * 2 + 1)) % 4);
}

void			Player::moveForward(sf::Vector2i const &m)
{
  if (_curDir == EAST)
    _curPos.x = (_curPos.x + 1) % m.x;
  else if (_curDir == NORTH)
    _curPos.y = (_curPos.y - 1) % m.y;
  else if (_curDir == WEST)
    _curPos.x = (_curPos.x - 1) % m.x;
  else if (_curDir == SOUTH)
    _curPos.y = (_curPos.y + 1) % m.y;
}

void			Player::setPosOnGrid(sf::Vector2i const &p, TileMap const &map)
{
  setPosition(adaptCoords(map.mapToCoords(p)));
  _curPos = p;
}

void			Player::setDirection(Direction d)
{
  _curDir = d;
}

Player::Direction	Player::transformDirection(unsigned int const o)
{
  Direction		d;

  if (o == 1)
    d = NORTH;
  else if (o == 2)
    d = EAST;
  else if (o == 3)
    d = SOUTH;
  else if (o == 4)
    d = WEST;
  return (d);
}
