#include "Team.hpp"

Team::Team(std::string const &n) : name(n)
{
  color = sf::Color(rand() % 255, rand() % 255, rand() % 255);
}
