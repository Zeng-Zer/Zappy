#include "Ressource.hpp"

zap::Ressource::Ressource() {}
zap::Ressource::~Ressource() {}

void			zap::Ressource::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = &_texture;
  target.draw(_sprite, states);
}

void			zap::Ressource::load(sf::Texture const &texture, sf::Vector2i const &setSize)
{
  _texture = texture;
  _setSize = setSize;
  _sprite.setTexture(_texture);
  _sprite.setTextureRect(sf::IntRect(0, 0, _texture.getSize().x / setSize.x, _texture.getSize().y / setSize.y));
}
