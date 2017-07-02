#include "Error.hpp"
#include "ImageHandler.hpp"

std::unique_ptr<ImageHandler>	ImageHandler::_instance(nullptr);

sf::Texture ImageHandler::createTexture(std::string const& path) {
  sf::Texture texture;
  if (!texture.loadFromFile(path)) {
    throw Error();
  }
  texture.setSmooth(true);
  return texture;
}

ImageHandler::ImageHandler() {
  _textures[PLAYER] = {
    createTexture("./media/images/player.png"), sf::Vector2i(14, 10)
  };
  _textures[RESOURCE] = {
    createTexture("./media/images/ressource.png"), sf::Vector2i(15, 15)
  };
  _textures[MAP] = {
    createTexture("./media/images/map.png"), sf::Vector2i(9, 9)
  };
}

ImageHandler::~ImageHandler() {}

ImageHandler		&ImageHandler::getInstance() {
  if (!_instance.get()) {
    _instance.reset(new ImageHandler());
  }
  return *_instance;
}

sf::Texture		ImageHandler::getTexture(Texture t) const {
  return (std::get<0>(_textures.at(t)));
}

sf::Vector2i const	&ImageHandler::getSetSize(Texture t) const {
  return (std::get<1>(_textures.at(t)));
}
