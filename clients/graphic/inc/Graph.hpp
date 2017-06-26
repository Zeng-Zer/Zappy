#ifndef GRAPH_HPP_
# define GRAPH_HPP_

# include <string>
# include <exception>
# include <SFML/Graphics.hpp>
# include "Player.hpp"
# include "TileMap.hpp"

# define WIDTH			1600
# define HEIGHT			900
# define GRASS			40

class				Graph
{
private:
  sf::Vector2u			_resolution;
  sf::Vector2u			_map_size;
  sf::RenderWindow		_window;
  TileMap			_map;
  sf::View			_view;
  Player			_player;

public:
  Graph(unsigned int const, unsigned int const, std::string const&);
  ~Graph();

  void				run();
};

#endif /* !GRAPH_HPP_ */
