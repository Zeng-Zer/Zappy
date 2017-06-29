/*
** broadcast.c for broadcast in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Jun 29 00:21:53 2017 David Zeng
** Last update Thu Jun 29 00:21:53 2017 David Zeng
*/

#include "cmd.h"

static const t_pos	g_left_dir[9] = {
  {0, 0},
  {-1, 0},
  {-1, 1},
  {0, 1},
  {1, 1},
  {1, 0},
  {1, -1},
  {0, -1},
  {-1, -1},
};

static const t_pos	g_right_dir[9] = {
  {0, 0},
  {1, 0},
  {1, -1},
  {0, -1},
  {-1, -1},
  {-1, 0},
  {-1, 1},
  {0, 1},
  {1, 1},
};

static const t_pos	g_up_dir[9] = {
  {0, 0},
  {0, -1},
  {-1, -1},
  {-1, 0},
  {-1, 1},
  {0, 1},
  {1, 1},
  {1, 0},
  {1, -1},
};

static const t_pos	g_down_dir[9] = {
  {0, 0},
  {0, 1},
  {1, 1},
  {1, 0},
  {1, -1},
  {0, -1},
  {-1, -1},
  {-1, 0},
  {-1, 1},
};

static const t_pos	*broadcast_rotation(t_rotation rot)
{
  if (rot == UP)
    return (g_up_dir);
  if (rot == DOWN)
    return (g_down_dir);
  if (rot == LEFT)
    return (g_left_dir);
  return (g_right_dir);
}

static t_pos	closest_pos(t_pos dim, t_pos from, t_pos other)
{
  t_pos		pos;

  if (abs(from.x - other.x) <= dim.x - abs(from.x - other.x))
    pos.x = other.x;
  else
    {
      if (other.x > from.x)
	pos.x = from.x - (dim.x - abs(from.x - other.x));
      else
	pos.x = from.x + (dim.x - abs(from.x - other.x));
    }
  if (abs(from.y - other.y) <= dim.y - abs(from.y - other.y))
    pos.y = other.y;
  else
    {
      if (other.y > from.y)
	pos.y = from.y - (dim.y - abs(from.y - other.y));
      else
	pos.y = from.y + (dim.y - abs(from.y - other.y));
    }
  return (pos);
}

static int	get_dir(t_world *world, t_player *player, t_pos pos)
{
  t_tile	*obj;
  const t_pos	*dirs;
  int		i;

  obj = at(world, pos);
  dirs = broadcast_rotation(player->rotation);
  i = -1;
  while (++i < 9)
    {
      if (at(world, (t_pos){player->pos.x + dirs[i].x,
	      player->pos.y + dirs[i].y}) == obj)
	return (i);
    }
  return (0);
}

int		broadcast_dir(t_world *world, t_player *from, t_player *other)
{
  t_pos		closest;
  t_pos		pos;

  closest = closest_pos(world->dimension, from->pos, other->pos);
  line(closest, from->pos, &pos);
  return (get_dir(world, other, pos));
}
