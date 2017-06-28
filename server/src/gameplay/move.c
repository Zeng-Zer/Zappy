/*
** move.c for move in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Jun 27 22:42:44 2017 David Zeng
** Last update Tue Jun 27 22:42:44 2017 David Zeng
*/

#include "server.h"
#include "player.h"

void	move_player(t_world *world, t_player *player, t_rotation dir)
{
  t_pos	pos_dir[2];

  vector_remove_item(world->map[player->pos.y][player->pos.x].players, player);
  get_front_dir(dir, pos_dir);
  player->pos.x = player->pos.x + pos_dir[0].x + pos_dir[1].x;
  player->pos.y = player->pos.y + pos_dir[0].y + pos_dir[1].y;
  actualize_pos(world, &player->pos);
  vector_push(world->map[player->pos.y][player->pos.x].players, player);
}
