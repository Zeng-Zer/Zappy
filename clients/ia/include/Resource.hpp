#ifndef RESOURCE_HPP_
# define RESOURCE_HPP_

# include <string>

enum Resource {
  PLAYER,
  FOOD,
  LINEMATE,
  DERAUMERE,
  SIBUR,
  MENDIANE,
  PHIRAS,
  THYSTAME,
};

Resource stringToResource(std::string const& str);

std::string resourceToString(Resource res);

#endif /* !RESOURCE_HPP_ */
