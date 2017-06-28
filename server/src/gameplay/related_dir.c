/*
** related_dir.c for related_dir in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Jun 27 18:36:28 2017 David Zeng
** Last update Tue Jun 27 18:36:28 2017 David Zeng
*/

#include "rotation.h"

static t_rotation	up_dir(t_rotation player)
{
  if (player == UP)
    return (DOWN);
  else if (player == DOWN)
    return (UP);
  else if (player == LEFT)
    return (LEFT);
  return (RIGHT);
}

static t_rotation	down_dir(t_rotation player)
{
  if (player == UP)
    return (UP);
  else if (player == DOWN)
    return (DOWN);
  else if (player == LEFT)
    return (RIGHT);
  return (LEFT);
}

static t_rotation	left_dir(t_rotation player)
{
  if (player == UP)
    return (RIGHT);
  else if (player == DOWN)
    return (LEFT);
  else if (player == LEFT)
    return (DOWN);
  return (UP);
}

static t_rotation	right_dir(t_rotation player)
{
  if (player == UP)
    return (LEFT);
  else if (player == DOWN)
    return (RIGHT);
  else if (player == LEFT)
    return (UP);
  return (DOWN);
}

t_rotation	related_dir(t_rotation from, t_rotation player)
{
  if (from == UP)
    return (up_dir(player));
  else if (from == DOWN)
    return (down_dir(player));
  else if (from == LEFT)
    return (left_dir(player));
  return (right_dir(player));
}
