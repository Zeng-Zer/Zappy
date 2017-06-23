/*
** player.c for player in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Fri Jun 23 00:42:48 2017 David Zeng
** Last update Fri Jun 23 00:42:48 2017 David Zeng
*/

#include "player.h"

t_player	*create_player(int fd, int team_id, t_pos pos)
{
  t_player	*player;

  if (!(player = malloc(sizeof(*player))))
    return (NULL);
  player->id = fd;
  player->team_id = team_id;
  player->level = 1;
  player->pos = pos;
  player->food = DEFAULT_FOOD;
  player->rotation = rand() % 4;
  memcpy(player->stones, (int[6]){0, 0, 0, 0, 0, 0}, sizeof(player->stones));
  return (player);
}

void		free_player(t_player *player)
{
  free(player);
}
