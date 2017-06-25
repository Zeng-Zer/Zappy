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
}

void		cmd_left(t_server *server, t_command *command)
{
  t_player	*player;

  (void)server;
  player = command->entity;
  player->rotation = turn(player->rotation, LEFT);
}

void		cmd_look(t_server *server, t_command *command)
{
  t_player	*player;

  player = command->entity;
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
