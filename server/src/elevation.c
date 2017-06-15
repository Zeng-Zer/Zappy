/*
** elevation.c for elevation in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Jun 15 21:02:00 2017 David Zeng
** Last update Thu Jun 15 21:02:00 2017 David Zeng
*/

#include <string.h>
#include <assert.h>
#include "elevation.h"

// first 2 element are useless
const t_elevation g_elevations[MAX_LEVEL + 1] = {
  {0, {0, 0, 0, 0, 0, 0}},
  {0, {0, 0, 0, 0, 0, 0}},

  // level 2
  {1, {1, 0, 0, 0, 0, 0}},
  // level 3
  {2, {1, 1, 1, 0, 0, 0}},
  // level 4
  {2, {2, 0, 1, 0, 2, 0}},
  // level 5
  {4, {1, 1, 2, 0, 1, 0}},
  // level 6
  {4, {1, 2, 1, 3, 0, 0}},
  // level 7
  {6, {1, 2, 3, 0, 1, 0}},
  // level 8
  {6, {2, 2, 2, 2, 2, 1}},
};

bool			can_elevate(int next_level,
				    int nb_player_on_tile,
				    int *stones)
{
  const t_elevation	*req;

  assert(next_level >= 2 && next_level <= MAX_LEVEL);
  req = &g_elevations[next_level];
  if (nb_player_on_tile == req->nb_player &&
      stones[LINEMATE] >= req->stones[LINEMATE] &&
      stones[DERAUMERE] >= req->stones[DERAUMERE] &&
      stones[SIBUR] >= req->stones[SIBUR] &&
      stones[MENDIANE] >= req->stones[MENDIANE] &&
      stones[PHIRAS] >= req->stones[PHIRAS] &&
      stones[THYSTAME] >= req->stones[THYSTAME])
    return (true);
  return (false);
}
