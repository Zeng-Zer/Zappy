#ifndef TILEMAP_HPP_
# define TILEMAP_HPP_

# include <SFML/Graphics.hpp>

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
    sf::VertexArray		_lineStrip;
    sf::Texture			_tileset;
    sf::Vector2i		_setSize;
    sf::Vector2i		_tileSize;
    bool			_quad;

    virtual void		draw(sf::RenderTarget&, sf::RenderStates) const;

  public:
    TileMap();
    virtual ~TileMap();

    void			load(sf::Texture const&, sf::Vector2i const&, int const*, sf::Vector2i const&);
    sf::Vector2i const		&getTileSize() const;
    void			quad();

    static int			*createMap(sf::Vector2i const&, Terrain);
  };
}

#endif /* !TILEMAP_HPP_ */
