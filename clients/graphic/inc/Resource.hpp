#ifndef RESOURCE_HPP_
# define RESOURCE_HPP_

# include <SFML/Graphics.hpp>
# include "Entity.hpp"

class				Resource : public Entity
{
public:
  enum				Type { FOOD, LINEMATE, DERAUMERE, SIBUR, MENDIANE, PHIRAS, THYSTAME };

private:
  Type				_type;
  unsigned int			_opacity;
  
public:
  Resource(sf::Texture const&, sf::Vector2i const&, Type);
  virtual ~Resource();

  Type const			&getType() const;
  unsigned int			getOpacity() const;

  void				setOpacity(unsigned int const);
};

#endif /* !RESOURCE_HPP_ */
