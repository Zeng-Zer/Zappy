#ifndef IMAGEHANDLER_HPP_
# define IMAGEHANDLER_HPP_

# include <SFML/Graphics.hpp>
# include <map>
# include <tuple>

namespace			zap
{
  class					ImageHandler
  {
  public:
    enum				Texture
      {
	PLAYER, RESSOURCE, MAP
      };

  private:
    std::map<Texture, std::tuple<sf::Texture, sf::Vector2i>>	_textures;

  public:
    ImageHandler();
    ~ImageHandler();

    void				load();
    sf::Texture				getTexture(Texture);
    sf::Vector2i const			&getSetSize(Texture);
  };
}

#endif /* !IMAGEHANDLER_HPP_ */
