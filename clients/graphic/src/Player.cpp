#include "Player.hpp"

Player::Player() : _speed(0.1)
{}

Player::~Player()
{}

void			Player::load(std::string const &sheet, sf::Vector2u const &size, sf::Vector2u const &dir)
{
  if (!_texture.loadFromFile(sheet))
    throw(std::exception());
  _texture.setSmooth(true);
  _sprite.setTexture(_texture);
  _size.x = _texture.getSize().x / size.x;
  _size.y = _texture.getSize().y / size.y;
  _sprite.setTextureRect(sf::IntRect(dir.x, dir.y * _size.y, _size.x, _size.y));
}

void			Player::move(float const x, float const y, unsigned int const posy)
{
  static unsigned int	posx = 1;
  static unsigned int	d = 0;

  if ((d += 2) == 128)
    {
      posx++;
      d = 0;
    }
  if (posx > 10)
    posx = 1;
  _sprite.move(x, y);
  _sprite.setTextureRect(sf::IntRect(posx * _size.x, posy * _size.y, _size.x, _size.y));
}

sf::Vector2f const	&Player::getPosition() const {return (_sprite.getPosition());}
sf::Sprite const	&Player::getSprite() const {return (_sprite);}
sf::Vector2u const	&Player::getSize() const {return (_size);}

void			Player::setPosition(unsigned int const x, unsigned int const y) {_sprite.setPosition(x, y);}
void			Player::setTextureRect(sf::IntRect const &r){_sprite.setTextureRect(r);}
