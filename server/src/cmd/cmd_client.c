/*
** cmd_client.c for cmd_client in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sat Jun 24 17:14:32 2017 David Zeng
** Last update Sat Jun 24 17:14:32 2017 David Zeng
*/

#include "cmd.h"
#include "graphic.h"

void		cmd_graphic(t_server *server, t_package *package, char **cmd)
{
  t_graphic	*graphic;

  (void)cmd;
  if ((graphic = new_graphic(package->fd)))
    {
      vector_push(server->graphic, graphic);
      // TODO send map
    }
  else
    {
      dprintf(package->fd, "ko\n");
    }
}

static int	get_team_id(t_server *server, char *str)
{
  int		i;

  i = -1;
  while (server->teams[++i] != NULL)
    {
      if (strcmp(server->teams[i], str) == 0 &&
	  server->max_client - nb_player_team(server->players, i) > 0)
	return (i);
    }
  return (-1);
}

void		cmd_player(t_server *server, t_package *package, char **cmd)
{
  t_player	*player;
  int		team_id;
  t_pos		pos;

  pos.x = rand() % server->world->dimension.x;
  pos.y = rand() % server->world->dimension.y;
  if ((team_id = get_team_id(server, *cmd)) == -1 ||
      !(player = create_player(package->fd, team_id, pos)))
    return ((void)dprintf(package->fd, "ko\n"));
  vector_push(server->players, player);
  dprintf(package->fd, "%d\n%d %d\n",
	  server->max_client - nb_player_team(server->players, team_id),
	  server->world->dimension.x,
	  server->world->dimension.y);
}
