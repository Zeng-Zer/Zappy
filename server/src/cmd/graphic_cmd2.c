/*
** graphic_cmd2.c for graphic_cmd2 in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Jun 29 16:54:12 2017 David Zeng
** Last update Thu Jun 29 16:54:12 2017 David Zeng
*/

#include "cmd.h"

void	graphic_ppo(int fd, t_player *player)
{
  dprintf(fd, "ppo %d %d %d %d\n", player->id,
	  player->pos.x, player->pos.y, player->rotation);
}

void	graphic_plv(int fd, t_player *player)
{
  dprintf(fd, "plv %d %d\n", player->id, player->level);
}

void	graphic_pin(int fd, t_player *player)
{
  dprintf(fd, "pin %d %d %d %d %d %d %d %d %d %d\n",
	  player->id, player->pos.x, player->pos.y,
	  player->stones[FOOD],
	  player->stones[LINEMATE],
	  player->stones[DERAUMERE],
	  player->stones[SIBUR],
	  player->stones[MENDIANE],
	  player->stones[PHIRAS],
	  player->stones[THYSTAME]);
}

void	graphic_sgt(int fd, t_server *server)
{
  dprintf(fd, "sgt %d\n", server->frequency);
}

void	graphic_sst(int fd, t_server *server, int freq)
{
  server->frequency = freq;
  graphic_sgt(fd, server);
}
