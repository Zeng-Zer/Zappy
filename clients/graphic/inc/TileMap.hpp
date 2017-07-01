#ifndef TILEMAP_HPP_
# define TILEMAP_HPP_

# include <SFML/Graphics.hpp>
# include <map>
# include <vector>
# include "Entity.hpp"

namespace			zap
{
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
    sf::Texture			_tileset;
    sf::Vector2i		_setSize;
    sf::Vector2i		_tileSize;
    std::map<sf::Vector2i, std::vector<Entity*>>	_grid;

    virtual void		draw(sf::RenderTarget&, sf::RenderStates) const;

  public:
    TileMap();
    virtual ~TileMap();

    void			load(sf::Texture const&, sf::Vector2i const&, int const*, sf::Vector2i const&);
    sf::Vector2i const		&getTileSize() const;

    static int			*createMap(sf::Vector2i const&, Terrain);
  };
}

#endif /* !TILEMAP_HPP_ */
