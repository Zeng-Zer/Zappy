/*
** graphic.c for graphic in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sat Jun 24 18:47:37 2017 David Zeng
** Last update Sat Jun 24 18:47:37 2017 David Zeng
*/

#include <stdlib.h>
#include "graphic.h"
#include "cmd.h"

t_graphic	*new_graphic(int fd)
{
  t_graphic	*graphic;

  if (!(graphic = malloc(sizeof(*graphic))))
    return (NULL);
  graphic->id = fd;
  graphic->cmds = vector_new();
  if (!graphic->cmds)
    {
      free(graphic);
      return (NULL);
    }
  return (graphic);
}

void		free_graphic(void *item)
{
  t_graphic	*graphic;

  if (!item)
    return;
  graphic = item;
  vector_delete(graphic->cmds, free_command);
  free(graphic);
}

void		add_graphic_cmd(t_graphic *graphic, t_command *cmd)
{
  vector_push(graphic->cmds, cmd);
}
