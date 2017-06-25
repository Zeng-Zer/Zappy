/*
** cmd_player3.c for cmd_player3 in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sun Jun 25 18:20:46 2017 David Zeng
** Last update Sun Jun 25 18:20:46 2017 David Zeng
*/

#include "cmd.h"
#include "elevation.h"

void		cmd_set(t_server *server, t_command *command)
{
  t_player	*player;
  char		**msg;
  t_stone	stone;

  player = command->entity;
  msg = split(command->item, " ");
  if (tablen(msg) != 2 || (stone = str_to_stone(msg[1])) == STONES_SIZE ||
      player->stones[stone] == 0)
    dprintf(player->id, "ko\n");
  else
    {
      --player->stones[stone];
      ++server->world->map[player->pos.y][player->pos.x].stones[stone];
      dprintf(player->id, "ok\n");
    }
  free_tab(msg);
}

static void	lvlup(t_tile *tile, int level)
{
  size_t	i;
  t_player	*player;

  i = -1;
  while (++i < tile->players->length)
    {
      player = tile->players->items[i];
      if (player->level == level)
	{
	  ++player->level;
	  dprintf(player->id, "Current level: %d\n", player->level);
	}
    }
}

void		cmd_incant(t_server *server, t_command *command)
{
  t_player	*player;
  bool		elevate;

  player = command->entity;
  elevate = can_elevate(player->level + 1,
	      server->world->map[player->pos.y][player->pos.x].players->length,
	      server->world->map[player->pos.y][player->pos.x].stones);
  if (command->delete)
    {
      command->end_time = END_TIME(300.0f);
      command->start = false;
      command->delete = false;
      if (elevate)
	dprintf(player->id, "Elevation underway\n");
      else
	dprintf(player->id, "ko\n");
    }
  else
    {
      command->delete = true;
      if (elevate)
	lvlup(&server->world->map[player->pos.y][player->pos.x], player->level);
      else
	dprintf(player->id, "ko\n");
    }
}
