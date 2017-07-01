#ifndef PLAYER_HPP_
# define PLAYER_HPP_

# include <SFML/Graphics.hpp>
# include "Entity.hpp"

namespace			zap
{
  class				Player : public Entity
  {
  public:
    enum			Direction { EAST, NORTH, WEST, SOUTH };
    enum			Side { LEFT, RIGHT };

  private:
    sf::Vector2i		_curPos;
    Direction			_curDir;

  public:
    Player(sf::Texture const&, sf::Vector2i const&, Direction);
    virtual ~Player();

    void			turn(Side);
    void			moveForward(sf::Vector2i const&);
  };
}

#endif /* !PLAYER_HPP_ */
