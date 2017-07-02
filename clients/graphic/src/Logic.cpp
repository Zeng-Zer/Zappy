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

void			Logic::createEgg(unsigned int const id, unsigned int const id_player, sf::Vector2i const &pos)
{
  _eggs[id] = new Egg(ImageHandler::getInstance().getTexture(ImageHandler::RESOURCE), ImageHandler::getInstance().getSetSize(ImageHandler::RESOURCE));
  _eggs[id]->scale(sf::Vector2f(0.75, 0.75));
  _eggs[id]->setPosition(_map.mapToCoords(pos));
  _eggs[id]->setPosition(_eggs[id]->adaptCoords(static_cast<sf::Vector2f>(_map.randCoords(_eggs[id]))));
  (void)id_player;
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
void			Logic::updateData()
{
  std::string line = Network::getInstance().recvMsg(MSG_DONTWAIT);

  while (!line.empty()) {
    std::cout << "Line: " << line << std::endl;
    std::stringstream ss(line);
    std::string cmdString;

    cmdString = Tools::parseStreamString(ss);
    std::cout << "Command: " << cmdString << std::endl;

    Protocol::Cmd cmd = Protocol::stringToCmd(cmdString);
    std::cout << "Enum cmd: " << cmd << std::endl;

    Protocol::cmdFun.at(cmd)(*this, line);
    line = Network::getInstance().recvMsg(MSG_DONTWAIT);
  }
}

void			Logic::clear() { _window.clear(); }
void			Logic::display() { _window.display(); }

void			Logic::setMapSize(sf::Vector2i const &s)
{
  _map.setMapSize(s);
  _map_size = s;
}

void			Logic::setMapContent(sf::Vector2i const &p, resource_list l)
{
  for (unsigned int i = 0; i < 7; i++)
    for (unsigned int j = 0; j < l[i]; j++)
      _map.addResource(p, static_cast<Resource::Type>(i));
}

void			Logic::setUnitTime(int ut)
{
  _unitTime = ut;
}
void			Logic::addTeam(std::string const &team)
{
  _teams[team] = new Team(team);
}

void			Logic::setPlayerPosition(unsigned int const id, sf::Vector2i const &p, unsigned int const o)
{
  _players[id]->setPosOnGrid(p, _map);
  _players[id]->setDirection(Player::transformDirection(o));
}

void			Logic::setPlayerLevel(unsigned int const id, unsigned int const lvl)
{
  _players[id]->setLevel(lvl);
}

void			Logic::playerDropResource(unsigned int const id, unsigned int const r)
{
  _map.addResource(_players[id]->getCurPos(), static_cast<Resource::Type>(r));
}

void			Logic::playerTakeResource(unsigned int const id, unsigned int const r)
{
  _map.removeResource(_players[id]->getCurPos(), static_cast<Resource::Type>(r));
}

void			Logic::playerDead(unsigned int const id)
{
  _players.erase(id);
}

void			Logic::update()
{
  _window.setView(_view);
  _map.update(&_window);
  for (unsigned int i = 0; i < _players.size(); i++)
    _window.draw(*_players[i]);
}
