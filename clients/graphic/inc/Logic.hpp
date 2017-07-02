#ifndef LOGIC_HPP_
# define LOGIC_HPP_

# include <SFML/Graphics.hpp>
# include <string>
# include <vector>
# include "AudioHandler.hpp"
# include "ImageHandler.hpp"
# include "TileMap.hpp"
# include "Player.hpp"
# include "Resource.hpp"

class				Logic
{
private:
  sf::Vector2i		_resolution;
  sf::Vector2i		_map_size;
  sf::RenderWindow	_window;
  sf::View		_view;
  TileMap		_map;
  std::vector<Player*>	_players;
  int			_unitTime;

public:
  Logic(sf::Vector2i const&, std::string const& = "Zappy");
  ~Logic();

  void			createMap(TileMap::Terrain);
  void			createPlayer(sf::Vector2i const&, Player::Direction);
  void			createResource(sf::Vector2i const&, Resource::Type);

  void			eventLoop();
  bool			isOpen() const;
  void			clear();
  void			display();

  void			setMapSize(sf::Vector2i const&);
  void			setMapContent(sf::Vector2i const&, resource_list);
  void			setUnitTime(int);

  void			update();
};

#endif /* !LOGIC_HPP_ */
