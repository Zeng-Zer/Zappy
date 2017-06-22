/*
** world.c for world in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Jun 22 00:17:58 2017 David Zeng
** Last update Thu Jun 22 00:17:58 2017 David Zeng
*/

#include <stdlib.h>
#include <time.h>
#include "world.h"

void		generate_map(t_tile **map, t_pos dim)
{
  int		j;
  int		i;

  srand(time(NULL));
  j = -1;
  while (++j < dim.y)
    {
      i = -1;
      while (++i < dim.x)
	{
	  map[j][i] = (t_tile){
	    rand() % 5,
	    {rand() % 5,
	     rand() % 5,
	     rand() % 5,
	     rand() % 5,
	     rand() % 5,
	     rand() % 5},
	    false,
	    vector_new()
	  };
	}
    }
}

t_world		*create_world(t_pos dim)
{
  t_world	*world;
  void		*offset;
  int		i;

  if (!(world = malloc(sizeof(*world))))
    exit(84);
  world->dimension = dim;
  if (!(world->map = malloc(dim.y * sizeof(void *) +
			    (dim.y * (dim.x * sizeof(t_tile))))))
    exit(84);
  i = -1;
  offset = world->map + dim.y;
  while (++i < dim.y)
    world->map[i] = offset + i * dim.x;
  generate_map(world->map, dim);
  return (world);
}

void		free_world(t_world *world)
{
  int		i;
  int		j;

  j = -1;
  while (++j < world->dimension.y)
    {
      i = -1;
      while (++i < world->dimension.x)
	vector_delete(world->map[j][i].players, NULL); // TODO DELETE PLAYER
    }
  free(world->map);
  free(world);
}
