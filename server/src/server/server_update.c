/*
** server_update.c for server_update in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sun Jun 25 21:34:08 2017 David Zeng
** Last update Sun Jun 25 21:34:08 2017 David Zeng
*/

#include "server.h"
#include "cmd.h"
#include "player.h"
#include "graphic.h"
#include "egg.h"

static bool	update_food(t_server *server, t_player *player, size_t *i,
			    long long time)
{
  long long	food_time;

  food_time = END_TIME(126.0f);
  if (player->stones[FOOD] == 0 || time >= player->time + food_time)
    {
      --player->stones[FOOD];
      player->time += food_time;
      if (player->stones[FOOD] <= 0)
	{
	  dprintf(player->id, "dead\n");
	  close_connection(&server->network, player->id);
	  delete_player_tile(server, player);
	  *i = -1;
	  return (true);
	}
    }
  return (false);
}

static void	player_update(t_server *server, t_player *player,
			      long long time, size_t *i)
{
  t_command	*cmd;
  bool		is_dead;

  is_dead = update_food(server, player, i, time);
  if (is_dead || player->cmds->length <= 0)
    return;
  cmd = player->cmds->items[0];
  if (!cmd->start)
    {
      cmd->end_time += time;
      cmd->start = true;
    }
  if (time >= cmd->end_time)
    {
      cmd->action ? cmd->action(server, cmd) : dprintf(player->id, "ko\n");
      if (cmd->delete)
	free_command(vector_remove_item(player->cmds, cmd));
    }
}

static void	graphic_update(t_server *server, t_graphic *graphic)
{
  t_command	*cmd;

  cmd = graphic->cmds->items[0];
  cmd->action ? cmd->action(server, cmd) : dprintf(graphic->id, "suc\n");
  free_command(vector_remove_item(graphic->cmds, cmd));
}

static void	eggs_update(t_server *server, long long time)
{
  t_egg		*egg;
  size_t	i;

  i = -1;
  while (++i < server->eggs->length)
    {
      egg = server->eggs->items[i];
      if (!egg->hatched && time > egg->end_time)
	{
	  egg->hatched = true;
	  multi_graphic_eht(server->graphic, egg);
	}
    }
}

void		server_update(t_server *server)
{
  size_t	i;
  long long	time;
  t_player	*player;
  t_graphic	*graphic;

  i = -1;
  time = current_time();
  while (++i < server->players->length)
    {
      player = server->players->items[i];
      player_update(server, player, time, &i);
    }
  i = -1;
  while (++i < server->graphic->length)
    {
      graphic = server->graphic->items[i];
      if (graphic->cmds->length > 0)
	graphic_update(server, graphic);
    }
  eggs_update(server, time);
}
