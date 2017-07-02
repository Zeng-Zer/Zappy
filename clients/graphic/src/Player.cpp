#include "Player.hpp"

Player::Player(sf::Texture const &texture, sf::Vector2i const &setSize, Direction d, unsigned int const lvl, std::shared_ptr<Team> t)
  : Entity(texture, setSize), _level(lvl)
{
  sf::Vector2f		tmp;

  _team = t;
  tmp.x = 0;
  tmp.y = (d + 1) * 2 * _texture.getSize().y / setSize.y;
  _sprite.setTextureRect(sf::IntRect(tmp.x, tmp.y, _texture.getSize().x / setSize.x, _texture.getSize().y / setSize.y));
  _sprite.setColor(_team->color);
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

sf::Vector2i const	&Player::getCurPos() const { return (_curPos); }

void			Player::setPosOnGrid(sf::Vector2i const &p, TileMap const &map)
{
  setPosition(adaptCoords(map.mapToCoords(p)));
  _curPos = p;
}

void			Player::setDirection(Direction d)
{
  sf::Vector2f		tmp;

  _curDir = d;
  tmp.x = 0;
  tmp.y = (d + 1) * 2 * _texture.getSize().y / _setSize.y;
  _sprite.setTextureRect(sf::IntRect(tmp.x, tmp.y, _texture.getSize().x / _setSize.x, _texture.getSize().y / _setSize.y));
}

void			Player::setCurPos(sf::Vector2i const &p) { _curPos = p; }
void			Player::setLevel(unsigned int const lvl) { _level = lvl; }

Player::Direction	Player::transformDirection(unsigned int const o)
{
  switch (o)
    {
    case 1: return (NORTH); break ;
    case 2: return (EAST); break ;
    case 3: return (SOUTH); break ;
    case 4: return (WEST); break ;
    default: return (SOUTH); break ;
    }
}
