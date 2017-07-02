#include "Error.hpp"
#include "ImageHandler.hpp"

ImageHandler	ImageHandler::_instance;

sf::Texture ImageHandler::createTexture(std::string const& path) {
  sf::Texture texture;
  if (!texture.loadFromFile(path)) {
    throw Error();
  }
  texture.setSmooth(true);
  return texture;
}

ImageHandler::ImageHandler() {
  // _textures[PLAYER] = {
  //   createTexture("./media/images/player.png"), sf::Vector2i(14, 10)
  // };
  // exit(1);
  // _textures[RESOURCE] = {
  //   createTexture("./media/images/ressource.png"), sf::Vector2i(15, 15)
  // };
  // _textures[MAP] = {
  //   createTexture("./media/images/map.png"), sf::Vector2i(9, 9)
  // };

  if (!std::get<0>(_textures[PLAYER]).loadFromFile("./media/images/player.png"))
    throw(Error());
  std::get<0>(_textures[PLAYER]).setSmooth(true);
  std::get<1>(_textures[PLAYER]) = sf::Vector2i(14, 10);
  if (!std::get<0>(_textures[RESOURCE]).loadFromFile("./media/images/ressource.png"))
    throw(Error());
  std::get<0>(_textures[RESOURCE]).setSmooth(true);
  std::get<1>(_textures[RESOURCE]) = sf::Vector2i(15, 15);
  if (!std::get<0>(_textures[MAP]).loadFromFile("./media/images/map.png"))
    throw(Error());
  std::get<0>(_textures[MAP]).setSmooth(true);
  std::get<1>(_textures[MAP]) = sf::Vector2i(9, 9);
}

ImageHandler::~ImageHandler() {}

ImageHandler		&ImageHandler::getInstance() {
  return _instance;
}

sf::Texture		ImageHandler::getTexture(Texture t) const {
  return (std::get<0>(_textures.at(t)));
}

sf::Vector2i const	&ImageHandler::getSetSize(Texture t) const {
  return (std::get<1>(_textures.at(t)));
}
