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
  _window.setView(_view);
}

Logic::~Logic() {}

void			Logic::createMap(TileMap::Terrain t)
{
  _map.load(ImageHandler::getInstance().getTexture(ImageHandler::MAP), ImageHandler::getInstance().getSetSize(ImageHandler::MAP), TileMap::createMap(_map_size, t), _map_size);
  _map.grid();
}

void			Logic::createPlayer(sf::Vector2i const &pos, Player::Direction d) // Peut etre prendre equipe en parametre
{
  _players.push_back(new Player(ImageHandler::getInstance().getTexture(ImageHandler::PLAYER), ImageHandler::getInstance().getSetSize(ImageHandler::PLAYER), d));
  _players.back()->scale(sf::Vector2f(0.5, 0.5));
  _players.back()->setPosition(_players.back()->adaptCoords(_map.mapToCoords(pos)));
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
	  break ;

	default :
	  break ;
	}
    }
}

bool			Logic::isOpen() const { return (_window.isOpen()); }
void			Logic::clear() { _window.clear(); }
void			Logic::display() { _window.display(); }

void			Logic::setMapSize(sf::Vector2i const &s) { _map_size = s; }
void			Logic::setMapContent(sf::Vector2i const &p, resource_list l) {
  _map.setMapContent(p, l);
}
void			Logic::setUnitTime(int ut) {
  _unitTime = ut;
}

void			Logic::update()
{
  _map.update(&_window);
  for (unsigned int i = 0; i < _players.size(); i++)
    _window.draw(*_players[i]);
}
