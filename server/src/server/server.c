/*
** server.c for server in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Jun 22 00:07:14 2017 David Zeng
** Last update Thu Jun 22 00:07:14 2017 David Zeng
*/

#include "cmd.h"
#include "server.h"
#include "player.h"
#include "graphic.h"
#include "egg.h"

t_server	init_server(t_param *param)
{
  t_server	server;

  server.network = init_network(param->port);
  server.world = create_world(param->dimension);
  server.max_client = param->nb_client;
  server.nb_team = tablen(param->teams);
  server.teams = param->teams;
  server.cmds = vector_new();
  server.running = true;
  server.frequency = param->frequency;
  server.players = vector_new();
  server.graphic = vector_new();
  server.eggs = vector_new();
  server.time = current_time();
  if (!server.cmds || !server.players || !server.graphic || !server.eggs)
    exit(84);
  return (server);
}

void		close_server(t_server *server)
{
  close_network(&server->network);
  vector_delete(server->cmds, NULL);
  vector_delete(server->players, free_player);
  vector_delete(server->graphic, free_graphic);
  vector_delete(server->eggs, free_egg);
  free_tab(server->teams);
  free_world(server->world);
}

void		handle_packages(t_server *server, t_vector *packages)
{
  size_t	i;

  i = -1;
  if (!packages)
    return;
  while (++i < packages->length)
    {
      handle_cmd(server, packages->items[i]);
    }
}
