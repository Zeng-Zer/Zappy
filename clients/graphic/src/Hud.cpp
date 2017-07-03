#include "Hud.hpp"

Hud::Hud(sf::Vector2f const &f) : _center(f)
{
  setCenter(f);
}

Hud::~Hud() {}

void		Hud::construct()
{
  _bg.setTexture(&ImageHandler::getInstance().getTexture(ImageHandler::HUD));
  _bg.setSize(sf::Vector2f(100, 100));
  _bg.setPosition(sf::Vector2f(_center.x - getSize().x / 2, _center.y - getSize().y / 2));
}

void		Hud::update(sf::RenderWindow *window) const
{
  window->draw(_bg);
}
