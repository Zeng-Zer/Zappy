#ifndef TILEMAP_HPP_
# define TILEMAP_HPP_

# include <SFML/Graphics.hpp>
# include <map>
# include <vector>
# include <memory>
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
  enum				Terrain
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
  std::map<int, std::vector<std::shared_ptr<Resource>>>	_resources;

  virtual void			draw(sf::RenderTarget&, sf::RenderStates) const;

public:
  TileMap();
  virtual ~TileMap();

  void				load(sf::Texture const&, sf::Vector2i const&, std::shared_ptr<int>);
  void				setMapSize(sf::Vector2i const&);
  sf::Vector2i const		&getTileSize() const;
  void				grid();

  static std::shared_ptr<int>	createMap(sf::Vector2i const&, Terrain);

  sf::Vector2f			mapToCoords(sf::Vector2i const&) const;
  sf::Vector2i			randCoords(std::shared_ptr<Entity>) const;
  void				addResource(sf::Vector2i const&, Resource::Type);

  void			        removeResource(sf::Vector2i const&, Resource::Type);
  void				update(sf::RenderWindow*);
};

#endif /* !TILEMAP_HPP_ */
