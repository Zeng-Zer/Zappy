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
#include "cmd.h"

t_player	*create_player(int fd, int team_id, t_pos pos)
{
  t_player	*player;

  if (!(player = malloc(sizeof(*player))))
    return (NULL);
  player->id = fd;
  player->team_id = team_id;
  player->level = 1;
  player->pos = pos;
  player->rotation = rand() % 4;
  player->time = current_time();
  memcpy(player->stones, (int[7]){DEFAULT_FOOD, 0, 0, 0, 0, 0, 0},
	 sizeof(player->stones));
  player->cmds = vector_new();
  if (!player->cmds)
    {
      free(player);
      return (NULL);
    }
  return (player);
}

void		free_player(void *item)
{
  t_player	*player;

  if (!item)
    return;
  player = item;
  vector_delete(player->cmds, free_command);
  free(player);
}

void		add_player_cmd(t_player *player, t_command *cmd)
{
  if (player->cmds->length >= 10)
    return (free_command(cmd));
  vector_push(player->cmds, cmd);
}
