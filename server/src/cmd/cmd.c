/*
** cmd.c for cmd in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Fri Jun 23 01:42:18 2017 David Zeng
** Last update Fri Jun 23 01:42:18 2017 David Zeng
*/

#include "player.h"
#include "graphic.h"
#include "cmd.h"

t_entity	get_entity(t_server *server, t_package *package)
{
  size_t	i;

  i = -1;
  while (++i < server->players->length)
    {
      if (package->fd == ((t_player *)server->players->items[i])->id)
	return (PLAYER);
    }
  i = -1;
  while (++i < server->graphic->length)
    {
      if (package->fd == ((t_graphic *)server->graphic->items[i])->id)
	return (GRAPHIC);
    }
  return (CLIENT);
}
