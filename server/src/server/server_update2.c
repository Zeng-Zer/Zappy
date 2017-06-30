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
	      return (true);
	    }
	}
    }
  return (false);
}
