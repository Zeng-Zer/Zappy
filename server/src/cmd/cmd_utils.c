/*
** cmd_utils.c for cmd_utils in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sun Jun 25 00:53:19 2017 David Zeng
** Last update Sun Jun 25 00:53:19 2017 David Zeng
*/

#include "cmd.h"

int		nb_player_team(t_vector *players, int team_id)
{
  size_t	i;
  int		nb;

  i = -1;
  nb = 0;
  while (++i < players->length)
    {
      if (((t_player *)players->items[i])->team_id == team_id)
	++nb;
    }
  return (nb);
}

t_player	*find_player(t_vector *players, int id)
{
  size_t	i;

  i = -1;
  while (++i < players->length)
    {
      if (((t_player*)players->items[i])->id == id)
	return (players->items[i]);
    }
  return (NULL);
}
