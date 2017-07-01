#include "Player.hpp"

zap::Player::Player(sf::Texture const &texture, sf::Vector2i const &setSize, Direction d):
  Entity(texture, setSize)
{
  sf::Vector2f		tmp;

  tmp.x = 0;
  tmp.y = (d + 1) * 2 * _texture.getSize().y / setSize.y;
  _sprite.setTextureRect(sf::IntRect(tmp.x, tmp.y, _texture.getSize().x / setSize.x, _texture.getSize().y / setSize.y));
}

zap::Player::~Player() {}

void			zap::Player::turn(Side s)
{
  _curDir = static_cast<Direction>((_curDir + (s * 2 + 1)) % 4);
}

void			zap::Player::moveForward(sf::Vector2i const &m)
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
