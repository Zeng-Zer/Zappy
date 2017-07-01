#ifndef TILEMAP_HPP_
# define TILEMAP_HPP_

# include <SFML/Graphics.hpp>
# include <map>
# include <vector>
# include <array>
# include <tuple>
# include "ImageHandler.hpp"
# include "Resource.hpp"

typedef std::array<unsigned int, 7>	resource_list;

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
  std::map<int, std::vector<Entity*>>	_grid;
  bool				_isGrid;

  virtual void			draw(sf::RenderTarget&, sf::RenderStates) const;

public:
  TileMap();
  virtual ~TileMap();

  void				load(sf::Texture const&, sf::Vector2i const&, int const*, sf::Vector2i const&);
  sf::Vector2i const		&getTileSize() const;
  void				grid();

  static int			*createMap(sf::Vector2i const&, Terrain);

  sf::Vector2f			mapToCoords(sf::Vector2i const&) const;
  void				setMapContent(sf::Vector2i const&, resource_list);
  void				update(sf::RenderWindow*);
};

#endif /* !TILEMAP_HPP_ */
