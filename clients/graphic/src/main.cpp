#include <iostream>
#include "Error.hpp"
#include <SFML/Graphics.hpp>
#include "ImageHandler.hpp"
#include "AudioHandler.hpp"
#include "TileMap.hpp"
#include "Player.hpp"
#include "Resource.hpp"
#include "Logic.hpp"

int			main()
{
  zap::Logic		logic(sf::Vector2i(1600, 900));

  try
    {
      struct		ImageHandlerInit
      {
	ImageHandlerInit(){ zap::ImageHandler::initImageHandler(); }
	~ImageHandlerInit(){ zap::ImageHandler::destroyImageHandler(); }
      }			ImageHandlerIniter;

      struct		AudioHandlerInit
      {
	AudioHandlerInit(){ zap::AudioHandler::initAudioHandler(); }
	~AudioHandlerInit(){ zap::AudioHandler::destroyAudioHandler(); }
      }			AudiHandlerIniter;

      logic.createMap(sf::Vector2i(10, 10), zap::TileMap::GRASS);
      logic.createPlayer(sf::Vector2i(0, 0), zap::Player::EAST);
      logic.createResource(sf::Vector2i(0, 1), zap::Resource::FOOD);
      logic.createResource(sf::Vector2i(1, 0), zap::Resource::LINEMATE);
      logic.createResource(sf::Vector2i(2, 0), zap::Resource::THYSTAME);
      logic.createResource(sf::Vector2i(0, 2), zap::Resource::PHIRAS);

      while (logic.isOpen())
	{
	  logic.eventLoop();
	  logic.clear();
	  logic.drawAll();
	  logic.display();
	}
    }
  catch (zap::Error e)
    {
      std::cerr << e.what() << std::endl;
    }
  return (0);
}
