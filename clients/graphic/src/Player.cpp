#include "Player.hpp"

static int		getDirFromE(Player::Direction dir)
{
  return ((dir + 1) * 2);
}

static sf::Vector2i	coordsToMapCoords(sf::Vector2i const &tileSize, sf::Vector2i const &coords)
{
  sf::Vector2i		p;

  p.x = coords.x * tileSize.x / 2 - coords.y * tileSize.x / 2;
  p.y = coords.x * tileSize.y / 2 + (coords.y + 1) * tileSize.y / 2;
  return (p);
}

Player::Player()
{
  _scale.x = 1;
  _scale.y = 1;
  _curDir = Player::SOUTH;
}

Player::~Player()
{}

void			Player::load(std::string const &sheet, sf::Vector2i const &size, Player::Direction dir, sf::Vector2i const &map_size)
{
  if (!_texture.loadFromFile(sheet))
    throw(std::exception());
  _texture.setSmooth(true);
  _sprite.setTexture(_texture);
  _map_size = map_size;
  _size.x = _texture.getSize().x / size.x;
  _size.y = _texture.getSize().y / size.y;
  _sprite.setTextureRect(sf::IntRect(0, getDirFromE(dir) * _size.y, _size.x, _size.y));
}

// A virer
void			Player::move(float const x, float const y, int const posy)
{
  static int		posx = 1;
  static int		d = 0;

  if ((d += 2) == 128)
    {
      posx++;
      d = 0;
    }
  if (posx > 9)
    posx = 1;
  _sprite.move(x, y);
  _sprite.setTextureRect(sf::IntRect(posx * _size.x, posy * _size.y, _size.x, _size.y));
}

sf::Vector2f const	&Player::getPosition() const {return (_sprite.getPosition());}
sf::Sprite const	&Player::getSprite() const {return (_sprite);}
sf::Vector2i const	&Player::getSize() const {return (_size);}
sf::Vector2f const	&Player::getScale() const {return (_scale);}

void			Player::setPosition(sf::Vector2f const &p) {_sprite.setPosition(p.x, p.y);}
void			Player::setTextureRect(sf::IntRect const &r){_sprite.setTextureRect(r);}
void			Player::setColor(sf::Color const &c){_sprite.setColor(c);}

void			Player::setPosOnGrid(sf::Vector2i const &pos) {_curPos = pos; _oldPos = _curPos;}
void			Player::scale(sf::Vector2f const &s) {_scale = s; _sprite.scale(_scale);}

void			Player::moveForward()
{
  if (_curDir == EAST)
    _curPos.x = (_curPos.x + 1) % _map_size.x;
  else if (_curDir == NORTH)
    _curPos.y = (_curPos.y + (_map_size.y - 1)) % _map_size.y;
  else if (_curDir == WEST)
    _curPos.x = (_curPos.x + (_map_size.x - 1)) % _map_size.x;
  else if (_curDir == SOUTH)
    _curPos.y = (_curPos.y + 1) % _map_size.y;
}

void			Player::turnLeft()
{
  _curDir = static_cast<Player::Direction>((_curDir + 1) % 4);
}

void			Player::turnRight()
{
  _curDir = static_cast<Player::Direction>((_curDir + 3) % 4);
}

void			Player::animate(sf::Vector2f oldPos, sf::Vector2f newPos)
{
  float			a = (newPos.y - oldPos.y) / (newPos.x - oldPos.x);
  float			b = oldPos.y - a * oldPos.x;
  
  float			x = oldPos.x;
  float			y;

  while (x != newPos.x)
    {
      y = a * x + b;
      setPosition(sf::Vector2f(x - _size.x * _scale.x / 2, y - _size.y * _scale.y));
      if (oldPos.x < newPos.x)
	x += 0.2;
      else
	x -= 0.2;
    }
}

void			Player::update(sf::Vector2i const &tileSize)
{
  sf::Vector2i		p = coordsToMapCoords(tileSize, _curPos);

  setTextureRect(sf::IntRect(0, getDirFromE(_curDir) * _size.y, _size.x, _size.y));
  //animate(static_cast<sf::Vector2f>(coordsToMapCoords(tileSize, _oldPos)), static_cast<sf::Vector2f>(coordsToMapCoords(tileSize, _curPos)));
  setPosition(sf::Vector2f(p.x - _size.x * _scale.x / 2, p.y - _size.y * _scale.y));
}
