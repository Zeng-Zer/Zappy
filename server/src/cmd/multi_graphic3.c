/*
** multi_graphic3.c for multi_graphic3 in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Fri Jun 30 02:24:54 2017 David Zeng
** Last update Fri Jun 30 02:24:54 2017 David Zeng
*/

#include "cmd.h"
#include "graphic.h"

void		multi_graphic_pfk(t_vector *graphics, t_player *player)
{
  t_graphic	*graphic;
  size_t	i;

  i = -1;
  while (++i < graphics->length)
    {
      graphic = graphics->items[i];
      graphic_pfk(graphic->id, player);
    }
}

void		multi_graphic_enw(t_vector *graphics, t_player *player,
				  t_egg *egg)
{
  t_graphic	*graphic;
  size_t	i;

  i = -1;
  while (++i < graphics->length)
    {
      graphic = graphics->items[i];
      graphic_enw(graphic->id, player->id, egg);
    }
}

void		multi_graphic_eht(t_vector *graphics, t_egg *egg)
{
  t_graphic	*graphic;
  size_t	i;

  i = -1;
  while (++i < graphics->length)
    {
      graphic = graphics->items[i];
      graphic_eht(graphic->id, egg);
    }
}

void		multi_graphic_pdi(t_vector *graphics, t_player *player)
{
  t_graphic	*graphic;
  size_t	i;

  i = -1;
  while (++i < graphics->length)
    {
      graphic = graphics->items[i];
      graphic_pdi(graphic->id, player);
    }
}

void		multi_graphic_seg(t_vector *graphics, char *team)
{
  t_graphic	*graphic;
  size_t	i;

  i = -1;
  while (++i < graphics->length)
    {
      graphic = graphics->items[i];
      graphic_seg(graphic->id, team);
    }
}
