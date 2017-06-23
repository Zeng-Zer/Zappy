/*
** vector.c<utils> for vector in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Jun 21 00:26:56 2017 David Zeng
** Last update Wed Jun 21 00:26:56 2017 David Zeng
*/

#include <assert.h>
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

void		vector_push(t_vector *vector, void *item)
{
  if (vector->length == vector->capacity)
    {
      vector->capacity *= 2;
      vector->items = realloc(vector->items, sizeof(void *) * vector->capacity);
    }
  vector->items[vector->length++] = item;
}

void		vector_remove(t_vector *vector, size_t id)
{
  size_t	i;

  i = id;
  assert(id < vector->length);
  while (i < vector->length)
    {
      vector->items[i] = vector->items[i + 1];
      ++i;
    }
  --vector->length;
}

void		vector_remove_item(t_vector *vector, void *item)
{
  size_t	i;

  i = 0;
  while (vector->items[i] != item)
    ++i;
  vector_remove(vector, i);
}
