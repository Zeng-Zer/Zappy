#ifndef IMAGEHANDLER_HPP_
# define IMAGEHANDLER_HPP_

# include <SFML/Graphics.hpp>
# include <map>
# include <tuple>
# include <memory>

class					ImageHandler
{
public:
  enum					Texture { PLAYER, RESOURCE, MAP };

private:
  ImageHandler();

  std::map<Texture, std::tuple<sf::Texture, sf::Vector2i>>	_textures;
  static std::unique_ptr<ImageHandler>				_instance;

public:
  ~ImageHandler();

  static ImageHandler			&getInstance();
  sf::Texture createTexture(std::string const& path);

  sf::Texture const			&getTexture(Texture) const;
  sf::Vector2i const			&getSetSize(Texture) const;
};

#endif /* !IMAGEHANDLER_HPP_ */
