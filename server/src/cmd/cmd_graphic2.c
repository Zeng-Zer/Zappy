/*
** cmd_graphic2.c for cmd_graphic2 in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Jun 29 16:45:12 2017 David Zeng
** Last update Thu Jun 29 16:45:12 2017 David Zeng
*/

#include "cmd.h"
#include "graphic.h"

void		cmd_plv(t_server *server, t_command *command)
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
    graphic_plv(graphic->id, player);
  free_tab(cmd);
}

void		cmd_pin(t_server *server, t_command *command)
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
    graphic_pin(graphic->id, player);
  free_tab(cmd);
}

void		cmd_sgt(t_server *server, t_command *command)
{
  t_graphic	*graphic;
  char		**cmd;

  graphic = command->entity;
  cmd = split(command->item, " ");
  if (tablen(cmd) != 1)
    graphic_sbp(graphic);
  else
    graphic_sgt(graphic->id, server);
  free_tab(cmd);
}

void		cmd_sst(t_server *server, t_command *command)
{
  t_graphic	*graphic;
  char		**cmd;
  int		freq;

  graphic = command->entity;
  cmd = split(command->item, " ");
  if (tablen(cmd) != 2 || (freq = atoi(cmd[1])) < 2 || freq > 10000)
    graphic_sbp(graphic);
  else
    graphic_sst(graphic->id, server, freq);
  free_tab(cmd);
}
