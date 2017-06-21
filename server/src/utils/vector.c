/*
** vector.c<utils> for vector in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Jun 21 00:26:56 2017 David Zeng
** Last update Wed Jun 21 00:26:56 2017 David Zeng
*/

#include "vector.h"

t_vector	*vector_new()
{
  t_vector	*vector;

  if (!(vector = malloc(sizeof(*vector))))
    return (NULL);
  vector->length = 0;
  vector->capacity = VECTOR_CAPACITY;
  if (!(vector->items = malloc(sizeof(*vector->items) * vector->capacity)))
    return (NULL);
  return (vector);
}

void		vector_push(t_vector *vector, void *item)
{
  if (vector->length == vector->capacity)
    {
      vector->capacity *= 2;
      vector->items = realloc(vector->items, sizeof(void *) * vector->capacity);
    }
  vector->items[vector->length++] = item;
}

void		*vector_pop(t_vector *vector)
{
  return (vector->length == 0 ? NULL : vector->items[--vector->length]);
}

void		vector_clear(t_vector *vector)
{
  vector->length = 0;
}

void		vector_delete(t_vector *vector, void (*free_item)(void *))
{
  size_t	i;

  i = 0;
  if (!vector)
    return;
  if (free_item)
    {
      while (i < vector->length)
	{
	  free_item(vector->items[i]);
	  ++i;
	}
    }
  free(vector->items);
  free(vector);
}
