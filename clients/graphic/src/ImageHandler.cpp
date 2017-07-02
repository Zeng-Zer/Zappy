#include "Error.hpp"
#include "ImageHandler.hpp"

std::unique_ptr<ImageHandler>	ImageHandler::_instance(nullptr);

ImageHandler::ImageHandler() {
  _textures = {
    {PLAYER, {sf::Texture(), sf::Vector2i(14, 10)}},
    {RESOURCE, {sf::Texture(), sf::Vector2i(15, 15)}},
    {MAP, {sf::Texture(), sf::Vector2i(9, 9)}}
  };
  if (!std::get<0>(_textures[PLAYER]).loadFromFile("./media/images/player.png"))
    throw(Error());
  std::get<0>(_textures[PLAYER]).setSmooth(true);
  if (!std::get<0>(_textures[RESOURCE]).loadFromFile("./media/images/ressource.png"))
    throw(Error());
  std::get<0>(_textures[RESOURCE]).setSmooth(true);
  if (!std::get<0>(_textures[MAP]).loadFromFile("./media/images/map.png"))
    throw(Error());
  std::get<0>(_textures[MAP]).setSmooth(true);
}

ImageHandler::~ImageHandler() {}

ImageHandler		&ImageHandler::getInstance() { return (*_instance); }

void			ImageHandler::initImageHandler()
{
  _instance.reset(new ImageHandler());
}

sf::Texture		ImageHandler::getTexture(Texture t) const {return (std::get<0>(_textures.at(t)));}
sf::Vector2i const	&ImageHandler::getSetSize(Texture t) const {return (std::get<1>(_textures.at(t)));}
