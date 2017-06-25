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

t_graphic	*new_graphic(int fd)
{
  t_graphic	*graphic;

  if (!(graphic = malloc(sizeof(*graphic))))
    return (NULL);
  graphic->id = fd;
  return (graphic);
}

void		free_graphic(void *item)
{
  t_graphic	*graphic;

  if (!item)
    return;
  graphic = item;
  free(graphic);
}
