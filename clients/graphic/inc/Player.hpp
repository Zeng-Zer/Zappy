#ifndef PLAYER_HPP_
# define PLAYER_HPP_

# include <SFML/Graphics.hpp>

namespace			zap
{
  class				Player : public sf::Drawable, public sf::Transformable
  {
  public:
    enum			Direction { EAST, NORTH, WEST, SOUTH };
    enum			Side { LEFT, RIGHT };

  private:
    sf::Sprite			_sprite;
    sf::Texture			_texture;
    sf::Vector2i		_setSize;
    sf::Vector2i		_curPos;
    Direction			_curDir;

    virtual void		draw(sf::RenderTarget&, sf::RenderStates) const;

  public:
    Player();
    virtual ~Player();

    void			load(sf::Texture const&, sf::Vector2i const&, Direction);
    void			turn(Side);
    void			moveForward(sf::Vector2i const&);
  };
}

#endif /* !PLAYER_HPP_ */
