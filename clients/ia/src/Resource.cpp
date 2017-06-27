#include "Resource.hpp"

const std::map<Resource::Resource, std::string> Resource::resourceMap = {
  {Resource::PLAYER, "player"},
  {Resource::FOOD, "food"},
  {Resource::LINEMATE, "linemate"},
  {Resource::DERAUMERE, "deraumere"},
  {Resource::SIBUR, "sibur"},
  {Resource::MENDIANE, "mendiane"},
  {Resource::PHIRAS, "phiras"},
  {Resource::THYSTAME, "thystame"},
  {Resource::UNKNOWN, "unknown"}
};

Resource::Resource stringToResource(std::string const& str) {
  int i = 0;
  while (i < 7) {
    if (Resource::resourceMap.at(static_cast<Resource::Resource>(i)) == str) {
      return static_cast<Resource::Resource>(i);
    }
    i++;
  }
  return (Resource::UNKNOWN);
}

std::string resourceToString(Resource::Resource res) {
  return Resource::resourceMap.at(res);
}
