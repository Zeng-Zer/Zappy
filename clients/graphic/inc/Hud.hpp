#ifndef HUD_HPP_
# define HUD_HPP_

# include <SFML/Graphics.hpp>
# include "ImageHandler.hpp"

class				Hud : public sf::View
{
private:
  sf::RectangleShape		_bg;
  sf::Vector2f			_center;

public:
  Hud(sf::Vector2f const& = sf::Vector2f(5000, 0));
  ~Hud();

  void				construct();
  void				update(sf::RenderWindow*) const;
};

#endif /* !HUD_HPP_ */
