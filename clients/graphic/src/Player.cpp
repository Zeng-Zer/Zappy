#include "Player.hpp"
#include "functions.hpp"

static int		getDirFromE(Player::Direction dir)
{
  return ((dir + 1) * 2);
}

Player::Player()
{
  _scale.x = 1;
  _scale.y = 1;
  _curDir = Player::SOUTH;
}

Player::~Player()
{}

void			Player::load(std::string const &sheet, sf::Vector2i const &size, Player::Direction dir)
{
  if (!_texture.loadFromFile(sheet))
    throw(std::exception());
  _texture.setSmooth(true);
  _sprite.setTexture(_texture);
  _size.x = _texture.getSize().x / size.x;
  _size.y = _texture.getSize().y / size.y;
  _sprite.setTextureRect(sf::IntRect(0, getDirFromE(dir) * _size.y, _size.x, _size.y));
}

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

void			Player::setPosition(sf::Vector2i const &p) {_sprite.setPosition(p.x, p.y);}
void			Player::setTextureRect(sf::IntRect const &r){_sprite.setTextureRect(r);}

void			Player::setPosOnGrid(sf::Vector2i const &pos) {_curPos = pos;}
void			Player::scale(sf::Vector2f const &s)
{
  _scale = s;
  _sprite.scale(_scale);
}

void			Player::moveForward()
{
  if (_curDir == EAST)
    _curPos.x += 1;
  else if (_curDir == NORTH)
    _curPos.y -= 1;
  else if (_curDir == WEST)
    _curPos.x -= 1;
  else if (_curDir == SOUTH)
    _curPos.y += 1;
}

void			Player::turnLeft()
{
  _curDir = static_cast<Player::Direction>((_curDir + 1) % 4);
}

void			Player::turnRight()
{
  _curDir = static_cast<Player::Direction>((_curDir - 1) % 4);
}

void			Player::update(sf::Vector2i const &tileSize)
{
  sf::Vector2i		p = coordsToMapCoords(tileSize, _curPos);

  setTextureRect(sf::IntRect(0, getDirFromE(_curDir) * _size.y, _size.x, _size.y));
  setPosition(sf::Vector2i(p.x - _size.x * _scale.x / 2, p.y - _size.y * _scale.y));
}
