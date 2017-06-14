/*
** elevation.h for elevation in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Jun 14 03:30:14 2017 David Zeng
** Last update Wed Jun 14 03:30:14 2017 David Zeng
*/

#ifndef ELEVATION_H_
# define ELEVATION_H_

# include <stdbool.h>
# include "stones.h"

/**
 * maximum level a player can reach
 */
# define MAX_LEVEL 8

/**
 * struct that describe an elevation and its requirement
 */
typedef struct	s_elevation
{
  int		nb_player;
  int		stones_req[STONES_SIZE];
}		t_elevation;

/**
 * g_elevations[0] and g_elevations[1] are useless
 * the index represent the level
 * g_elevations[2] = lvl 2 requirements
 */
extern const t_elevation g_elevations[MAX_LEVEL + 1];

/**
 * check if an elevation can be done
 * compare parameters with g_elevations[next_level]
 */
bool	can_elevate(int next_level, int nb_player_on_tile, int *stones);

#endif /* !ELEVATION_H_ */
