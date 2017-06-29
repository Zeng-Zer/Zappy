/*
** cmd_graphic.c for cmd_graphic in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Jun 29 16:12:34 2017 David Zeng
** Last update Thu Jun 29 16:12:34 2017 David Zeng
*/

#include "cmd.h"
#include "graphic.h"

void		cmd_msz(t_server *server, t_command *command)
{
  t_graphic	*graphic;
  char		**cmd;

  graphic = command->entity;
  cmd = split(command->item, " ");
  if (tablen(cmd) != 1)
    graphic_sbp(graphic);
  else
    graphic_msz(graphic->id, server->world);
  free_tab(cmd);
}

void		cmd_bct(t_server *server, t_command *command)
{
  t_graphic	*graphic;
  char		**cmd;
  t_pos		pos;

  graphic = command->entity;
  cmd = split(command->item, " ");
  if (tablen(cmd) != 3 ||
      (pos.x = atoi(cmd[1])) < 0 || pos.x >= server->world->dimension.x ||
      (pos.y = atoi(cmd[2])) < 0 || pos.y >= server->world->dimension.y)
    graphic_sbp(graphic);
  else
    graphic_bct(graphic->id, server->world, pos);
  free_tab(cmd);
}

void		cmd_mct(t_server *server, t_command *command)
{
  t_graphic	*graphic;
  char		**cmd;

  graphic = command->entity;
  cmd = split(command->item, " ");
  if (tablen(cmd) != 1)
    graphic_sbp(graphic);
  else
    graphic_mct(graphic->id, server->world);
  free_tab(cmd);
}

void		cmd_tna(t_server *server, t_command *command)
{
  t_graphic	*graphic;
  char		**cmd;

  graphic = command->entity;
  cmd = split(command->item, " ");
  if (tablen(cmd) != 1)
    graphic_sbp(graphic);
  else
    graphic_tna(graphic->id, server);
  free_tab(cmd);
}

void		cmd_ppo(t_server *server, t_command *command)
{
  t_graphic	*graphic;
  t_player	*player;
  char		**cmd;
  int		id;

  graphic = command->entity;
  cmd = split(command->item, " ");
  if (tablen(cmd) != 2 || (id = atoi(cmd[1])) < 0 ||
      !(player = find_player(server->players, id)))
    graphic_sbp(graphic);
  else
    graphic_ppo(graphic->id, player);
  free_tab(cmd);
}
