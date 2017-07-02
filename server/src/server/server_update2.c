/*
** server_update2.c for server_update2 in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sat Jul  1 01:14:08 2017 David Zeng
** Last update Sat Jul  1 01:14:08 2017 David Zeng
*/

#include "server.h"
#include "elevation.h"
#include "player.h"
#include "graphic.h"

bool		check_win(t_server *server)
{
  int		teams_max_level_player[server->nb_team];
  size_t	i;
  t_player	*player;

  i = -1;
  while (++i < server->players->length)
    {
      player = server->players->items[i];
      if (player->level == MAX_LEVEL)
	{
	  ++teams_max_level_player[player->team_id];
	  if (teams_max_level_player[player->team_id] >= 6)
	    {
	      multi_graphic_seg(server->graphic,
				server->teams[player->team_id]);
	      printf("WINNER: %s\n", server->teams[player->team_id]);
	      return (true);
	    }
	}
    }
  return (false);
}

static void	multi_graphic_mct(t_vector *graphics, t_server *server)
{
  t_graphic	*graphic;
  size_t	i;

  i = -1;
  while (++i < graphics->length)
    {
      graphic = graphics->items[i];
      graphic_mct(graphic->id, server->world);
    }
}

void		add_food(t_server *server, long long time)
{
  t_pos		pos;

  if (time > server->time + END_TIME(2000.0f))
    {
      server->time = time;
      pos.y = -1;
      while (++pos.y < server->world->dimension.y)
	{
	  pos.x = -1;
	  while (++pos.x < server->world->dimension.x)
	    server->world->map[pos.y][pos.x].stones[FOOD] += 1;
	}
      multi_graphic_mct(server->graphic, server);
      printf("Add food\n");
    }
}
