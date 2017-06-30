#include "Logic.hpp"

zap::Logic::Logic(sf::Vector2i const &res, std::string const &name)
  : _resolution(res)
{
  _window.create(sf::VideoMode(_resolution.x, _resolution.y), name);

  _view.setSize(_resolution.x, _resolution.y);
  _view.setViewport(sf::FloatRect(0, 0, 1, 1));
  _view.setCenter(0, 0);
  _window.setView(_view);
}

zap::Logic::~Logic() {}

// sf::Vector2i		zap::Logic::coordsToMap(sf::Vector2f const &p)
// {}

#include <iostream>

sf::Vector2f		zap::Logic::mapToCoords(sf::Vector2i const &p)
{
  sf::Vector2f		v;
  sf::Vector2i	        map = _map.getTileSize();

  v.x = p.x * map.x / 2 - p.y * map.x / 2;
  v.y = p.x * map.y / 2 + (p.y + 1) * map.y / 2;
  //std::cout <<  << std::endl;
  return (v);
}

sf::Vector2f		zap::Logic::adaptCoords(sf::Vector2f const &p, Player const &player)
{
  sf::Vector2f		v;
  sf::Vector2f		tmp = static_cast<sf::Vector2f>(player.getSprite().getTexture()->getSize());

  v.x = p.x - tmp.x / player.getSetSize().x * player.getScale().x / 2;
  v.y = p.y - tmp.y / player.getSetSize().y * player.getScale().y;
  return (v);
}

sf::Vector2f		zap::Logic::adaptCoords(sf::Vector2f const &p, Resource const &player) // Faire une classe entity
{
  sf::Vector2f		v;
  sf::Vector2f		tmp = static_cast<sf::Vector2f>(player.getSprite().getTexture()->getSize());

  v.x = p.x - tmp.x / player.getSetSize().x * player.getScale().x / 2;
  v.y = p.y - tmp.y / player.getSetSize().y * player.getScale().y;
  return (v);
}

void			zap::Logic::update() const {}

void			zap::Logic::createMap(sf::Vector2i const &map, TileMap::Terrain t)
{
  _map.load(ImageHandler::getInstance().getTexture(ImageHandler::MAP), ImageHandler::getInstance().getSetSize(ImageHandler::MAP), TileMap::createMap(map, t), map);
  _map_size = map;
  _map.quad();
}

void			zap::Logic::createPlayer(sf::Vector2i const &pos, Player::Direction d) // Peut etre prendre equipe en parametre
{
  _players.push_back(new Player(ImageHandler::getInstance().getTexture(ImageHandler::PLAYER), ImageHandler::getInstance().getSetSize(ImageHandler::PLAYER), d));
  _players.back()->scale(sf::Vector2f(0.5, 0.5));
  _players.back()->setPosition(adaptCoords(mapToCoords(pos), *(_players.back())));
}

void			zap::Logic::createResource(sf::Vector2i const &pos, Resource::Type t)
{
  _resources.push_back(new Resource(ImageHandler::getInstance().getTexture(ImageHandler::RESSOURCE), ImageHandler::getInstance().getSetSize(ImageHandler::RESSOURCE), t));
  _resources.back()->scale(sf::Vector2f(0.5, 0.5));
  _resources.back()->setPosition(adaptCoords(mapToCoords(pos), *(_resources.back())));
}

void			zap::Logic::drawAll()
{
  unsigned int		i;
  unsigned int		size;

  _window.draw(_map);
  size = _players.size();
  for (i = 0; i < size; i++)
    _window.draw(*_players[i]);
  size = _resources.size();
  for (i = 0; i < size; i++)
    _window.draw(*_resources[i]);
}

void			zap::Logic::eventLoop()
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

bool			zap::Logic::isOpen() const { return (_window.isOpen()); }
void			zap::Logic::clear() { _window.clear(); }
void			zap::Logic::display() { _window.display(); }
