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

const t_cmd	g_player_cmd[] = {
  {"Forward", cmd_forward, 7.0f},
  {"Right", cmd_right, 7.0f},
  {"Left", cmd_left, 7.0f},
  {"Look", cmd_look, 7.0f},
  {"Inventory", cmd_inventory, 1.0f},
  {"Broadcast", cmd_broadcast, 7.0f},
  {"Connect_nbr", cmd_connect, 0.0f},
  {"Fork", cmd_fork, 42.0f},
  {"Eject", cmd_eject, 7.0f},
  {"Take", cmd_take, 7.0f},
  {"Set", cmd_set, 7.0f},
  {"Incantation", cmd_incant, 0.0f},
};

const t_cmd	g_graphic_cmd[] = {
  /* {"msz", cmd_msz}, */
  /* {"bct", cmd_bct}, */
  /* {"mct", cmd_mct}, */
  /* {"tna", cmd_tna}, */
  /* {"ppo", cmd_ppo}, */
  /* {"plv", cmd_plv}, */
  /* {"pin", cmd_pin}, */
  /* {"sgt", cmd_sgt}, */
  /* {"sst", cmd_sst}, */
};

/**
 * delete connection if package->close == true
 */
static t_entity	get_entity(t_server *server, t_package *package, void **item)
{
  size_t	i;

  i = -1;
  while (++i < server->players->length)
    if (package->fd == ((t_player *)server->players->items[i])->id)
      {
	*item = server->players->items[i];
	if (package->close)
	  free_player(vector_remove(server->players, i));
	return (PLAYER);
      }
  i = -1;
  while (++i < server->graphic->length)
    if (package->fd == ((t_graphic *)server->graphic->items[i])->id)
      {
	*item = server->graphic->items[i];
	if (package->close)
	  free_graphic(vector_remove(server->graphic, i));
	return (GRAPHIC);
      }
  return (CLIENT);
}

static void		handle_player(t_server *server, t_package *package,
				      t_player *player)
{
  size_t		i;
  static const size_t	size = sizeof(g_player_cmd) / sizeof(*g_player_cmd);
  t_command		*cmd;

  i = -1;
  while (++i < size)
    {
      if (match_first_word(package->msg, g_player_cmd[i].key))
	{
	  if ((cmd = create_command(g_player_cmd[i].cmd,
				    END_TIME(g_player_cmd[i].time),
				    player, package->msg)))
	    {
	      package->msg = NULL;
	      add_player_cmd(player, cmd);
	    }
	  return;
	}
    }
  if ((cmd = create_command(NULL, 0, player, NULL)))
    add_player_cmd(player, cmd);
}

static void		handle_graphic(t_server *server, t_package *package,
				       t_graphic *graphic)
{
  size_t		i;
  static const size_t	size = sizeof(g_graphic_cmd) / sizeof(*g_graphic_cmd);
  t_command		*cmd;

  i = -1;
  while (++i < size)
    {
      if (match_first_word(package->msg, g_graphic_cmd[i].key))
	{
	  if ((cmd = create_command(g_graphic_cmd[i].cmd,
				    END_TIME(g_graphic_cmd[i].time),
				    graphic, package->msg)))
	    {
	      package->msg = NULL;
	      add_graphic_cmd(graphic, cmd);
	    }
	  return;
	}
    }
  if ((cmd = create_command(NULL, 0, graphic, NULL)))
    add_graphic_cmd(graphic, cmd);
}

void		handle_cmd(t_server *server, t_package *package)
{
  t_entity	entity;
  void		*item;

  entity = get_entity(server, package, &item);
  if (package->close)
    return;
  if (entity == CLIENT)
    {
      if (match_first_word(package->msg, "GRAPHIC"))
	cmd_graphic(server, package);
      else
	cmd_player(server, package);
    }
  else if (entity == PLAYER)
    handle_player(server, package, item);
  else if (entity == GRAPHIC)
    handle_graphic(server, package, item);
}
