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
};

const std::map<std::string, Resource::Resource> Resource::resourceString = {
  {"player", Resource::PLAYER},
  {"food", Resource::FOOD},
  {"linemate", Resource::LINEMATE},
  {"deraumere", Resource::DERAUMERE},
  {"sibur", Resource::SIBUR},
  {"mendiane", Resource::MENDIANE},
  {"phiras", Resource::PHIRAS},
  {"thystame", Resource::THYSTAME},
};

Resource::Resource Resource::stringToResource(std::string const& str) {
  if (resourceString.count(str) > 0) {
    return resourceString.at(str);
  } else {
    return Resource::UNKNOWN;
  }
}

std::string Resource::resourceToString(Resource res) {
  if (resourceMap.count(res) > 0) {
    return resourceMap.at(res);
  } else {
    return "";
  }
}
