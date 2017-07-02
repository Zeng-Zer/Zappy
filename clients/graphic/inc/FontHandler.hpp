#ifndef FONTHANDLER_HPP_
# define FONTHANDLER_HPP_

# include <SFML/Graphics.hpp>
# include <map>
# include <memory>

class					FontHandler
{
public:
  enum					Font { ROBOTO, ROBOTO_I, HAMBURGER };

private:
  FontHandler();

  std::map<Font, sf::Font>		_fonts;
  static std::unique_ptr<FontHandler>	_instance;

public:
  ~FontHandler();

  static FontHandler			&getInstance();
  static void				initFontHandler();

  sf::Font const			&getFont(Font) const;
};

#endif /* !FONTHANDLER_HPP_ */
