/*
** rotation.c for rotation in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sun Jun 25 22:57:36 2017 David Zeng
** Last update Sun Jun 25 22:57:36 2017 David Zeng
*/

#include "rotation.h"

t_rotation	turn(t_rotation current, t_rotation direction)
{
  if (current == RIGHT && direction == LEFT)
    current = UP;
  else if (current == LEFT && direction == LEFT)
    current = DOWN;
  else if (current == UP && direction == LEFT)
    current = LEFT;
  else if (current == DOWN && direction == LEFT)
    current = RIGHT;
  else if (current == RIGHT && direction == RIGHT)
    current = DOWN;
  else if (current == LEFT && direction == RIGHT)
    current = UP;
  else if (current == UP && direction == RIGHT)
    current = RIGHT;
  else if (current == DOWN && direction == RIGHT)
    current = LEFT;
  return (current);
}

void	get_front_dir(t_rotation rot, t_pos *pos)
{
  if (rot == UP)
    {
      pos[0] = (t_pos){-1, -1};
      pos[1] = (t_pos){1, 0};
    }
  else if (rot == LEFT)
    {
      pos[0] = (t_pos){-1, 1};
      pos[1] = (t_pos){0, -1};
    }
  else if (rot == RIGHT)
    {
      pos[0] = (t_pos){1, -1};
      pos[1] = (t_pos){0, 1};
    }
  else
    {
      pos[0] = (t_pos){1, 1};
      pos[1] = (t_pos){-1, 0};
    }
}
