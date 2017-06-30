/*
** multi_graphic.c for multi_graphic in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Fri Jun 30 01:17:33 2017 David Zeng
** Last update Fri Jun 30 01:17:33 2017 David Zeng
*/

#include "cmd.h"
#include "graphic.h"
#include "egg.h"

void		multi_graphic_pnw(t_vector *graphics, t_server *server,
				  t_player *player)
{
  t_graphic	*graphic;
  size_t	i;

  i = -1;
  while (++i < graphics->length)
    {
      graphic = graphics->items[i];
      graphic_pnw(graphic->id, server, player);
    }
}

void		multi_graphic_ebo(t_vector *graphics, t_egg *egg)
{
  t_graphic	*graphic;
  size_t	i;

  i = -1;
  while (++i < graphics->length)
    {
      graphic = graphics->items[i];
      graphic_ebo(graphic->id, egg);
    }
}

void		multi_graphic_ppo(t_vector *graphics, t_player *player)
{
  t_graphic	*graphic;
  size_t	i;

  i = -1;
  while (++i < graphics->length)
    {
      graphic = graphics->items[i];
      graphic_ppo(graphic->id, player);
    }
}

void		multi_graphic_take(t_vector *graphics, t_world *world,
				   t_player *player, t_stone res)
{
  t_graphic	*graphic;
  size_t	i;

  i = -1;
  while (++i < graphics->length)
    {
      graphic = graphics->items[i];
      graphic_pgt(graphic->id, player, res);
      graphic_pin(graphic->id, player);
      graphic_bct(graphic->id, world, player->pos);
    }
}

void		multi_graphic_set(t_vector *graphics, t_world *world,
				   t_player *player, t_stone res)
{
  t_graphic	*graphic;
  size_t	i;

  i = -1;
  while (++i < graphics->length)
    {
      graphic = graphics->items[i];
      graphic_pdr(graphic->id, player, res);
      graphic_pin(graphic->id, player);
      graphic_bct(graphic->id, world, player->pos);
    }
}
