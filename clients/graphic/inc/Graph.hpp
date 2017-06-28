
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
  sf::Vector2i			_resolution;
  sf::Vector2i			_map_size;
  sf::RenderWindow		_window;
  TileMap			_map;
  sf::View			_view;
  Player			_player;

  void				handle_player_mvmt(Player&);

public:
  Graph(unsigned int const, unsigned int const, std::string const&);
  ~Graph();

  void				run();
};

#endif /* !GRAPH_HPP_ */
