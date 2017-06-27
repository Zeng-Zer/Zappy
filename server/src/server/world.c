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
#include <stdio.h>
#include "world.h"
#include "player.h"

static void	generate_map(t_tile **map, t_pos dim)
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
	  map[j][i].stones[FOOD] = 0;
	  map[j][i].stones[LINEMATE] = rand() % 3;
	  map[j][i].stones[DERAUMERE] = rand() % 3;
	  map[j][i].stones[SIBUR] = rand() % 2;
	  map[j][i].stones[MENDIANE] = rand() % 2;
	  map[j][i].stones[PHIRAS] = !(rand() % 4);
	  map[j][i].stones[THYSTAME] = !(rand() % 6);
	  if (!(map[j][i].players = vector_new()))
	    exit(84);
	}
    }
}

void		world_dump(int fd, t_world *world)
{
  int		i;
  int		j;
  t_tile	*tile;

  j = -1;
  while (++j < world->dimension.y)
    {
      i = -1;
      while (++i < world->dimension.x)
	{
	  tile = &world->map[j][i];
	  dprintf(fd, "bct %d %d %d %d %d %d %d %d %d\n",
		  i, j, tile->stones[FOOD], tile->stones[LINEMATE],
		  tile->stones[DERAUMERE], tile->stones[SIBUR],
		  tile->stones[MENDIANE], tile->stones[PHIRAS],
		  tile->stones[THYSTAME]);
	}
    }
}

t_world		*create_world(t_pos dim)
{
  t_world	*world;
  int		i;

  if (!(world = malloc(sizeof(*world))))
    exit(84);
  world->dimension = dim;
  if (!(world->map = malloc(sizeof(t_tile *) * dim.y)))
    exit(84);
  i = -1;
  while (++i < dim.y)
    {
      world->map[i] = malloc(sizeof(t_tile) * dim.x);
      if (!world->map[i])
	exit(84);
    }
  generate_map(world->map, dim);
  return (world);
}

void		free_world(t_world *world)
{
  int		i;
  int		j;

  if (!world)
    return;
  j = -1;
  while (++j < world->dimension.y)
    {
      i = -1;
      while (++i < world->dimension.x)
	vector_delete(world->map[j][i].players, NULL);
      free(world->map[j]);
    }
  free(world->map);
  free(world);
}

t_tile	*at(t_world *world, t_pos pos)
{
  while (pos.x >= world->dimension.x)
    pos.x -= world->dimension.x;
  while (pos.y >= world->dimension.y)
    pos.y -= world->dimension.y;
  while (pos.x < 0)
    pos.x += world->dimension.x;
  while (pos.y < 0)
    pos.y += world->dimension.y;
  return (&world->map[pos.y][pos.x]);
}
