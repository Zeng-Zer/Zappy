#ifndef RESSOURCE_HPP_
# define RESSOURCE_HPP_

# include <string>
# include <exception>
# include <SFML/Graphics.hpp>

class				Ressource
{
public:
  enum				Type
    {
      FOOD, LINEMATE, DERAUMERE, SIBUR, MENDIANE, PHIRAS, THYSTAME
    };

private:
  sf::Texture			_texture;
  sf::Sprite			_sprite;
  sf::Vector2i			_size;
  sf::Vector2f			_scale;
  sf::Vector2i			_curPos;

public:
  Ressource(std::string const&, sf::Vector2i const&, Ressource::Type);
  ~Ressource();

  void				load(std::string const&, sf::Vector2i const&, Ressource::Type);

  sf::Vector2f const		&getPosition() const;
  sf::Sprite const		&getSprite() const;
  sf::Vector2i const		&getSize() const;
  sf::Vector2f const		&getScale() const;

  void				setPosition(sf::Vector2f const&);
  void				setTextureRect(sf::IntRect const&);
  void				scale(sf::Vector2f const&);
};

#endif /* !RESSOURCE_HPP_ */
