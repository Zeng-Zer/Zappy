#include "Graph.hpp"

static void		init_map(sf::Vector2i const &map_size, int *level)
{
  for (int i = 0; i < map_size.y; i++)
    for (int j = 0; j < map_size.x; j++)
      level[j + i * map_size.x] = GRASS;
}

Graph::Graph(unsigned int const width, unsigned int const height, std::string const &name)
{
  int			*level;

  _resolution.x = WIDTH;
  _resolution.y = HEIGHT;
  _window.create(sf::VideoMode(_resolution.x, _resolution.y), name.c_str());

  level = new int [width * height];
  _map_size.x = width;
  _map_size.y = height;
  init_map(_map_size, level);
  if (!_map.load("./media/tileset_iso.png", sf::Vector2i(128, 64), level, _map_size))
    throw(std::exception());

  _player.load("./media/cowboy.png", sf::Vector2i(14, 10), Player::SOUTH, _map_size);
  _player.scale(sf::Vector2f(0.5f, 0.5f));
  _player.setPosOnGrid(sf::Vector2i(0, 0));
  _player.setColor(sf::Color(255, 0, 0));
  _player.update(_map.getTileSize());

  _view.setSize(_resolution.x, _resolution.y);
  _view.setViewport(sf::FloatRect(0, 0, 1, 1));
  delete [] level;
}

Graph::~Graph()
{}

void		        Graph::handle_keyboard(sf::Event const &event)
{
  if (event.key.code == sf::Keyboard::Up)
    _player.moveForward();
  else if (event.key.code == sf::Keyboard::Left)
    _player.turnLeft();
  else if (event.key.code == sf::Keyboard::Right)
    _player.turnRight();
  if (event.key.code == sf::Keyboard::A)
    _view.zoom(0.7);
  else if (event.key.code == sf::Keyboard::E)
    _view.zoom(1.3);
  else if (event.key.code == sf::Keyboard::Escape)
    _window.close();
  _player.update(_map.getTileSize());
}

void			Graph::eventLoop()
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
	  handle_keyboard(event);
	  break ;
	default:
	  break ;
	}
    }
}

void			Graph::run()
{
  sf::Vector2f		position;

  while (_window.isOpen())
    {
      eventLoop();

      position.x = _player.getPosition().x + _player.getSize().x * _player.getScale().x / 2;
      position.y = _player.getPosition().y + _player.getSize().y * _player.getScale().y / 2;
      _view.setCenter(position.x, position.y);

      _window.setView(_view);
      _window.clear();
      _window.draw(_map);
      _window.draw(_player.getSprite());
      _window.display();
    }
}
