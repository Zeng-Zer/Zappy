#include "TileMap.hpp"

TileMap::TileMap()
{}

TileMap::~TileMap()
{}

void				TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = &_tileset;
  target.draw(_vertices, states);
}

bool				TileMap::load(std::string const &tileset, sf::Vector2u tileSize, int const *tiles, sf::Vector2u const &map_size, sf::Vector2u const &res)
{
  unsigned int		        x, y;
  unsigned int			tileNb;
  sf::Vertex			*quad;
  sf::Vector2f			tmp;

  (void)res;
  if (!_tileset.loadFromFile(tileset))
    return (false);
  _vertices.setPrimitiveType(sf::Quads);
  _vertices.resize(map_size.x * map_size.y * 4);
  for (unsigned int i = 0; i < map_size.y; i++)
    {
      tmp.x = tileSize.x / 2 - (i + 1) * tileSize.x / 2 + (tileSize.x / 2 * map_size.y);
      tmp.y = i * tileSize.y / 2;
      for (unsigned int j = 0; j < map_size.x; j++)
	{
	  tileNb = tiles[j + i * map_size.x];
	  x = tileNb % (_tileset.getSize().x / tileSize.x);
	  y = tileNb / (_tileset.getSize().x / tileSize.x);
	  quad = &_vertices[(j + i * map_size.x) * 4];

	  quad[0].position = sf::Vector2f(tmp.x, tmp.y);
	  quad[1].position = sf::Vector2f(tmp.x + tileSize.x / 2, tmp.y + tileSize.y / 2);
	  quad[2].position = sf::Vector2f(tmp.x, tmp.y + tileSize.y);
	  quad[3].position = sf::Vector2f(tmp.x - tileSize.x / 2, tmp.y + tileSize.y / 2);

	  quad[0].texCoords = sf::Vector2f(x * tileSize.x + tileSize.x / 2, y * tileSize.y);
	  quad[1].texCoords = sf::Vector2f((x + 1) * tileSize.x, y * tileSize.y + tileSize.y / 2);
	  quad[2].texCoords = sf::Vector2f((x + 1) * tileSize.x - tileSize.x / 2, (y + 1) * tileSize.y);
	  quad[3].texCoords = sf::Vector2f(x * tileSize.x, (y + 1) * tileSize.y - tileSize.y / 2);

	  tmp.x = tmp.x + tileSize.x / 2;
	  tmp.y = tmp.y + tileSize.y / 2;
	}
    }
  return (true);
}
