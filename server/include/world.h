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
  int		stones[STONES_SIZE];
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

/**
 * world functions
 */
int	tile_dump(int fd, t_tile *tile, int x, int y);
void	world_dump(int fd, t_world *world);

/**
 * get tile at pos
 */
t_tile	*at(t_world *world, t_pos pos);
void	print_tile(int fd, t_world *world, t_pos pos);

#endif /* !WORLD_H_ */
