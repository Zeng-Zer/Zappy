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
#include "egg.h"

void		cmd_graphic(t_server *server, t_package *package)
{
  t_graphic	*graphic;

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

static t_pos	get_pos_or_egg(t_server *server, int team_id)
{
  t_pos		pos;
  t_egg		*egg;
  size_t	i;

  i = -1;
  while (++i < server->eggs->length)
    {
      egg = server->eggs->items[i];
      if (egg->hatched && egg->team_id == team_id)
	{
	  pos = egg->pos;
	  free_egg(vector_remove(server->eggs, i));
	  return (pos);
	}
    }
  pos.x = rand() % server->world->dimension.x;
  pos.y = rand() % server->world->dimension.y;
  return (pos);
}

static t_player	*add_player(t_server *server, t_package *package)
{
  t_player	*player;
  int		team_id;
  t_pos		pos;
  char		*word;

  if (!(word = first_word(package->msg)) ||
      (team_id = get_team_id(server, word)) == -1)
    {
      free(word);
      dprintf(package->fd, "ko\n");
      return (NULL);
    }
  pos = get_pos_or_egg(server, team_id);
  if ((player = create_player(package->fd, team_id, pos)))
    {
      vector_push(server->world->map[pos.y][pos.x].players, player);
      vector_push(server->players, player);
      dprintf(package->fd, "%d\n%d %d\n",
	      server->max_client - nb_player_team(server->players, team_id),
	      server->world->dimension.x, server->world->dimension.y);
    }
  free(word);
  return (player);
}

void		cmd_player(t_server *server, t_package *package)
{
  t_player	*player;

  if (!(player = add_player(server, package)))
    return;
  // TODO ADD FOOD + GRAPHIC
}
