#include "TileMap.hpp"

zap::TileMap::TileMap() {}
zap::TileMap::~TileMap() {}

void			zap::TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = &_tileset;
  target.draw(_vertices, states);
}

void			zap::TileMap::load(sf::Texture const &tileset, sf::Vector2i const &setSize, int const *tiles, sf::Vector2i const &map_size)
{
  unsigned int		        x, y, tileNb;
  sf::Vertex			*quad;
  sf::Vector2f			tmp;

  _tileset = tileset;
  _tileSize.x = _tileset.getSize().x / setSize.x;
  _tileSize.y = _tileset.getSize().y / setSize.y;
  _vertices.setPrimitiveType(sf::Quads);
  _vertices.resize(map_size.x * map_size.y * 4);
  for (int i = 0; i < map_size.y; i++)
    {
      tmp.x = -i * _tileSize.x / 2;
      tmp.y = i * _tileSize.y / 2;
      for (int j = 0; j < map_size.x; j++)
	{
	  tileNb = tiles[j + i * map_size.x];
	  x = tileNb % (_tileset.getSize().x / _tileSize.x);
	  y = tileNb / (_tileset.getSize().x / _tileSize.x);
	  quad = &_vertices[(j + i * map_size.x) * 4];

	  quad[0].position = sf::Vector2f(tmp.x, tmp.y);
	  quad[1].position = sf::Vector2f(tmp.x + _tileSize.x / 2, tmp.y + _tileSize.y / 2);
	  quad[2].position = sf::Vector2f(tmp.x, tmp.y + _tileSize.y);
	  quad[3].position = sf::Vector2f(tmp.x - _tileSize.x / 2, tmp.y + _tileSize.y / 2);

	  quad[0].texCoords = sf::Vector2f(x * _tileSize.x + _tileSize.x / 2, y * _tileSize.y);
	  quad[1].texCoords = sf::Vector2f((x + 1) * _tileSize.x, y * _tileSize.y + _tileSize.y / 2);
	  quad[2].texCoords = sf::Vector2f((x + 1) * _tileSize.x - _tileSize.x / 2, (y + 1) * _tileSize.y);
	  quad[3].texCoords = sf::Vector2f(x * _tileSize.x, (y + 1) * _tileSize.y - _tileSize.y / 2);

	  tmp.x = tmp.x + _tileSize.x / 2;
	  tmp.y = tmp.y + _tileSize.y / 2;
	}
    }
}

sf::Vector2i const		&zap::TileMap::getTileSize() const {return (_tileSize);}

int				*zap::TileMap::createMap(sf::Vector2i const &size, Terrain t)
{
  int				*lvl = new int [size.x * size.y];

  for (int i = 0; i < size.y; i++)
    for (int j = 0; j < size.x; j++)
      lvl[j + i * size.x] = t;
  return (lvl);
}
