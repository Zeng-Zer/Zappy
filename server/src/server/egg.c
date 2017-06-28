/*
** egg.c for egg in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Jun 28 00:00:41 2017 David Zeng
** Last update Wed Jun 28 00:00:41 2017 David Zeng
*/

#include <stdlib.h>
#include "egg.h"

t_egg	*create_egg(int team_id, t_pos *pos, long long end_time)
{
  t_egg	*egg;

  if (!(egg = malloc(sizeof(*egg))))
    return (NULL);
  egg->team_id = team_id;
  egg->pos = *pos;
  egg->hatched = false;
  egg->end_time = current_time() + end_time;
  return (egg);
}

void	free_egg(void *item)
{
  t_egg	*egg;

  egg = item;
  free(egg);
}
