#include <cstdlib>
#include <ctime>
#include "Logic.hpp"

Logic::Logic(sf::Vector2i const &res, std::string const &name)
  : _resolution(res)
{
  _window.create(sf::VideoMode(_resolution.x, _resolution.y), name);

  srand(time(NULL));
  _view.setSize(_resolution.x, _resolution.y);
  _view.setViewport(sf::FloatRect(0, 0, 1, 1));
  _view.setCenter(0, 0);
  _view.zoom(1);
}

Logic::~Logic()
{
  unsigned int		i;

  for (std::map<std::string, Team*>::iterator it = _teams.begin(); it != _teams.end(); ++it)
    delete std::get<1>(*it);
  for (i = 0; i < _players.size(); i++)
    delete _players[i];
}

void			Logic::createMap(TileMap::Terrain t)
{
  sf::Vector2f		tmp;

  _map.load(ImageHandler::getInstance().getTexture(ImageHandler::MAP), ImageHandler::getInstance().getSetSize(ImageHandler::MAP), TileMap::createMap(_map_size, t));
  _map.grid();
  tmp = _map.mapToCoords(sf::Vector2i(_map_size.x, _map_size.y));
  _view.setCenter(tmp.x / 2, tmp.y / 2);
}

void			Logic::createPlayer(unsigned int const id, sf::Vector2i const &pos, unsigned int const o, unsigned int const lvl, std::string const &team)
{
  _players[id] = new Player(ImageHandler::getInstance().getTexture(ImageHandler::PLAYER), ImageHandler::getInstance().getSetSize(ImageHandler::PLAYER), Player::transformDirection(o), lvl, _teams[team]);
  _players[id]->scale(sf::Vector2f(0.5, 0.5));
  _players[id]->setPosition(_players[id]->adaptCoords(_map.mapToCoords(pos)));
  _players[id]->setCurPos(pos);
}

void			Logic::eventLoop()
{
  sf::Event		event;

  while (_window.pollEvent(event))
    {
      switch (event.type)
	{
	case sf::Event::Closed:
	  _window.close();
	  break ;

	case sf::Event::KeyPressed:
	  if (event.key.code == sf::Keyboard::Escape)
	    _window.close();
	  else if (event.key.code == sf::Keyboard::A)
	    _view.zoom(1.01);
	  else if (event.key.code == sf::Keyboard::E)
	    _view.zoom(0.99);
	  else if (event.key.code == sf::Keyboard::Up)
	    _view.setCenter(_view.getCenter().x, _view.getCenter().y - CAM_SPEED);
	  else if (event.key.code == sf::Keyboard::Left)
	    _view.setCenter(_view.getCenter().x - CAM_SPEED, _view.getCenter().y);
	  else if (event.key.code == sf::Keyboard::Down)
	    _view.setCenter(_view.getCenter().x, _view.getCenter().y + CAM_SPEED);
	  else if (event.key.code == sf::Keyboard::Right)
	    _view.setCenter(_view.getCenter().x + CAM_SPEED, _view.getCenter().y);
	  break ;

	default :
	  break ;
	}
    }
}

bool			Logic::isOpen() const { return (_window.isOpen()); }
void			Logic::clear() { _window.clear(); }
void			Logic::display() { _window.display(); }

void			Logic::setMapSize(sf::Vector2i const &s)
{
  _map.setMapSize(s);
  _map_size = s;
}

void			Logic::setMapContent(sf::Vector2i const &p, resource_list l)
{
  _map.setMapContent(p, l);
}

void			Logic::setMapContent(unsigned int const id)
{
  _map.setMapContent(_players[id]->getCurPos());
}

void			Logic::setUnitTime(int ut) {
  _unitTime = ut;
}

void			Logic::setPlayerPosition(unsigned int const id, sf::Vector2i const &p, unsigned int const o)
{
  _players[id]->setPosOnGrid(p, _map);
  _players[id]->setDirection(Player::transformDirection(o));
}

void			Logic::playerTakeResource(unsigned int const id, unsigned int const r)
{
  _map.removeMapContent(_players[id]->getCurPos(), static_cast<Resource::Type>(r));
}

void			Logic::addTeam(std::string const &team)
{
  _teams[team] = new Team(team);
}

void			Logic::update()
{
  _window.setView(_view);
  _map.update(&_window);
  for (unsigned int i = 0; i < _players.size(); i++)
    _window.draw(*_players[i]);
}
