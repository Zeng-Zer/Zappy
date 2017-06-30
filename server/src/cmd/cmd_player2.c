/*
** cmd_player2.c for cmd_player2 in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sun Jun 25 18:10:30 2017 David Zeng
** Last update Sun Jun 25 18:10:30 2017 David Zeng
*/

#include "cmd.h"
#include "egg.h"
#include "graphic.h"

void		cmd_broadcast(t_server *server, t_command *command)
{
  t_player	*player;
  size_t	i;
  int		dir;

  player = command->entity;
  i = -1;
  while (++i < server->players->length)
    {
      if (server->players->items[i] == player)
	continue;
      dir = broadcast_dir(server->world, player,
			  server->players->items[i]);
      dprintf(((t_player*)server->players->items[i])->id,
	      "message %d, %s\n",
	      dir, (char*)command->item + strlen("Broadcast "));
    }
  dprintf(player->id, "ok\n");
  multi_graphic_broadcast(server->graphic, player,
			  (char*)command->item + strlen("Broadcast "));
}

void		cmd_connect(t_server *server, t_command *command)
{
  t_player	*player;

  player = command->entity;
  dprintf(player->id, "%d\n", server->max_client -
	  nb_player_team(server->players, player->team_id));
}

void		cmd_fork(t_server *server, t_command *command)
{
  t_player	*player;
  t_egg		*egg;

  player = command->entity;
  if (command->delete)
    {
      command->end_time = END_TIME(42.0f);
      command->start = false;
      command->delete = false;
      multi_graphic_pfk(server->graphic, player);
    }
  else
    {
      command->delete = true;
      if (!(egg = create_egg(player->team_id, &player->pos, END_TIME(600.0f))))
	return;
      vector_push(server->eggs, egg);
      dprintf(player->id, "ok\n");
      multi_graphic_enw(server->graphic, player, egg);
    }
}

void		cmd_eject(t_server *server, t_command *command)
{
  t_player	*player;
  t_player	*ejected;
  t_pos		dir[2];
  t_tile	*tile;

  player = command->entity;
  get_front_dir(player->rotation, dir);
  tile = at(server->world, (t_pos){player->pos.x + dir[0].x + dir[1].x,
	player->pos.y + dir[0].y + dir[1].y});
  if (tile->players->length == 0)
    return ((void)dprintf(player->id, "ko\n"));
  while (tile->players->length > 0)
    {
      ejected = tile->players->items[0];
      move_player(server->world, ejected, player->rotation);
      dprintf(ejected->id, "eject: %d\n",
	      related_dir(player->rotation, ejected->rotation));
    }
  dprintf(player->id, "ok\n");
  multi_graphic_eject(server->graphic, server, player);
}

void		cmd_take(t_server *server, t_command *command)
{
  t_player	*player;
  char		**msg;
  t_stone	stone;

  player = command->entity;
  msg = split(command->item, " ");
  if (tablen(msg) != 2 || (stone = str_to_stone(msg[1])) == STONES_SIZE ||
      server->world->map[player->pos.y][player->pos.x].stones[stone] == 0)
    dprintf(player->id, "ko\n");
  else
    {
      ++player->stones[stone];
      --server->world->map[player->pos.y][player->pos.x].stones[stone];
      dprintf(player->id, "ok\n");
      multi_graphic_take(server->graphic, server->world, player, stone);
    }
  free_tab(msg);
}
