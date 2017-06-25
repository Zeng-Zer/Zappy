/*
** cmd_player2.c for cmd_player2 in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sun Jun 25 18:10:30 2017 David Zeng
** Last update Sun Jun 25 18:10:30 2017 David Zeng
*/

#include "cmd.h"

void		cmd_broadcast(t_server *server, t_command *command)
{
}

void		cmd_connect(t_server *server, t_command *command)
{
  t_player	*player;

  player = command->entity;
  dprintf(player->id, "%d\n", server->max_client -
	  nb_player_team(server->players, player->team_id));
}

void		cmd_fork(t_server *server, t_command *command)
{
}

void		cmd_eject(t_server *server, t_command *command)
{
}

void		cmd_take(t_server *server, t_command *command)
{
  t_player	*player;
  char		**msg;
  t_stone	stone;

  player = command->entity;
  msg = split(command->item, " ");
  if (tablen(msg) != 2 || (stone = str_to_stone(msg[1])) == STONES_SIZE ||
      server->world->map[player->pos.y][player->pos.x].stones[stone] == 0)
    dprintf(player->id, "ko\n");
  else
    {
      ++player->stones[stone];
      --server->world->map[player->pos.y][player->pos.x].stones[stone];
      dprintf(player->id, "ok\n");
    }
  free_tab(msg);
}
