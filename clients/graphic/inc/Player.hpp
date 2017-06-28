#ifndef PLAYER_HPP_
# define PLAYER_HPP_

# include <string>
# include <exception>
# include <SFML/Graphics.hpp>
# include "TileMap.hpp"

class				Player
{
public:
  enum				Direction
    {
      EAST, NORTH, WEST, SOUTH
    };

private:
  sf::Texture			_texture;
  sf::Sprite			_sprite;
  sf::Vector2i			_size;
  sf::Vector2f			_scale;
  sf::Vector2f			_shiftedPos;
  sf::Vector2i			_curPos;
  Direction			_curDir;

public:
  Player();
  ~Player();


  void				load(std::string const&, sf::Vector2i const&, Player::Direction);
  void				move(float const, float const, int const);

  sf::Vector2f const		&getPosition() const;
  sf::Sprite const		&getSprite() const;
  sf::Vector2i const		&getSize() const;

  void				setPosition(sf::Vector2f const&);
  void				setTextureRect(sf::IntRect const&);
  void				setColor(sf::Color const&);

  void				scale(sf::Vector2f const&);
  void				setPosOnGrid(sf::Vector2i const&);
  void			        moveForward();
  void				turnLeft();
  void				turnRight();
  void				update(sf::Vector2i const&);
};

# endif /* !PLAYER_HPP_ */
