#include "Level.hpp"

std::map<int, std::map<Resource, int> > Lvl::level = {
  {2, {
      {Resource::PLAYER, 1},
      {Resource::LINEMATE, 1},
      {Resource::DERAUMERE, 0},
      {Resource::SIBUR, 0},
      {Resource::MENDIANE, 0},
      {Resource::PHIRAS, 0},
      {Resource::THYSTAME, 0},
    }},
  {3, {
      {Resource::PLAYER, 2},
      {Resource::LINEMATE, 1},
      {Resource::DERAUMERE, 1},
      {Resource::SIBUR, 1},
      {Resource::MENDIANE, 0},
      {Resource::PHIRAS, 0},
      {Resource::THYSTAME, 0},
    }},
  {4, {
      {Resource::PLAYER, 2},
      {Resource::LINEMATE, 2},
      {Resource::DERAUMERE, 0},
      {Resource::SIBUR, 1},
      {Resource::MENDIANE, 0},
      {Resource::PHIRAS, 2},
      {Resource::THYSTAME, 0},
    }},
  {5, {
      {Resource::PLAYER, 4},
      {Resource::LINEMATE, 1},
      {Resource::DERAUMERE, 1},
      {Resource::SIBUR, 2},
      {Resource::MENDIANE, 0},
      {Resource::PHIRAS, 1},
      {Resource::THYSTAME, 0},
    }},
  {6, {
      {Resource::PLAYER, 4},
      {Resource::LINEMATE, 1},
      {Resource::DERAUMERE, 2},
      {Resource::SIBUR, 1},
      {Resource::MENDIANE, 3},
      {Resource::PHIRAS, 0},
      {Resource::THYSTAME, 0},
    }},
  {7, {
      {Resource::PLAYER, 6},
      {Resource::LINEMATE, 1},
      {Resource::DERAUMERE, 2},
      {Resource::SIBUR, 3},
      {Resource::MENDIANE, 0},
      {Resource::PHIRAS, 1},
      {Resource::THYSTAME, 0},
    }},
  {8, {
      {Resource::PLAYER, 6},
      {Resource::LINEMATE, 2},
      {Resource::DERAUMERE, 2},
      {Resource::SIBUR, 2},
      {Resource::MENDIANE, 2},
      {Resource::PHIRAS, 2},
      {Resource::THYSTAME, 1},
    }},
};
