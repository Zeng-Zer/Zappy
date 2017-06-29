#ifndef RESSOURCE_HPP_
# define RESSOURCE_HPP_

# include <SFML/Graphics.hpp>

namespace			zap
{
  class				Ressource : public sf::Drawable, public sf::Transformable
  {
  private:
    sf::Sprite			_sprite;
    sf::Texture			_texture;
    sf::Vector2i		_setSize;

    virtual void		draw(sf::RenderTarget&, sf::RenderStates) const;

  public:
    Ressource();
    virtual ~Ressource();

    void			load(sf::Texture const&, sf::Vector2i const&);
  };
}

#endif /* !RESSOURCE_HPP_ */
