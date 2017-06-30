#include "Error.hpp"
#include "ImageHandler.hpp"

std::unique_ptr<zap::ImageHandler>	zap::ImageHandler::_instance(nullptr);

zap::ImageHandler::ImageHandler() {
  if (!std::get<0>(_textures[PLAYER]).loadFromFile("./media/images/player.png"))
    throw(zap::Error());
  std::get<0>(_textures[PLAYER]).setSmooth(true);
  std::get<1>(_textures[PLAYER]) = sf::Vector2i(14, 10);
  if (!std::get<0>(_textures[RESSOURCE]).loadFromFile("./media/images/ressource.png"))
    throw(zap::Error());
  std::get<0>(_textures[RESSOURCE]).setSmooth(true);
  std::get<1>(_textures[RESSOURCE]) = sf::Vector2i(15, 15);
  if (!std::get<0>(_textures[MAP]).loadFromFile("./media/images/map.png"))
    throw(zap::Error());
  std::get<0>(_textures[MAP]).setSmooth(true);
  std::get<1>(_textures[MAP]) = sf::Vector2i(9, 9);
}

zap::ImageHandler	&zap::ImageHandler::getInstance() { return (*_instance); }

void			zap::ImageHandler::initImageHandler()
{
  _instance.reset(new ImageHandler());
}

void			zap::ImageHandler::destroyImageHandler()
{
  _instance.reset(nullptr);
}

sf::Texture		zap::ImageHandler::getTexture(Texture t) {return (std::get<0>(_textures[t]));}
sf::Vector2i const	&zap::ImageHandler::getSetSize(Texture t) {return (std::get<1>(_textures[t]));}
