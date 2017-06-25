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
  /* {"Forward", cmd_forward}, */
  /* {"Right", cmd_right}, */
  /* {"Left", cmd_left}, */
  /* {"Look", cmd_look}, */
  /* {"Inventory", cmd_inventory}, */
  /* {"Broadcast", cmd_broadcast}, */
  /* {"Connect_nbr", cmd_connect}, */
  /* {"Fork", cmd_fork}, */
  /* {"Eject", cmd_eject}, */
  /* {"Take", cmd_take}, */
  /* {"Set", cmd_set}, */
  /* {"Incantation", cmd_incant}, */
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
static t_entity	get_entity(t_server *server, t_package *package)
{
  size_t	i;

  i = -1;
  while (++i < server->players->length)
    {
      if (package->fd == ((t_player *)server->players->items[i])->id)
	{
	  if (package->close)
	    free_player(vector_remove(server->players, i));
	  return (PLAYER);
	}
    }
  i = -1;
  while (++i < server->graphic->length)
    {
      if (package->fd == ((t_graphic *)server->graphic->items[i])->id)
	{
	  if (package->close)
	    free_graphic(vector_remove(server->graphic, i));
	  return (GRAPHIC);
	}
    }
  return (CLIENT);
}

static void		handle_player(t_server *server, t_package *package,
				      char **cmd)
{
  size_t		i;
  static const size_t	size = sizeof(g_player_cmd) / sizeof(*g_player_cmd);

  i = -1;
  while (++i < size)
    {
      if (strcmp(*cmd, g_player_cmd[i].key) == 0)
	return (g_player_cmd[i].cmd(server, package, cmd,
				    g_player_cmd[i].action));
    }
}

static void		handle_graphic(t_server *server, t_package *package,
				       char **cmd)
{
  size_t		i;
  static const size_t	size = sizeof(g_graphic_cmd) / sizeof(*g_graphic_cmd);

  i = -1;
  while (++i < size)
    {
      if (strcmp(*cmd, g_graphic_cmd[i].key) == 0)
	return (g_graphic_cmd[i].cmd(server, package, cmd,
				     g_graphic_cmd[i].action));
    }
}

void		handle_cmd(t_server *server, t_package *package)
{
  t_entity	entity;
  char		**cmd;

  entity = get_entity(server, package);
  if (package->close || !(cmd = split(package->msg, " ")) || !*cmd)
    return;
  if (entity == CLIENT)
    {
      if (strcmp(*cmd, "GRAPHIC") == 0)
	cmd_graphic(server, package, cmd);
      else
	cmd_player(server, package, cmd);
    }
  else if (entity == PLAYER)
    handle_player(server, package, cmd);
  else if (entity == GRAPHIC)
    handle_graphic(server, package, cmd);
  free_tab(cmd);
}
