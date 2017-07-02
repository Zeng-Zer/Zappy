#ifndef TILEMAP_HPP_
# define TILEMAP_HPP_

# include <SFML/Graphics.hpp>
# include <map>
# include <vector>
# include <array>
# include <tuple>
# include "ImageHandler.hpp"
# include "Resource.hpp"
# include "Egg.hpp"

typedef std::array<unsigned int, 7>	resource_list;

class				Egg;
class			        Resource;
class				TileMap : public sf::Drawable, public sf::Transformable
{
public:
  enum			Terrain
    {
      DIRT = 0,
      GRASS = 40
    };

private:
  sf::VertexArray		_vertices;
  std::vector<sf::VertexArray>	_lineGrid;
  sf::Texture			_tileset;
  sf::Vector2i			_setSize;
  sf::Vector2i			_tileSize;
  sf::Vector2i			_map_size;
  bool				_isGrid;
  std::map<int, std::vector<Resource*>>	_grid;
  std::map<int, std::vector<Egg*>>	_eggs;

  virtual void			draw(sf::RenderTarget&, sf::RenderStates) const;

public:
  TileMap();
  virtual ~TileMap();

  void				load(sf::Texture const&, sf::Vector2i const&, int const*);
  void				setMapSize(sf::Vector2i const&);
  sf::Vector2i const		&getTileSize() const;
  void				grid();

  static int			*createMap(sf::Vector2i const&, Terrain);

  sf::Vector2f			mapToCoords(sf::Vector2i const&) const;
  void				setMapContent(sf::Vector2i const&, resource_list);
  void				setMapContent(sf::Vector2i const&);
  void				removeMapContent(sf::Vector2i const&, Resource::Type);
  void				update(sf::RenderWindow*);
};

#endif /* !TILEMAP_HPP_ */
