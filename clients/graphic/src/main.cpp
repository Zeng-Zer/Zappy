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

      logic.setMapSize(sf::Vector2i(1, 1));
      logic.createMap(TileMap::GRASS);

      resource_list	l = {{1, 1, 1, 1, 1, 1, 1}};
      logic.setMapContent(sf::Vector2i(0, 0), l);

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
