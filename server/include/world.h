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
}		t_tile;

/**
 * world is represented as a tile array
 */
typedef t_tile	**World;

/**
 * malloc a new world with random resources
 */
World		create_world(t_pos dimension);

/**
 * free world
 */
void		free_world(World world);

#endif /* !WORLD_H_ */
