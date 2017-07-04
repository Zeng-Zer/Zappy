#include "Player.hpp"

Player::Player(sf::Texture const &texture, sf::Vector2i const &setSize, Direction d, unsigned int const lvl, std::shared_ptr<Team> t)
  : Entity(texture, setSize), _level(lvl)
{
  sf::Vector2f		tmp;

  _a = std::vector<float>(4);
  _team = t;
  _curDir = d;
  tmp.x = 0;
  tmp.y = (d + 1) * 2 * _texture.getSize().y / setSize.y;
  _sprite.setTextureRect(sf::IntRect(tmp.x, tmp.y, _texture.getSize().x / setSize.x, _texture.getSize().y / setSize.y));
  _sprite.setColor(_team->color);
  scale(sf::Vector2f(static_cast<float>(lvl) * 0.3 / 8 + 0.5, static_cast<float>(lvl) * 0.3 / 8 + 0.5));
  _nextScale = getScale();
  _oldScale = _nextScale;
  _incanting = false;
}

Player::~Player() {}

sf::Vector2i const	&Player::getCurPos() const { return (_curPos); }

void			Player::setNextPosOnGrid(sf::Vector2i const &p, TileMap const &map)
{
  _curPos = p;
  _nextPosition = map.mapToCoords(p);
}

void			Player::setDirection(Direction d)
{
  sf::Vector2f		tmp;

  _curDir = d;
  tmp.x = 0;
  tmp.y = (d + 1) * 2 * _texture.getSize().y / _setSize.y;
  _sprite.setTextureRect(sf::IntRect(tmp.x, tmp.y, _texture.getSize().x / _setSize.x, _texture.getSize().y / _setSize.y));
}

void			Player::setCurPos(sf::Vector2i const &p, TileMap const &map)
{
  setNextPosOnGrid(p, map);
  _currentPosition = _nextPosition;
  _a[0] = static_cast<float>(map.getTileSize().y) / static_cast<float>(map.getTileSize().x);
  _a[1] = static_cast<float>(-map.getTileSize().y) / static_cast<float>(map.getTileSize().x);
  _a[2] = _a[0];
  _a[3] = _a[1];
}

void			Player::setLevel(unsigned int const lvl)
{
  _level = lvl;
}

void			Player::prepareIncantation(unsigned int const lvl)
{
  _incanting = true;
  _nextScale = sf::Vector2f(static_cast<float>(lvl) * 0.3 / 8 + 0.5, static_cast<float>(lvl) * 0.3 / 8 + 0.5);
}

void			Player::endIncantation(unsigned int const result)
{
  if (result == 1)
    {
      _oldScale = _nextScale;
      setScale(_nextScale);
    }
  else
    setScale(_oldScale);
  _incanting = false;
}

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

void			Player::update(int unitTime)
{
  float			b = _nextPosition.y - _a[_curDir] * _nextPosition.x;
  static int		posx = 1;
  static int		d = 0;

  if (_incanting == true)
    setScale(_nextScale == getScale() ? _oldScale : _nextScale);
  if (_currentPosition != _nextPosition)
    {
      if ((d += unitTime / 10) == 128)
  	{
  	  posx++;
  	  d = 0;
  	}
      if (posx > 9)
  	posx = 1;
      if (_curDir == Player::NORTH || _curDir == Player::EAST)
  	{
  	  _currentPosition.x += static_cast<float>(unitTime) / 15;
  	  if (_currentPosition.x > _nextPosition.x)
  	    {
  	      _currentPosition = _nextPosition;
  	      return ;
  	    }
  	}
      else
  	{
  	  _currentPosition.x -= static_cast<float>(unitTime) / 15;
  	  if (_currentPosition.x < _nextPosition.x)
  	    {
  	      _currentPosition = _nextPosition;
  	      return ;
  	    }
  	}
      _currentPosition.y = _a[_curDir] * _currentPosition.x + b;
      _sprite.setTextureRect(sf::IntRect(posx * _texture.getSize().x / _setSize.x, (_curDir + 1) * 2 * _texture.getSize().y / _setSize.y, _texture.getSize().x / _setSize.x, _texture.getSize().y / _setSize.y));
    }
  else
    _sprite.setTextureRect(sf::IntRect(0, (_curDir + 1) * 2 * _texture.getSize().y / _setSize.y, _texture.getSize().x / _setSize.x, _texture.getSize().y / _setSize.y));
  setPosition(adaptCoords(_currentPosition));
}
