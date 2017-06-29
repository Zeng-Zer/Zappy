#include <iostream>
#include "Error.hpp"
#include <SFML/Graphics.hpp>
#include "ImageHandler.hpp"
#include "AudioHandler.hpp"
#include "TileMap.hpp"
#include "Player.hpp"
#include "Ressource.hpp"

static void		eventLoop(sf::RenderWindow &window)
{
  sf::Event		event;

  while (window.pollEvent(event))
    {
      switch (event.type)
	{
	case sf::Event::Closed:
	  window.close();
	  break ;

	case sf::Event::KeyPressed:
	  if (event.key.code == sf::Keyboard::Escape)
	    window.close();
	  break ;

	default :
	  break ;
	}
    }
}

int			main()
{
  sf::Vector2i		resolution(800, 480);
  sf::Vector2i		map_size(10, 10);
  sf::RenderWindow	window(sf::VideoMode(resolution.x, resolution.y), "Zappy");
  sf::View		view;
  zap::ImageHandler	imgh;
  zap::AudioHandler	audioh;
  zap::TileMap		map;
  zap::Player		player;
  zap::Ressource	ressource;

  try
    {
      imgh.load();
      audioh.load();
 
      map.load(imgh.getTexture(zap::ImageHandler::MAP), sf::Vector2i(9, 9), zap::TileMap::createMap(map_size), map_size);

      player.load(imgh.getTexture(zap::ImageHandler::PLAYER), imgh.getSetSize(zap::ImageHandler::PLAYER));
      player.setPosition(sf::Vector2f(0, 0));

      ressource.load(imgh.getTexture(zap::ImageHandler::RESSOURCE), imgh.getSetSize(zap::ImageHandler::RESSOURCE));
      ressource.setPosition(sf::Vector2f(100, 100));

      view.setSize(resolution.x, resolution.y);
      view.setViewport(sf::FloatRect(0, 0, 1, 1));
      view.setCenter(player.getPosition().x, player.getPosition().y);

      window.setView(view);
      while (window.isOpen())
	{
	  eventLoop(window);

	  window.clear();
	  window.draw(map);
	  window.draw(player);
	  window.draw(ressource);
	  window.display();
	}
    }
  catch (zap::Error e)
    {
      std::cerr << e.what() << std::endl;
    }
  return (0);
}
