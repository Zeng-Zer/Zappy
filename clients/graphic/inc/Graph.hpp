
#ifndef GRAPH_HPP_
# define GRAPH_HPP_

# include <string>
# include <exception>
# include <SFML/Graphics.hpp>
# include <vector>
# include "Player.hpp"
# include "Ressource.hpp"
# include "TileMap.hpp"

# define WIDTH			1600
# define HEIGHT			900
# define GRASS			40

class				Graph
{
private:
  sf::Vector2i			_resolution;
  sf::Vector2i			_map_size;
  sf::RenderWindow		_window;
  TileMap			_map;
  sf::View			_view;
  Player			_player;
  std::vector<Ressource>	_ressources;

  void				handle_keyboard(sf::Event const&);
  void				eventLoop();

public:
  Graph(unsigned int const, unsigned int const, std::string const&);
  ~Graph();

  void				run();
};

#endif /* !GRAPH_HPP_ */
