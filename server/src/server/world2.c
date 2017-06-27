/*
** world2.c for world2 in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Jun 27 02:09:13 2017 David Zeng
** Last update Tue Jun 27 02:09:13 2017 David Zeng
*/

#include <stdio.h>
#include "world.h"
#include "stone.h"

void		print_tile(int fd, t_world *world, t_pos pos)
{
  t_tile	*tile;
  size_t	i;

  tile = at(world, pos);
  i = -1;
  while (++i < tile->players->length)
    {
      dprintf(fd, " player");
    }
  print_stones(fd, tile->stones);
}
