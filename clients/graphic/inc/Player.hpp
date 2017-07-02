#ifndef PLAYER_HPP_
# define PLAYER_HPP_

# include <SFML/Graphics.hpp>
# include "TileMap.hpp"
# include "Entity.hpp"
# include "Team.hpp"

class				Player : public Entity
{
public:
  enum			Direction { EAST, NORTH, WEST, SOUTH };
  enum			Side { LEFT, RIGHT };

private:
  sf::Vector2i		_curPos;
  Direction		_curDir;
  unsigned int		_level;
  Team			*_team;

public:
  Player(sf::Texture const&, sf::Vector2i const&, Direction, unsigned int const, Team*);
  virtual ~Player();

  void			turn(Side);
  void			moveForward(sf::Vector2i const&);

  void			setPosOnGrid(sf::Vector2i const&, TileMap const&);
  void			setDirection(Direction);

  static Direction	transformDirection(unsigned int const);
};

#endif /* !PLAYER_HPP_ */
