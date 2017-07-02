#include "TileMap.hpp"

TileMap::TileMap() : _isGrid(false)
{
  _map_size.x = 1;
  _map_size.y = 1;
}

TileMap::~TileMap() {}

void			TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  states.transform *= getTransform();
  states.texture = &_tileset;
  target.draw(_vertices, states);
  if (_isGrid == true)
    for (unsigned int i = 0; i < _lineGrid.size(); i++)
      target.draw(_lineGrid[i], states);
}

void			TileMap::load(sf::Texture const &tileset, sf::Vector2i const &setSize, int const *tiles)
{
  unsigned int	        x, y, tileNb;
  sf::Vertex		*quad;
  sf::Vector2f		tmp;
  int			vSize = _map_size.x * _map_size.y * 4;

  _tileset = tileset;
  _tileSize.x = _tileset.getSize().x / setSize.x;
  _tileSize.y = _tileset.getSize().y / setSize.y;
  _vertices.setPrimitiveType(sf::Quads);
  _vertices.resize(vSize);
  for (int i = 0; i < _map_size.y; i++)
    {
      tmp.x = -i * _tileSize.x / 2;
      tmp.y = i * _tileSize.y / 2;
      for (int j = 0; j < _map_size.x; j++)
	{
	  tileNb = tiles[j + i * _map_size.x];
	  x = tileNb % (_tileset.getSize().x / _tileSize.x);
	  y = tileNb / (_tileset.getSize().x / _tileSize.x);
	  quad = &_vertices[(j + i * _map_size.x) * 4];

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

void			TileMap::grid()
{
  int			vSize = _vertices.getVertexCount() / 4;
  sf::Vertex		*quad;

  _isGrid = true;
  for (int i = 0; i < vSize; i++)
    _lineGrid.push_back(sf::VertexArray(sf::LineStrip, 4));
  for (int i = 0; i < vSize; i++)
    {
      quad = &_vertices[i * 4];

      _lineGrid[i][0].position = quad[0].position;
      _lineGrid[i][1].position = quad[1].position;
      _lineGrid[i][2].position = quad[2].position;
      _lineGrid[i][3].position = quad[3].position;

      _lineGrid[i][0].color = sf::Color::White;
      _lineGrid[i][1].color = sf::Color::White;
      _lineGrid[i][2].color = sf::Color::White;
      _lineGrid[i][3].color = sf::Color::White;
    }
}

void			TileMap::setMapSize(sf::Vector2i const &s) { _map_size = s; }

sf::Vector2i const	&TileMap::getTileSize() const {return (_tileSize);}

int			*TileMap::createMap(sf::Vector2i const &size, Terrain t)
{
  int			*lvl = new int [size.x * size.y];

  for (int i = 0; i < size.y; i++)
    for (int j = 0; j < size.x; j++)
      lvl[j + i * size.x] = t;
  return (lvl);
}

sf::Vector2f	        TileMap::mapToCoords(sf::Vector2i const &p) const
{
  sf::Vector2f		v;
  sf::Vector2i	        map = getTileSize();

  v.x = (map.x / 2) * (p.x - p.y);
  v.y = (map.y / 2) * (p.x + p.y + 1);
  return (v);
}

void			TileMap::setMapContent(sf::Vector2i const &p, resource_list l)
{
  sf::Vector2i		pos;
  Entity		*e;
  std::vector<Entity*>	v;

  for (unsigned int i = 0; i < 7; i++)
    for (unsigned int j = 0; j < l[i]; j++)
      {
        e = new Resource(ImageHandler::getInstance().getTexture(ImageHandler::RESSOURCE), ImageHandler::getInstance().getSetSize(ImageHandler::RESSOURCE), static_cast<Resource::Type>(i));
        e->scale(sf::Vector2f(0.5, 0.5));
        e->setPosition(mapToCoords(p));
	pos.y = rand() % (_tileSize.y - 8) + 8;
	if (pos.y <= _tileSize.y / 2)
	  pos.x = e->getPosition().x - _tileSize.x / 2 + rand() % ((pos.y - 8) * 4 + 1) + 64 - (pos.y - 8) * 2;
	else
	  pos.x = e->getPosition().x - _tileSize.x / 2 + rand() % ((_tileSize.y - pos.y) * 4 + 1) + 64 - (_tileSize.y - pos.y) * 2;
	pos.y += e->getPosition().y - _tileSize.y / 2;
	e->setPosition(e->adaptCoords(static_cast<sf::Vector2f>(pos)));
	v.push_back(e);
      }
  _grid[(p.y + p.x * _map_size.x)] = v;
}

#include <iostream>

void			TileMap::update(sf::RenderWindow *window)
{
  window->draw(*this);
  for (std::map<int, std::vector<Entity*>>::iterator it = _grid.begin(); it != _grid.end(); ++it)
    for (unsigned int i = 0; i < std::get<1>(*it).size(); i++)
      window->draw(*std::get<1>(*it)[i]);
}
