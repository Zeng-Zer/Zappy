#ifndef TILEMAP_HPP_
# define TILEMAP_HPP_

# include <string>
# include <SFML/Graphics.hpp>

class				TileMap : public sf::Drawable, public sf::Transformable
{
private:
  sf::VertexArray		_vertices;
  sf::Texture			_tileset;
  sf::Vector2i			_tileSize;

  virtual void		draw(sf::RenderTarget&, sf::RenderStates) const;

public:
  TileMap();
  ~TileMap();

  bool			load(std::string const&, sf::Vector2i const&, int const*, sf::Vector2i const&);

  sf::Vector2i const	&getTileSize() const;
};

#endif /* !TILEMAP_HPP_ */
