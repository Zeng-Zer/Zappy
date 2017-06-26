#ifndef PLAYER_HPP_
# define PLAYER_HPP_

# include <string>
# include <exception>
# include <SFML/Graphics.hpp>

class				Player
{
private:
  sf::Texture			_texture;
  sf::Sprite			_sprite;
  sf::Vector2u			_size;
  float				_speed;

public:
  Player();
  ~Player();

  void				load(std::string const&, sf::Vector2u const&, sf::Vector2u const&);
  void				move(float const, float const, unsigned int const);
  
  sf::Vector2f const		&getPosition() const;
  sf::Sprite const		&getSprite() const;

  void				setPosition(unsigned int const, unsigned int const);
  void				setTextureRect(sf::IntRect const&);
};

# endif /* !PLAYER_HPP_ */
