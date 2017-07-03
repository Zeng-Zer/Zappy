#ifndef PLAYER_HPP_
# define PLAYER_HPP_

# include <SFML/Graphics.hpp>
# include <memory>
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
  bool			_incanting;
  std::shared_ptr<Team>	_team;
  sf::Vector2f		_currentPosition;
  sf::Vector2f		_nextPosition;
  std::vector<float>	_a;
  sf::Vector2f		_oldScale;
  sf::Vector2f		_nextScale;

public:
  Player(sf::Texture const&, sf::Vector2i const&, Direction, unsigned int const, std::shared_ptr<Team>);
  virtual ~Player();

  sf::Vector2i const	&getCurPos() const;

  void			setNextPosOnGrid(sf::Vector2i const&, TileMap const&);
  void			setDirection(Direction);
  void			setCurPos(sf::Vector2i const&, TileMap const&);
  void			setLevel(unsigned int const);
  void			prepareIncantation(unsigned int const);
  void			endIncantation(unsigned int const);

  static Direction	transformDirection(unsigned int const);

  void			update(int);
};

#endif /* !PLAYER_HPP_ */
