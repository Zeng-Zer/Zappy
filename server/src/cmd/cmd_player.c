/*
** cmd_player.c for cmd_player in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sat Jun 24 17:00:31 2017 David Zeng
** Last update Sat Jun 24 17:00:31 2017 David Zeng
*/

#include "cmd.h"

void		cmd_forward(t_server *server, t_command *command)
{
  t_player	*player;

  player = command->entity;
  vector_remove_item(server->world->map[player->pos.y][player->pos.x].players,
		     player);
  if (player->rotation == UP)
    --player->pos.y;
  else if (player->rotation == DOWN)
    ++player->pos.y;
  else if (player->rotation == LEFT)
    --player->pos.x;
  else if (player->rotation == RIGHT)
    ++player->pos.x;
  if (player->pos.y < 0)
    player->pos.y += server->world->dimension.y;
  else if (player->pos.y >= server->world->dimension.y)
    player->pos.y -= server->world->dimension.y;
  if (player->pos.x < 0)
    player->pos.x += server->world->dimension.x;
  else if (player->pos.x >= server->world->dimension.x)
    player->pos.x -= server->world->dimension.x;
  vector_push(server->world->map[player->pos.y][player->pos.x].players, player);
  dprintf(player->id, "ok\n");
}

void		cmd_right(t_server *server, t_command *command)
{
  t_player	*player;

  (void)server;
  player = command->entity;
  player->rotation = turn(player->rotation, RIGHT);
  dprintf(player->id, "ok\n");
}

void		cmd_left(t_server *server, t_command *command)
{
  t_player	*player;

  (void)server;
  player = command->entity;
  player->rotation = turn(player->rotation, LEFT);
  dprintf(player->id, "ok\n");
}

void		cmd_look(t_server *server, t_command *command)
{
  t_player	*player;
  t_pos		dir[2];
  int		i;
  int		j;
  t_pos		pos;

  player = command->entity;
  get_front_dir(player->rotation, dir);
  i = 0;
  dprintf(player->id, "[");
  print_tile(player->id, server->world, player->pos);
  while (++i <= player->level)
    {
      pos.x = dir[0].x * i + player->pos.x;
      pos.y = dir[0].y * i + player->pos.y;
      j = -1;
      while (++j <= i * 2)
	{
	  dprintf(player->id, ",");
	  print_tile(player->id, server->world, pos);
	  pos.x += dir[1].x;
	  pos.y += dir[1].y;
	}
    }
  dprintf(player->id, " ]\n");
}

void		cmd_inventory(t_server *server, t_command *command)
{
  t_player	*player;
  char		buf[512];

  (void)server;
  player = command->entity;
  snprintf(buf, 511, "[ food %d, linemate %d, deraumere %d, sibur %d, "
	   "mendiane %d, phiras %d, thystame %d ]",
	   player->stones[FOOD],
	   player->stones[LINEMATE],
	   player->stones[DERAUMERE],
	   player->stones[SIBUR],
	   player->stones[MENDIANE],
	   player->stones[PHIRAS],
	   player->stones[THYSTAME]);
  dprintf(player->id, "%s\n", buf);
}
