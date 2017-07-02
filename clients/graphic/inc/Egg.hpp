#ifndef EGG_HPP_
# define EGG_HPP_

# include <SFML/Graphics.hpp>
# include "TileMap.hpp"
# include "Entity.hpp"

class			TileMap;
class			Egg : public Entity
{
private:
  sf::Vector2i		_curPos;

public:
  Egg(sf::Texture const&, sf::Vector2i const&);
  virtual ~Egg();

  void			setPosOnGrid(sf::Vector2i const&, TileMap const&);
};

#endif /* !EGG_HPP_ */
