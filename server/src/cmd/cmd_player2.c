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
}
