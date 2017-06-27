#ifndef RESOURCE_HPP_
# define RESOURCE_HPP_

# include <string>
# include <map>

namespace Resource {

  enum Resource {
    PLAYER = 0,
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    UNKNOWN,
  };

  extern const std::map<Resource, std::string> resourceMap;

  Resource stringToResource(std::string const& str);
  std::string resourceToString(Resource res);
}

#endif /* !RESOURCE_HPP_ */
