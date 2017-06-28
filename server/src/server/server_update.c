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

static void	player_update(t_server *server, t_player *player,
			      long long time)
{
  t_command	*cmd;

  cmd = player->cmds->items[0];
  // TODO CHECK FOOD
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
  cmd->action ? cmd->action(server, cmd) : dprintf(graphic->id, "ko\n");
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
	  // TODO GRAPHIC
	  egg->hatched = true;
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
      if (player->cmds->length > 0)
	player_update(server, player, time);
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
