#ifndef ENTITY_HPP_
# define ENTITY_HPP_

# include <SFML/Graphics.hpp>

class				Entity : public sf::Drawable, public sf::Transformable
{
protected:
  sf::Sprite			_sprite;
  sf::Texture			_texture;
  sf::Vector2i			_setSize;

  virtual void			draw(sf::RenderTarget&, sf::RenderStates) const;

public:
  Entity(sf::Texture const&, sf::Vector2i const&);
  virtual ~Entity();

  sf::Vector2i const		&getSetSize() const;
  sf::Sprite const		&getSprite() const;
  sf::Vector2f			adaptCoords(sf::Vector2f const&) const;
};

#endif /* !ENTITY_HPP_ */
