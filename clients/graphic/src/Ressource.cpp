#include "Ressource.hpp"

static sf::Vector2i	getTypeFromE(Ressource::Type t)
{
  if (t == Ressource::FOOD)
    return (sf::Vector2i(1, 5));
  return (sf::Vector2i(t + 14, 1));
}

Ressource::Ressource(std::string const &sheet, sf::Vector2i const &size, Ressource::Type type)
{
  sf::Vector2i		p;

  if (!_texture.loadFromFile(sheet))
    throw(std::exception());
  _texture.setSmooth(true);
  _sprite.setTexture(_texture);
  _size.x = _texture.getSize().x / size.x;
  _size.y = _texture.getSize().y / size.y;
  p = getTypeFromE(type);
  _sprite.setTextureRect(sf::IntRect(p.x * _size.x, p.y * _size.y, _size.x, _size.y));
  _scale.x = 1;
  _scale.y = 1;
}

Ressource::~Ressource()
{}

void			Ressource::load(std::string const &sheet, sf::Vector2i const &size, Ressource::Type type)
{
  sf::Vector2i		p;

  if (!_texture.loadFromFile(sheet))
    throw(std::exception());
  _texture.setSmooth(true);
  _sprite.setTexture(_texture);
  _size.x = _texture.getSize().x / size.x;
  _size.y = _texture.getSize().y / size.y;
  p = getTypeFromE(type);
  _sprite.setTextureRect(sf::IntRect(p.x * _size.x, p.y * _size.y, _size.x, _size.y));
}

sf::Vector2f const	&Ressource::getPosition() const {return (_sprite.getPosition());}
sf::Sprite const	&Ressource::getSprite() const {return (_sprite);}
sf::Vector2i const	&Ressource::getSize() const {return (_size);}
sf::Vector2f const	&Ressource::getScale() const {return (_scale);}

void			Ressource::setPosition(sf::Vector2f const &p) {_sprite.setPosition(p.x, p.y);}
void			Ressource::setTextureRect(sf::IntRect const &r){_sprite.setTextureRect(r);}
void			Ressource::scale(sf::Vector2f const &s) {_scale = s; _sprite.scale(_scale);}
