/*
** vector2.c for vector2 in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Jun 21 22:15:43 2017 David Zeng
** Last update Wed Jun 21 22:15:43 2017 David Zeng
*/

#include "vector.h"

void		*vector_pop(t_vector *vector)
{
  return (vector->length == 0 ? NULL : vector->items[--vector->length]);
}

void		*vector_pop_front(t_vector *vector)
{
  void		*item;

  if (vector->length == 0)
    return (NULL);
  item = vector->items[0];
  vector_remove(vector, 0);
  return (item);
}
