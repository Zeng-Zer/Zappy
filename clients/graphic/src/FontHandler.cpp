#include "Error.hpp"
#include "FontHandler.hpp"

std::unique_ptr<FontHandler>	FontHandler::_instance(nullptr);

FontHandler::FontHandler() {
  if (!_fonts[ROBOTO].loadFromFile("./media/fonts/Roboto-Light.ttf"))
    throw(Error());
  if (!_fonts[ROBOTO_I].loadFromFile("./media/fonts/Roboto-LightItalic.ttf"))
    throw(Error());
  if (!_fonts[HAMBURGER].loadFromFile("./media/fonts/hamburger_heaven.ttf"))
    throw(Error());
}

FontHandler::~FontHandler() {}

FontHandler			&FontHandler::getInstance() {
  if (!_instance.get())
    _instance.reset(new FontHandler);
  return (*_instance);
}

sf::Font const			&FontHandler::getFont(Font f) const {
  return (_fonts.at(f));
}
