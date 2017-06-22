/*
** world.h for world in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Fri Jun 16 00:18:44 2017 David Zeng
** Last update Fri Jun 16 00:18:44 2017 David Zeng
*/

#ifndef WORLD_H_
# define WORLD_H_

# include <stdbool.h>
# include "stone.h"
# include "utils.h"
# include "vector.h"

/**
 * struct representing a tile
 * contains quantity of food and stones
 * bool for elevation
 */
typedef struct	s_tile
{
  int		food;
  int		stones[STONES_SIZE];
  bool		elevation;
  t_vector	*players;
}		t_tile;

/**
 * world is represented as a tile array
 */
typedef struct	s_world
{
  t_tile	**map;
  t_pos		dimension;
}		t_world;

/**
 * malloc a new world with random resources
 */
t_world		*create_world(t_pos dimension);

/**
 * free world
 */
void		free_world(t_world *world);

#endif /* !WORLD_H_ */
