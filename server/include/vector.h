/*
** vector.h for vector in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Jun 21 00:15:44 2017 David Zeng
** Last update Wed Jun 21 00:15:44 2017 David Zeng
*/

#ifndef VECTOR_H_
# define VECTOR_H_

# include <stdlib.h>

# define VECTOR_CAPACITY 20

/**
 * struct that represents a vector
 */
typedef struct	s_vector
{
  size_t	length;
  size_t	capacity;
  void		**items;
}		t_vector;

/**
 * vector functions
 */
t_vector	*vector_new();
void		vector_delete(t_vector *vector, void (*free_item)(void *));
void		vector_push(t_vector *vector, void *item);
void		*vector_pop(t_vector *vector);
void		*vector_pop_front(t_vector *vector);
void		*vector_remove(t_vector *vector, size_t id);
void		*vector_remove_item(t_vector *vector, void *item);

// get an items with vector.items[i]
// clear items with vector.length = 0;

#endif /* !VECTOR_H_ */
