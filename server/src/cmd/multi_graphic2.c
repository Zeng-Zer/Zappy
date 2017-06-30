/*
** multi_graphic2.c for multi_graphic2 in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Fri Jun 30 01:45:35 2017 David Zeng
** Last update Fri Jun 30 01:45:35 2017 David Zeng
*/

#include "cmd.h"
#include "graphic.h"

void		multi_graphic_eject(t_vector *graphics, t_server *server,
				    t_player *player)
{
  t_graphic	*graphic;
  t_player	*ejected;
  size_t	i;
  size_t	j;

  i = -1;
  while (++i < graphics->length)
    {
      graphic = graphics->items[i];
      j = -1;
      graphic_pex(graphic->id, player);
      while (++j < server->players->length)
	{
	  ejected = server->players->items[j];
	  graphic_ppo(graphic->id, ejected);
	}
    }
}

void		multi_graphic_broadcast(t_vector *graphics, t_player *player,
					char *msg)
{
  t_graphic	*graphic;
  size_t	i;

  i = -1;
  while (++i < graphics->length)
    {
      graphic = graphics->items[i];
      graphic_pbc(graphic->id, player, msg);
    }
}

void		multi_graphic_pic(t_vector *graphics, t_player *player,
				  t_tile *tile)
{
  t_graphic	*graphic;
  size_t	i;

  i = -1;
  while (++i < graphics->length)
    {
      graphic = graphics->items[i];
      graphic_pic(graphic->id, player, tile);
    }
}

void		multi_graphic_pie(t_vector *graphics, t_pos pos,
				  bool elevation, t_server *server)
{
  t_graphic	*graphic;
  size_t	i;
  size_t	j;

  i = -1;
  while (++i < graphics->length)
    {
      graphic = graphics->items[i];
      graphic_pie(graphic->id, pos, elevation);
      j = -1;
      while (++j < server->players->length)
	graphic_plv(graphic->id, server->players->items[i]);
      graphic_mct(graphic->id, server->world);
    }
}
