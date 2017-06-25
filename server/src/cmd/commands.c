/*
** commands.c for commands in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sun Jun 25 17:51:29 2017 David Zeng
** Last update Sun Jun 25 17:51:29 2017 David Zeng
*/

#include "cmd.h"

t_command	*create_command(cmd action, long long end_time,
				void *entity, void *item)
{
  t_command	*command;

  if (!(command = malloc(sizeof(*command))))
    return (NULL);
  command->action = action;
  command->end_time = end_time;
  command->entity = entity;
  command->item = item;
  command->start = false;
  command->delete = true;
  return (command);
}

void		free_command(void *item)
{
  t_command	*cmd;

  cmd = item;
  if (cmd->item)
    free(cmd->item);
  free(cmd);
}
