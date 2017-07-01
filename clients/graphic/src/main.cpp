#include <iostream>
#include "Error.hpp"
#include <SFML/Graphics.hpp>
#include "ImageHandler.hpp"
#include "AudioHandler.hpp"
#include "TileMap.hpp"
#include "Player.hpp"
#include "Resource.hpp"
#include "Logic.hpp"

#include <vector>

int			main()
{
  Logic			logic(sf::Vector2i(1600, 900));

  try
    {
      struct		ImageHandlerInit
      {
      	ImageHandlerInit(){ ImageHandler::initImageHandler(); }
      	~ImageHandlerInit(){ ImageHandler::destroyImageHandler(); }
      }			ImageHandlerIniter;

      struct		AudioHandlerInit
      {
      	AudioHandlerInit(){ AudioHandler::initAudioHandler(); }
      	~AudioHandlerInit(){ AudioHandler::destroyAudioHandler(); }
      }			AudiHandlerIniter;

      logic.createMap(sf::Vector2i(10, 10), TileMap::GRASS);
      logic.createPlayer(sf::Vector2i(0, 0), Player::EAST);
      logic.createResource(sf::Vector2i(0, 1), Resource::FOOD);
      logic.createResource(sf::Vector2i(1, 0), Resource::LINEMATE);
      logic.createResource(sf::Vector2i(2, 0), Resource::THYSTAME);
      logic.createResource(sf::Vector2i(0, 2), Resource::PHIRAS);

      while (logic.isOpen())
      	{
      	  logic.eventLoop();
      	  logic.clear();
      	  logic.drawAll();
      	  logic.display();
      	}
    }
  catch (Error e)
    {
      std::cerr << e.what() << std::endl;
    }
  return (0);
}
