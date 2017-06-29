#ifndef PLAYER_HPP_
# define PLAYER_HPP_

# include <SFML/Graphics.hpp>

namespace			zap
{
  class				Player : public sf::Drawable, public sf::Transformable
  {
  private:
    sf::Sprite			_sprite;
    sf::Texture			_texture;
    sf::Vector2i		_setSize;

    virtual void		draw(sf::RenderTarget&, sf::RenderStates) const;

  public:
    Player();
    virtual ~Player();

    void			load(sf::Texture const&, sf::Vector2i const&);
  };
}

#endif /* !PLAYER_HPP_ */
