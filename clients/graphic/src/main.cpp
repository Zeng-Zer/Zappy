#include <SFML/Graphics.hpp>
#include <iostream>
#include "Error.hpp"
#include "TileMap.hpp"
#include "Param.hpp"
#include "Network.hpp"
#include "Protocol.hpp"
#include "ImageHandler.hpp"
#include "AudioHandler.hpp"
#include "Player.hpp"
#include "Resource.hpp"
#include "Logic.hpp"


sf::Texture createTexture(std::string const& path) {
  sf::Texture texture;
  if (!texture.loadFromFile(path)) {
    throw Error();
  }
  texture.setSmooth(true);
  return texture;
}

int main(int argc, char **argv)
{
  Param args(argc, argv);
  Logic logic(sf::Vector2i(1600, 900));

 try
    {
      Network::initNetwork(args.getPort(), args.getHost());
      if (Network::getInstance().recvMsg() != "WELCOME") {
	NetworkException("First message is not \"WELCOME\"");
      }
      Protocol::initDataGame(logic);

      logic.addTeam("TeamA");

      while (logic.isOpen())
      	{
      	  logic.eventLoop();
	  logic.updateData();
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
