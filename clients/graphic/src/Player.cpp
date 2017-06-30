#include "Player.hpp"

zap::Player::Player() {}
zap::Player::~Player() {}

void			zap::Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = &_texture;
  target.draw(_sprite, states);
}

void			zap::Player::load(sf::Texture const &texture, sf::Vector2i const &setSize, Direction d)
{
  sf::Vector2f		tmp;

  _texture = texture;
  _setSize = setSize;
  _sprite.setTexture(_texture);
  tmp.x = 0;
  tmp.y = (d + 1) * 2 * _texture.getSize().y / setSize.y;
  _sprite.setTextureRect(sf::IntRect(tmp.x, tmp.y, _texture.getSize().x / setSize.x, _texture.getSize().y / setSize.y));
}

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
