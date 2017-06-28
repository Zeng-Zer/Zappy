#include "functions.hpp"

sf::Vector2i		coordsToMapCoords(sf::Vector2i const &tileSize, sf::Vector2i const &coords)
{
  sf::Vector2i		p;

  p.x = coords.x * tileSize.x / 2 - coords.y * tileSize.x / 2;
  p.y = coords.x * tileSize.y / 2 + (coords.y + 1) * tileSize.y / 2;
  return (p);
}
