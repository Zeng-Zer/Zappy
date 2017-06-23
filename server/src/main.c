/*
** main.c for main in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Jan 23 17:57:49 2017 David Zeng
** Last update Mon Jan 23 17:57:49 2017 David Zeng
*/

#include "server.h"

static bool	*g_running;

static void	signal_handler(int sig)
{
  if (sig == SIGINT)
    {
      *g_running = false;
    }
}

int		main(int argc, char *argv[])
{
  t_param	param;
  t_server	server;
  t_vector	*packages;

  param = parse_args(argc, argv);
  param_default(&param);
  param_dump(&param);
  server = init_server(&param);
  g_running = &server.running;
  signal(SIGINT, signal_handler);
  world_dump(1, server.world);
  while (server.running)
    {
      if ((packages = poll_event(&server.network)))
	handle_packages(&server, packages);
      update_server(&server);
    }
  close_server(&server);
  return (0);
}
