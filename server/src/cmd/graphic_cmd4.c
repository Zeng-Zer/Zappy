/*
** graphic_cmd4.c for graphic_cmd4 in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Jun 29 18:36:19 2017 David Zeng
** Last update Thu Jun 29 18:36:19 2017 David Zeng
*/

#include "cmd.h"
#include "egg.h"

void	graphic_pfk(int fd, t_player *player)
{
  dprintf(fd, "pfk %d\n", player->id);
}

void	graphic_pdr(int fd, t_player *player, t_stone res)
{
  dprintf(fd, "pdr %d %d\n", player->id, res);
}

void	graphic_pgt(int fd, t_player *player, t_stone res)
{
  dprintf(fd, "pgt %d %d\n", player->id, res);
}

void	graphic_pdi(int fd, t_player *player)
{
  dprintf(fd, "pdi %d\n", player->id);
}

void	graphic_enw(int fd, int id, t_egg *egg)
{
  dprintf(fd, "enw %d %d %d %d\n", (int)egg, id,
	  egg->pos.x, egg->pos.y);
}
