/*
** server.c for server in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Jun 22 00:07:14 2017 David Zeng
** Last update Thu Jun 22 00:07:14 2017 David Zeng
*/

#include "server.h"

t_server	init_server(t_param *param)
{
  t_server	server;

  server.network = init_network(param->port);
  server.world = create_world(param->dimension);
  server.nb_team = tablen(param->teams);
  server.teams = param->teams;
  server.tasks = vector_new();
  server.running = true;
  return (server);
}

void		close_server(t_server *server)
{
  close_network(&server->network);
  vector_delete(server->tasks, NULL);
  free_tab(server->teams);
  free_world(server->world);
}
