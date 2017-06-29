/*
** graphic_cmd.c for graphic_cmd in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Jun 29 16:20:57 2017 David Zeng
** Last update Thu Jun 29 16:20:57 2017 David Zeng
*/

#include "cmd.h"
#include "graphic.h"

void	graphic_sbp(t_graphic *graphic)
{
  dprintf(graphic->id, "sbp\n");
}

void	graphic_msz(int fd, t_world *world)
{
  dprintf(fd, "msz %d %d\n", world->dimension.x, world->dimension.y);
}

void		graphic_bct(int fd, t_world *world, t_pos pos)
{
  t_tile	*tile;

  tile = at(world, pos);
  dprintf(fd, "bct %d %d %d %d %d %d %d %d %d\n",
	  pos.x, pos.y,
	  tile->stones[FOOD],
	  tile->stones[LINEMATE],
	  tile->stones[DERAUMERE],
	  tile->stones[SIBUR],
	  tile->stones[MENDIANE],
	  tile->stones[PHIRAS],
	  tile->stones[THYSTAME]);
}

void	graphic_mct(int fd, t_world *world)
{
  t_pos	pos;

  pos.y = -1;
  while (++pos.y < world->dimension.y)
    {
      pos.x = -1;
      while (++pos.x < world->dimension.x)
	{
	  graphic_bct(fd, world, pos);
	}
    }
}

void	graphic_tna(int fd, t_server *server)
{
  int	i;

  i = -1;
  while (++i < server->nb_team)
    {
      dprintf(fd, "tna %s\n", server->teams[i]);
    }
}
