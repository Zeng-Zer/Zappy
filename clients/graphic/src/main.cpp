#include <SFML/Graphics.hpp>
#include <iostream>
#include "Error.hpp"
#include "Param.hpp"
#include "Network.hpp"
#include "Protocol.hpp"
#include "ImageHandler.hpp"
#include "AudioHandler.hpp"
#include "TileMap.hpp"
#include "Player.hpp"
#include "Resource.hpp"
#include "Logic.hpp"

int main(int argc, char **argv)
{
  Param args(argc, argv);
  Logic logic(sf::Vector2i(1600, 900));

  try
    {
      ImageHandler::initImageHandler();
      AudioHandler::initAudioHandler();

      Network::initNetwork(args.getPort(), args.getHost());
      if (Network::getInstance().recvMsg() != "WELCOME") {
	NetworkException("First message is not \"WELCOME\"");
      }
      Protocol::initDataGame(logic);
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
