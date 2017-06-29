#include "Player.hpp"

zap::Player::Player() {}
zap::Player::~Player() {}

void			zap::Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = &_texture;
  target.draw(_sprite, states);
}

void			zap::Player::load(sf::Texture const &texture, sf::Vector2i const &setSize)
{
  _texture = texture;
  _setSize = setSize;
  _sprite.setTexture(_texture);
  _sprite.setTextureRect(sf::IntRect(0, 0, _texture.getSize().x / setSize.x, _texture.getSize().y / setSize.y));
}
