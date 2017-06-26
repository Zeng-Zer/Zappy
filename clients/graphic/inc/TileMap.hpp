#ifndef TILEMAP_HPP_
# define TILEMAP_HPP_

# include <string>
# include <SFML/Graphics.hpp>

class				TileMap : public sf::Drawable, public sf::Transformable
{
private:
  sf::VertexArray		_vertices;
  sf::Texture			_tileset;

  virtual void		draw(sf::RenderTarget&, sf::RenderStates) const;

public:
  TileMap();
  ~TileMap();

  bool			load(std::string const&, sf::Vector2u, int const*, sf::Vector2u const&, sf::Vector2u const&);
};

#endif /* !TILEMAP_HPP_ */
