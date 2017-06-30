/*
** graphic_cmd3.c for graphic_cmd3 in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Jun 29 18:23:07 2017 David Zeng
** Last update Thu Jun 29 18:23:07 2017 David Zeng
*/

#include "cmd.h"

void	graphic_pnw(int fd, t_server *server, t_player *player)
{
  dprintf(fd, "pnw %d %d %d %d %d %s\n", player->id,
	  player->pos.x, player->pos.y, player->rotation, player->level,
	  server->teams[player->team_id]);
}

void	graphic_pex(int fd, t_player *player)
{
  dprintf(fd, "pew %d\n", player->id);
}

void	graphic_pbc(int fd, t_player *player, char *msg)
{
  dprintf(fd, "pbc %d %s\n", player->id, msg);
}

void		graphic_pic(int fd, t_player *player, t_tile *tile)
{
  t_player	*other;
  size_t	i;

  dprintf(fd, "pic %d %d %d %d", player->pos.x, player->pos.y,
	  player->level + 1, player->id);
  i = -1;
  while (++i < tile->players->length)
    {
      other = tile->players->items[i];
      if (other != player)
	{
	  dprintf(fd, " %d", other->id);
	}
    }
  dprintf(fd, "\n");
}

void	graphic_pie(int fd, t_pos pos, bool elevation)
{
  dprintf(fd, "pie %d %d %d\n", pos.x, pos.y, elevation);
}
