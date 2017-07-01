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

      logic.setMapSize(sf::Vector2i(10, 10));
      logic.createMap(TileMap::GRASS);

      resource_list	l = {{1, 1, 1, 1, 1, 1, 1}};
      logic.setMapContent(sf::Vector2i(9, 0), l);
      logic.setMapContent(sf::Vector2i(0, 0), l);
      logic.setMapContent(sf::Vector2i(4, 4), l);
      logic.setMapContent(sf::Vector2i(1, 6), l);
      logic.setMapContent(sf::Vector2i(2, 2), l);
      logic.setMapContent(sf::Vector2i(3, 3), l);
      logic.setMapContent(sf::Vector2i(6, 7), l);

      logic.createPlayer(sf::Vector2i(3, 8), 3);

      while (logic.isOpen())
      	{
      	  logic.eventLoop();
      	  logic.clear();
	  logic.update();
      	  logic.display();
      	}
    }
  catch (Error e)
    {
      std::cerr << e.what() << std::endl;
    }
  return (0);
}
