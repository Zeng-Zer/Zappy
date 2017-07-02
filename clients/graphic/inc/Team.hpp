#ifndef TEAM_HPP_
# define TEAM_HPP_

# include <SFML/Graphics.hpp>
# include <cstdlib>
# include <string>

struct			Team
{
  Team(std::string const&);
  std::string		name;
  sf::Color		color;
};

#endif /* !TEAM_HPP_ */
