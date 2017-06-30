#ifndef RESOURCE_HPP_
# define RESOURCE_HPP_

# include <SFML/Graphics.hpp>

namespace			zap
{
  class				Resource : public sf::Drawable, public sf::Transformable
  {
  public:
    enum			Type { FOOD, LINEMATE, DERAUMERE, SIBUR, MENDIANE, PHIRAS, THYSTAME };

  private:
    sf::Sprite			_sprite;
    sf::Texture			_texture;
    sf::Vector2i		_setSize;

    virtual void		draw(sf::RenderTarget&, sf::RenderStates) const;

  public:
    Resource();
    virtual ~Resource();

    void			load(sf::Texture const&, sf::Vector2i const&, Type);
  };
}

#endif /* !RESOURCE_HPP_ */
